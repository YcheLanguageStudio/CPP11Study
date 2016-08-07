//
// Created by cheyulin on 8/7/16.
//
#include <boost/smart_ptr.hpp>

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

int main() {
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

