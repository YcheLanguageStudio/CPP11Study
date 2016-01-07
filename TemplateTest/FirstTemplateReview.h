//
// Created by cheyulin on 1/7/16.
//

#ifndef CPP11FEATURESSTUDY_FIRSTTEMPLATEREVIEW_H
#define CPP11FEATURESSTUDY_FIRSTTEMPLATEREVIEW_H
#endif //CPP11FEATURESSTUDY_FIRSTTEMPLATEREVIEW_H

#include <iostream>

namespace yche{

    //First: Template Class
    template<typename T>
    class ClassA {
    private:
        T member_;
    public:
        //Universal Reference
        ClassA(T&& member);
        void PrintMember();
    };

    //Second: Template Function
    template<typename T> T Add(T a,T b);
    template<typename T,typename R> T GetValue(R param);
}
