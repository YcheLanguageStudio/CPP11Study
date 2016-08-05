//
// Created by cheyulin on 8/5/16.
//
#include <boost/thread/shared_mutex.hpp>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include <functional>

using namespace std;
using namespace boost;

class rw_data {
private:
    int m_x;
    shared_mutex rw_mu;
public:
    rw_data() : m_x(0) {}

    void write() {
        unique_lock<shared_mutex> g(rw_mu);
        ++m_x;
    }

    void read(int *x) {
        shared_lock<shared_mutex> g(rw_mu);
        *x = m_x;
    }

    int get_m_x() {
        return m_x;
    }
};

void writer(rw_data &d) {
    for (auto i = 0; i < 20; ++i) {
        this_thread::sleep_for(boost::chrono::milliseconds(3));
        d.write();
    }
}

void reader(rw_data &d) {
    int x;
    for (auto i = 0; i < 10; ++i) {
        this_thread::sleep_for(boost::chrono::milliseconds(5));
        d.read(&x);
        cout << "reader:" << x << endl;
    }

}

int main() {
    rw_data d;
    thread_group pool;

    pool.create_thread(std::bind(writer, std::ref(d)));
    pool.create_thread(std::bind(writer, std::ref(d)));

    pool.create_thread(std::bind(reader, std::ref(d)));
    pool.create_thread(std::bind(reader, std::ref(d)));
    pool.create_thread(std::bind(reader, std::ref(d)));
    pool.create_thread(std::bind(reader, std::ref(d)));

    pool.join_all();

    cout << "final:" << d.get_m_x() << endl;

}