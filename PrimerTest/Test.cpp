//
// Created by cheyulin on 12/24/15.
//
#include <memory>
#include <array>
#include <set>
#include <bits/unique_ptr.h>
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

    std::array<int,2> test;
    test[0]=1;
    test[1]=2;
    for(auto i=0;i<test.size();i++)
        std::cout << test[i] <<std::endl;


    using namespace std;
    set<int> first_set;
    set<int> second_set;
    first_set.insert(1);
    first_set.insert(3);
    second_set.insert(2);
    second_set.insert(4);
    vector<int> third_set(4);

    set_union(first_set.begin(), first_set.end(), second_set.begin(), second_set.end(), third_set.begin());
    for(auto it = third_set.begin();it!=third_set.end();it++){
        cout << "hello:"<<*it << endl;
    }

//    int first[] = {5,10,15,20,25};
//    int second[] = {50,40,30,20,10};
//    std::vector<int> v(10);                      // 0  0  0  0  0  0  0  0  0  0
//    std::vector<int>::iterator it;
//
//    std::sort (first,first+5);     //  5 10 15 20 25
//    std::sort (second,second+5);   // 10 20 30 40 50
//
//    it=std::set_union (first, first+5, second, second+5, v.begin());
//    // 5 10 15 20 25 30 40 50  0  0
//    v.resize(it-v.begin());                      // 5 10 15 20 25 30 40 50
//
//    std::cout << "The union has " << (v.size_()) << " elements:\n";
//    for (it=v.begin(); it!=v.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';






}