##Function
- class abstract   
```cpp
template <typename R, typename... ArgTypes>
class function<R (ArgTypes...)>
{
public:
  function() noexcepts;
  template <typename F>
  function(F);

  void swap(function&) noexcept;      //swap function

  template <typename F, typename A>
  void assign(F&&, const A&);           //assign value

  explicit operator bool() const noexcept; //explict conversion to bool function

  R operator()(ArgTypes...) const;    //operator()

  const std::typeinfo& target_type() const noexcept;
  template <typename T>
  T* target() noexcept;
}
```
- std::function vs boost::function
  - std::function does not have clear() and empty()
  - provides assign()
  - provides explicit operator bool(), static_cast<bool>(f) or !!f, i.e, explicit bool conversion

##Bind
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

##Ref
###Reson for use
- C++/Boost adopts function object as predicate, which are often pass-value-syntax, 
algorithm or function has to keep function object copy to use, e.g,    
```cpp
int main(){
    struct square
    {
        typedef void result_type;
        void operator()(int& x)
        {
            x = x * x;
        }
    };
    
    vector<int> v = {1,2,3,4,5};
    for_each(v.begin(), v.end(), square());
}
```

###boost.ref
- boost.ref apply proxy design pattern
- class abstract is as follows,     
```cpp
tempalte<class T>
class reference_wrapper
{
public:
    //has to intilize the object in constructing phase, just as the usage of reference variable
    explicit reference_wrapper(T& t):t_(&t){}
    
    operator T&() const { return *t_};
    
    T& get() const {return *t_};
    T* get_pointer() const {return t_};
    
private:
    T* t_;
}
```    
- factory function    
```cpp
reference_wrapper<T> ref(T& t);
reference_wrapper<T const> cref(T const& t);
```    
- meta-function, providing
```cpp
is_reference_wrapper<T>::value      // judge whether T is a reference_wrapper
unwrap_reference<T>::type           // judge whether T has been wrapped by reference_wrapper
```