//
// Created by cheyulin on 12/24/15.
//

#include "Test.h"
size_t count_calls(){
    static size_t ctr =1 ;
    return ++ctr;
}

std::string::size_type find_char(const std::string & s, char c, std::string::size_type & occurs){
    auto ret = s.size();
    occurs =0;
    for(decltype(ret) i =0 ;  i!= s.size(); ++i){
        if(s[i] == c){
            if(ret == s.size()){
                ret = i;
            }
            ++occurs;
        }
    }
    return  ret;
}

void print(const int ia[], size_t size){
    for(auto i =0; i!=size;  ++i){
        std::cout<< ia[i] << std::endl;
    }
}

void print(int(&array)[5]){
    for(auto elem : array){
        std::cout << elem << std::endl;
    }
}

void error_msg(std::initializer_list<std::string> il){
    for(auto beg = il.begin(); beg != il.end(); ++beg){
        std::cout << *beg << " ";

    }
    std::cout << std::endl;
}

//Never Return a Reference or Pointer to a Local Object

int test_reference(int& reference){
    reference = 2222;
}

int main(){
    for(size_t i =0 ; i !=10; ++i){
        std::cout << count_calls() << std::endl;
    }
    std::cout << "Hello!" << std::endl;
    std::string::size_type occurs;
    std::cout << find_char("aoboc",'o', occurs) << std::endl;
    std::cout << occurs << std::endl;
    int ia[5]={1,2,3,4,5};
    print(ia, 3);
    int arr[5] = {5,4,3,2,1};
    print(arr);
    error_msg({"a","bv","d"});

    int a = 3333;
    test_reference(a);
    std::cout << a << std::endl;
}