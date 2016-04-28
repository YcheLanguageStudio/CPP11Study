//
// Created by cheyulin on 4/16/16.
//

#include <memory>
#include <set>
#include <iostream>

using namespace std;

//If unique_ptr<int> implement move assignment constructor
//Call callfunction(std::move(xxx))
//Will call the move assignment constructor
int callfunction(unique_ptr<int> int_ptr) {
    cout << "In Function:" << *int_ptr << endl;
    return -1;
}

//If set<int> implement move assignment constructor
//Call callfunction2(std::move(xxx))
//Will call the move assignment constructor
void callfunction2(set<int> set_r_val) {
    for (auto integer:set_r_val) {
        cout << integer << ",";
    }
    cout << endl;
}

class TestClass {

public:
    int hello;

    TestClass(int hello) : hello(hello) {
        cout << "Default Constructor" << endl;
    }

    TestClass(const TestClass &test_class) {
        this->hello = test_class.hello;
        cout << "Copy Constructor" << endl;
    }

    TestClass(TestClass &&test_class) {
        this->hello = test_class.hello;

        cout << "Move Constructor" << endl;
    }

    TestClass operator=(const TestClass &test_class) {
        cout << "Copy Assignment" << endl;
    }

    TestClass operator=(TestClass &&test_class) {
        cout << "Move Assignment" << endl;
    }
};

void CallFunctionWithTest(TestClass tmp_test_class) {

}

TestClass RetRVal() {
    TestClass tmp_test_class(4);
    return std::move(tmp_test_class);
}

TestClass RetLVal() {
    TestClass tmp_test_class(5);
    return tmp_test_class;
}

void AcceptRVal(unique_ptr<int> &&hello_ptr) {
    *hello_ptr = 3;
}

void SimpleTest() {
    set<int> first_set;
    first_set.insert(1);
    first_set.insert(2);
    //use The Rvalue Assignment Constructor
    auto second_set = std::move(first_set);
    cout << second_set.size() << endl;
    cout << first_set.size() << endl;

    auto int_ptr = make_unique<int>(1);
    cout << "!!" << (int_ptr == nullptr) << endl;

    callfunction(std::move(int_ptr));
    cout << "!!" << (int_ptr == nullptr) << endl;

    callfunction2(std::move(second_set));
    cout << second_set.size() << endl;

    cout << endl << endl;
    TestClass my_class_first(1);
    //Call Constructor
    auto my_class_second = std::move(my_class_first);
    //Call Constructor
    auto my_class_third = my_class_second;
    //Call Assignment
    my_class_first = my_class_third;
    //Call Assignment
    my_class_first = std::move(my_class_third);

    cout << endl;
    //Call Constructor
    CallFunctionWithTest(my_class_first);
    CallFunctionWithTest(std::move(my_class_first));

    cout << endl << "Ret Val Test:" << endl;
    //Ret Val Test
    auto my_fourth_class = RetRVal();
    cout << my_fourth_class.hello << endl;
    auto my_fifth_class = RetLVal();

    //compiler optimization???
    cout << my_fifth_class.hello << endl;


    cout << "hello" << endl;
    //Only reference Without Any Assignment or Constructor

    auto &&r_reference_class = std::move(my_fourth_class);
    auto &l_reference_class = my_fourth_class;

    cout << endl << endl;
    unique_ptr<int> first_int_ptr = make_unique<int>(1);
    auto &&r_ref_first_int_ptr = std::move(first_int_ptr);
    unique_ptr<int> second_int_ptr = make_unique<int>(2);
    r_ref_first_int_ptr = std::move(second_int_ptr);
    cout << *first_int_ptr << endl;


    cout << endl << endl;
    unique_ptr<int> third_int_ptr = make_unique<int>(111);
    auto &&r_ref = std::move(third_int_ptr);
    AcceptRVal(std::move(r_ref));
    cout << "third int:" << *third_int_ptr << endl;

}

void Call_Me(unique_ptr<int> &&hello) {
    cout << *hello << "!!!" << endl;
}

int main() {
    SimpleTest();
    unique_ptr<int> int_ptr_one = make_unique<int>(1);
    auto &&r_ref = std::move(int_ptr_one);
    cout << *r_ref << endl;
    cout << *int_ptr_one << endl;

    Call_Me(std::move(int_ptr_one));
    cout << *r_ref << endl;
    cout << *int_ptr_one << endl;


    getchar();


}