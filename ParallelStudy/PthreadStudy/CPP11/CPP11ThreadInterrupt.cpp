//
// Created by cheyulin on 8/5/16.
//

#include <boost/thread/thread.hpp>

using namespace boost;
using namespace std;

void to_interrupt(int x) {
    try {
        for (auto i = 0; i < x; i++) {
            cout << i << endl;
            if (i % 2 == 1)
                this_thread::interruption_point();
        }
    } catch (thread_interrupted &) {
        cout << "Thread Interrupted" << endl;
    }
};

int main() {
    boost::thread my_thread(boost::bind(to_interrupt, 10));
    my_thread.interrupt();  //Immediately Interrupt
    my_thread.join();
}