//
// Created by cheyulin on 4/10/16.
//
#include<memory>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class TestClass{
public:
    unique_ptr<int> test_uptr_;

    TestClass(unique_ptr<int> &test_uptr)  {
        test_uptr_ = std::move(test_uptr);
        cout << "test_uptr"<<*test_uptr_ << endl;
    }
};

unique_ptr<int> test_unique_ptr_input(unique_ptr<int> in_ptr){
    *in_ptr =4;
    return move(in_ptr);
}

int main(){
//    unique_ptr<int> u_ptr4;
//    unique_ptr<int> u_ptr2(new int(2));
//    cout << *u_ptr2 << endl;
//    *u_ptr2 = 1;
//    cout << *u_ptr2 << endl ;
//
//    unique_ptr<int> u_ptr1 = std::move(u_ptr2);
//    cout << *u_ptr1 << endl ;
//
//    unique_ptr<int> u_ptr3 = std::move(u_ptr1);
//    cout << *u_ptr3 << endl ;
//
//    TestClass myclass(u_ptr3);
//    u_ptr4 = std::move(myclass.test_uptr_);
//    cout << "u_ptr4:" << *u_ptr4;

//    vector<int>* v_p = new vector<int>();
//    unique_ptr<vector<int>> my_set_ptr(v_p);
    //Make Unique Specify Template Type
    unique_ptr<vector<int>> my_set_ptr = make_unique<vector<int>>();
    my_set_ptr->push_back(1);
    for(auto iter=my_set_ptr->begin();iter!=my_set_ptr->end();++iter){
        cout << "iter:" << *iter << endl;
    }

    cout <<endl<<endl;
    unique_ptr<int> former_ptr=make_unique<int>(3);
    former_ptr = test_unique_ptr_input(std::move(former_ptr));
    cout << ">>:"<<*former_ptr<<endl;
}





