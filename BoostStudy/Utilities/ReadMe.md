##Utilities
###noncopyable
- Impl:
    - C++98
    ```cpp
    class noncopyable{
    protected:
        noncopyable(){}   
        ~noncopyable(){}   
    private:
        noncopyable(const noncopyable&);
        const noncopyable& opeartor=(cosnt noncopyable&);
    };
    ```   

    - C++11   
    ```cpp
    class noncopyable
    {
     protected:
         noncopyable() = default;
         ~noncopyable() = default;
     private:
         noncopyable(const noncopyable&) = delete;
         const noncopyable& opeartor=(cosnt noncopyable&) = delete;
    };

    ```

###ignore_unused
- Impl, making use of varadic template, just mimicly use the variables, more clear than (void)var
```cpp
template <typename... Ts>
inline void ignore_unused(Ts const& ...){}

template <typename... Ts>
inline void ignore_unused(){}
```
