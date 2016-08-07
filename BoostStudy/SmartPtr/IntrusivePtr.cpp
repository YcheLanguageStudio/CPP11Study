//
// Created by cheyulin on 8/7/16.
//
#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

using namespace boost;

struct counted_data {
    int m_count = 0;
private:
    friend void intrusive_ptr_add_ref(counted_data *p) {
        ++p->m_count;
    }

    friend void intrusive_ptr_release(counted_data *p) {
        if (--p->m_count == 0) {
            delete p;
        }
    }
};

//crtp: curiously recurring template pattern: static-polymorphism
struct counted_data2 : public intrusive_ref_counter<counted_data2, thread_unsafe_counter> {

};

void basic_demo() {
    using counted_ptr=intrusive_ptr<counted_data>;

    counted_ptr p(new counted_data);
    assert(p);     //explicit bool conversion
    assert(p->m_count == 1);

    counted_ptr p2(p);
    assert(p->m_count == 2);

    counted_ptr weak_p(p.get(), false);
    assert(weak_p->m_count == 2);

    p2.reset();
    assert(!p2);
    assert(p->m_count == 1);
}

void advance_demo() {
    using counted_ptr = intrusive_ptr<counted_data2>;

    counted_ptr p(new counted_data2);
    assert(p);
    assert(p->use_count() == 1);
}

int main() {
    basic_demo();
    advance_demo();
}

