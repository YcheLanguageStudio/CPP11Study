//
// Created by cheyulin on 5/10/16.
//

#include "TemplateClassTest.h"

int main(){
    using namespace yche;
    TemplateClassTest<yche::tag1> tag1_class;
    TemplateClassTest<yche::tag2> tag2_class;
    tag1_class.CallPrint();
    tag2_class.CallPrint();
    getchar();
}