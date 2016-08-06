//
// Created by cheyulin on 8/6/16.
//
#include <boost/thread.hpp>
#include <boost/utility.hpp>

using namespace boost;

void cas_demo() {
    atomic<long> l(100);

    long v = 100;
    if (l.compare_exchange_weak(v, 313)) {
        assert(l == 313 && v == 100);
    }

    v = 200;
    auto b = l.compare_exchange_strong(v, 99);
    assert(!b && v == 313);

    l.compare_exchange_weak(v, 99);
    assert(l == 99 && v == 313);
}

void atomic_integer_demo() {
    atomic_int n(100);
    assert(n.fetch_add(10) == 100);  //add operation, return original value
    assert(n == 110);

    assert(++n == 111);
    assert(n++ == 111);
    assert(n == 112);

    assert((n -= 10) == 102);  // equals to fetch_sub

    atomic_int b{BOOST_BINARY(1101)};

    auto x = b.fetch_add(BOOST_BINARY(0110));
    assert(x == BOOST_BINARY(1101) && b == BOOST_BINARY(10011));
    assert((b | BOOST_BINARY(1001)) == BOOST_BINARY(11011));
}


void atomic_bool_demo() {
    atomic<bool> b(true);
    assert(b);

    b = false;
    assert(!b.load());

    auto x = b.exchange(true);
    assert(b && !x);
}

int main() {
    cas_demo();
    atomic_integer_demo();
    atomic_bool_demo();
}