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