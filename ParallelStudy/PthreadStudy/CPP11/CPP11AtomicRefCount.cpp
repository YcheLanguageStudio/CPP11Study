//
// Created by cheyulin on 8/6/16.
//
#include <boost/intrusive_ptr.hpp>
#include <boost/atomic.hpp>
#include <iostream>

using namespace boost;

template<typename T>
class ref_count {
private:
    using atomic_type=atomic_int;
    //mutable is used for breaking const
    mutable atomic_type m_count{0};

protected:
    ref_count() {};

    ~ref_count() {};

public:
    using counted_ptr= boost::intrusive_ptr<T>;

    void add_ref() const {
        m_count.fetch_add(1, boost::memory_order_relaxed);  //not require any memory access gurantee
    };

    void sub_ref() const {
        if (m_count.fetch_sub(1, boost::memory_order_relaxed) == 1) {
            boost::atomic_thread_fence(boost::memory_order_acquire);    //atomic thread fence, acquire previous update
            delete static_cast<const T *> (this);                       //delete pointer
        }
    }

    decltype(m_count.load()) count() const {
        return m_count.load();
    }

public:
    template<typename ...Args>
    static counted_ptr make_ptr(Args &&...args) {   //factory function
        return counted_ptr(new T(std::forward<Args>(args)...));
    }

private:
    friend void intrusive_ptr_add_ref(const T *p) {  //implenting traits/concepts specified in intrusive_ptr
        p->add_ref();
    }

    friend void intrusive_ptr_release(const T *p) {  //implenting traits/concepts specified in intrusive_ptr
        p->sub_ref();
    }
};


//CRTP: Curiously Recurring Template Pattern
class demo : public ref_count<demo> {
public:
    demo() = default;

    ~demo() = default;

    int x;
};

int main() {
    auto p = demo::make_ptr();
    p->x = 10;
    assert(p->x == 10);
    assert(p->count() == 1);
    auto shared_p = p;  //pointer copy constructor, shared reference
    assert(p->count() == 2);

    auto weak_p = boost::intrusive_ptr<demo>(p.get(), false); //weak reference
    assert(p->count() == 2);

}