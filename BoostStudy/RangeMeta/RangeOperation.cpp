//
// Created by cheyulin on 8/2/16.
//

#include "boost/type_traits.hpp"
#include <boost/range.hpp>
#include <vector>
#include <iostream>
#include "assert.h"

using namespace boost;
using namespace std;

void BasicRangeTest() {
    boost::range_value<vector<int>>::type hello_integer;
    hello_integer = 3;
    cout << "hello_integer:" << hello_integer << endl;
    boost::range_reference<vector<int>>::type hello_integer_ref = hello_integer;
    hello_integer++;
    cout << "hello_integer_ref:" << hello_integer_ref << endl;
}

template<typename ContainerType>
class TestRange {
public:
    ContainerType *container_ptr_;
    using ElementType = typename boost::range_value<ContainerType>::type;
    ElementType element_value_;

    TestRange(ContainerType *container_ptr) : container_ptr_(container_ptr) {
        element_value_ = *(container_ptr->end()-1);
    }
};

int main() {
    BasicRangeTest();
    vector<int> my_vector{111, 222, 333};
    TestRange<vector<int>> test_range_obj(&my_vector);
    cout << test_range_obj.element_value_<<endl;
}