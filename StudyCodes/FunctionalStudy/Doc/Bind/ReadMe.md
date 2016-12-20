##Bind
###CPP11
- C++11 standard make use of varadic template parameter template and forward to simplify the definition of bind,
support any number of parameters
```cpp
template <typename R, typename F, typename... BoundArgs>
unspecified bind(F&&, BoundArgs&&...);  //bind function

namespace std::placeholders{
  extern unspecified _1;
  extern unspecified _2;
}

//usage
cout << std::bind(f, std::placeholders::_1, 20)(10)  //10 is the binded parameter, _1 is the placeholder
}

//similar to lambda expression
auto lf = [](int x){     //binded parameter
  return f(x,9);  // x just like the placeholder
};

assert(lf(10) == bind(f, _1, 9)(10));
```
