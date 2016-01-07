//
// Created by cheyulin on 1/7/16.
//

#ifndef CPP11FEATURESSTUDY_LAMBDA_H_H
#define CPP11FEATURESSTUDY_LAMBDA_H_H
#define __thiscall
#endif //CPP11FEATURESSTUDY_LAMBDA_H_H

#include <functional>
#include <iostream>

namespace yche {
    //Refer to vczh github.com/vczh/vczh_toys/CppRecursiveLambda/

    template<typename TResult, typename  ...TArgs>
    class YBuilder {
    private:
        std::function<TResult(std::function<TResult(TArgs...)>, TArgs...)> partialLambda_;

    public:
        YBuilder(std::function<TResult(std::function<TResult(TArgs...)>, TArgs...)> partialLambda) :
                partialLambda_(partialLambda) {
        }

        TResult operator()(TArgs...args) const {
            return partialLambda_(
                    [this](TArgs...args) {
                        return this->operator()(args...);
                    },
                    args...);
        }
    };

    template<typename TMethod>
    struct PartialLambdaTypeRetriver {
        typedef void FunctionType;
        typedef void LambdaType;
        typedef void YBuilderType;
    };

    template<typename TClass, typename TResult, typename ...TArgs>
    struct PartialLambdaTypeRetriver<TResult(__thiscall TClass::*)(std::function<TResult(TArgs...)>, TArgs...)> {
        typedef TResult FunctionType(TArgs ...);
        typedef TResult LambdaType(std::function<TResult(TArgs...)>, TArgs...);
        typedef YBuilder<TResult, TArgs...> YBuilderType;
    };

    template<typename TClass, typename TResult, typename ...TArgs>
    struct PartialLambdaTypeRetriver<TResult(__thiscall TClass::*)(std::function<TResult(TArgs...)>, TArgs...) const> {
        typedef TResult FunctionType(TArgs ...);
        typedef TResult LambdaType(std::function<TResult(TArgs...)>, TArgs...);
        typedef YBuilder<TResult, TArgs...> YBuilderType;
    };

    template<typename TLambda>
    std::function<typename PartialLambdaTypeRetriver<decltype(&TLambda::operator())>::FunctionType> Y(TLambda partialLambda) {
        return  typename PartialLambdaTypeRetriver<decltype(&TLambda::operator())>::YBuilderType(partialLambda);
    }
}