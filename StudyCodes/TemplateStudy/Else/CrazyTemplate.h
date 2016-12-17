//
// Created by cheyulin on 4/25/16.
//

#ifndef CPP11FEATURESSTUDY_CRAZYTEMPLATE_H
#define CPP11FEATURESSTUDY_CRAZYTEMPLATE_H

#include <iostream>

namespace yche {
    template<typename D>
    class CrazyTemplate {
    public:
        D d;

        void SayHi();
    };


    using namespace std;
    template<typename D>
    void CrazyTemplate<D>::SayHi() {
        cout << d;
    }
}


#endif //CPP11FEATURESSTUDY_CRAZYTEMPLATE_H
