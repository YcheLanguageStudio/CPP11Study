##Function
###C++11
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
