//
// Created by cheyulin on 1/7/16.
//

#include "FirstTemplateReview.h"

//First: Template Class
template<typename T>
void yche::ClassA<T>::PrintMember() {
    std::cout << "Member:" << member_ << std::endl;
}

template<typename T>
yche::ClassA<T>::ClassA(T &&member) {
    member_ = member;
}

void TestTemplateClass() {
    yche::ClassA<int> class_int(123);
    yche::ClassA<std::string> class_string(std::string("123"));
    class_int.PrintMember();
    class_string.PrintMember();
}

//Second: Template Function
template<typename T>
T yche::Add(T a, T b) {
    return a + b;
}

void TestTemplateFunctionAdd() {
    //Normal
    std::cout << yche::Add<int>(1, 2) << std::endl;
    //Type Deduction
    int left_int = 1;
    int right_int = 2;
    std::cout << yche::Add(left_int, right_int) << std::endl;
    /* Type Deduction Failure
        char left = 1;
        int right = 2;
        yche::Add(left,right);
    */
}

template<typename T, typename R>
T yche::GetValue(R param) {
    return static_cast<T>(param);
}

void TestTemplateFuctionGetValue() {
    int i = 1;
    //Must specify float, Since compiler could not deduce from the return type
    float a = yche::GetValue<float>(i);
}


int main() {
    TestTemplateClass();
    TestTemplateFunctionAdd();
    TestTemplateFuctionGetValue();
}


