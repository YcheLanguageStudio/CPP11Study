//
// Created by cheyulin on 7/28/16.
//
#include <iostream>
using namespace std;
template<typename IndexType>
class MyTemplate {
    IndexType integer_;

public:
    inline void ChangeMyInteger(const IndexType &change_value) {
        integer_ = change_value;
    }

    inline void GetInTeger(){
        cout << integer_<<endl;
    }
};

int main(){
    MyTemplate<int> template_o;
    template_o.ChangeMyInteger(3);
    template_o.GetInTeger();
}