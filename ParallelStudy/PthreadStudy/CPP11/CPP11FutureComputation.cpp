//
// Created by cheyulin on 8/5/16.
//
#include <boost/thread/future.hpp>
#include <boost/chrono.hpp>

using namespace boost;
using namespace std;

int fab(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fab(n - 1) + fab(n - 2);
}

void simple_demo() {
    auto f5 = async(std::bind(fab, 5));
    auto f7 = async(launch::async, std::bind(fab, 7));
    cout << f5.get() + f7.get() << endl;
//    assert(!f5.valid() && !f7.valid()); why is that still valid

    auto f10 = async(std::bind(fab, 10));
    auto s = f10.wait_for(boost::chrono::milliseconds(100));

    if (f10.valid()) {
        assert(s == future_status::ready);
        cout << f10.get() << endl;
    }
}

void multiple_future_objects_demo() {
    vector<unique_future<int>> vec;
    for (auto i = 0; i < 5; ++i) {
        vec.push_back(async(bind(fab, i + 10)));
    }
    wait_for_all(vec.begin(), vec.end());
    for (auto &x :vec) {
        cout << x.get() << ",";
    }
}

//void shared_future_demo() {
//    auto f5 = async(bind(fab, 5)).share();
//
//    auto func = [](decltype(f5) f){
//        cout << "[" << f.get() << "]";
//    };
//    async(func,f5);
//    async(func,f5);
//
//    this_thread::sleep_for(boost::chrono::milliseconds(100));
//    assert(f5.valid());
//}

int main() {
    simple_demo();
    cout << endl << endl;
    multiple_future_objects_demo();
    cout << endl << endl;
//    shared_future_demo();
}
