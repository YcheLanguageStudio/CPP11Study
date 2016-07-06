//
// Created by cheyulin on 7/6/16.
//
#include <iostream>

class testClass{
public:
    static int data;
};

//Need to Specify int to make it allocate correctly
int testClass::data=1;

template <typename T>
class testAnother{
public:
    static int data;
};

template<>  //Speicalization Member reuqires tempalte <> syntax for gcc5.x
int testAnother<char>::data=2;

int main(){
    using namespace std;
    cout << testClass::data<<endl;
    cout << testAnother<char>::data <<endl;
}