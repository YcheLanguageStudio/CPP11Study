//
// Created by cheyulin on 8/11/16.
//

#include <boost/noncopyable.hpp>

class do_not_copy : boost::noncopyable {

};

int main() {
    do_not_copy d1;
    // error: do_not_copy d2(d1);
    do_not_copy d3;
    // error: d3 = d1;
}
