//
// Created by cheyulin on 4/10/16.
//
#include<memory>
#include <iostream>

using namespace std;
class TestClass{
public:
    unique_ptr<int> test_uptr_;

    TestClass(unique_ptr<int> &test_uptr)  {
        test_uptr_ = std::move(test_uptr);
        cout << "test_uptr"<<*test_uptr_ << endl;
    }
};
int main(){
    unique_ptr<int> u_ptr4;
    unique_ptr<int> u_ptr2(new int(2));
    cout << *u_ptr2 << endl;
    *u_ptr2 = 1;
    cout << *u_ptr2 << endl ;

    unique_ptr<int> u_ptr1 = std::move(u_ptr2);
    cout << *u_ptr1 << endl ;

    unique_ptr<int> u_ptr3 = std::move(u_ptr1);
    cout << *u_ptr3 << endl ;

    TestClass myclass(u_ptr3);
    u_ptr4 = std::move(myclass.test_uptr_);
    cout << "u_ptr4:" << *u_ptr4;
}




