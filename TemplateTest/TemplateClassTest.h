//
// Created by cheyulin on 5/10/16.
//

#ifndef CPP11FEATURESSTUDY_TEMPLATECLASSTEST_H
#define CPP11FEATURESSTUDY_TEMPLATECLASSTEST_H

#include <iostream>

namespace yche {
    struct tag1;
    struct tag2;

    using namespace std;

    template<typename tag>
    class TemplateClassTest {
        void PrintAccordingToTag();

    public:
        void CallPrint();
    };

    template<>
    void TemplateClassTest<tag1>::PrintAccordingToTag() {
        cout << "tag1 print" << endl;
    }

    template<>
    void TemplateClassTest<tag2>::PrintAccordingToTag() {
        cout << "tag2 print" << endl;
    }


    template<typename tag>
    void TemplateClassTest<tag>::CallPrint() {
        PrintAccordingToTag();
    }


}


#endif //CPP11FEATURESSTUDY_TEMPLATECLASSTEST_H
