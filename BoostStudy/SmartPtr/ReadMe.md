##Smart-Ptrs
###Intrusive Ptr
- intrusive_ptr is a reference counting smart pointer, which is different from scope_ptr and shared_ptr, users
 have to add some extra codes to user it.
- actually it does not require us to modify proxy object's interior states
- class abstract is as follows:   
```cpp
template <typename T>
class intrusive_ptr｛
public:
  typedef T element_type;   //the proxyed object

  intrusive_ptr();
  intrusive_ptr(T* p, bool add_ref = true);

  intrusive_ptr(intrusive_ptr const & r);
  template <typename Y>
  intrusive_ptr(intrusive_ptr<Y> const　＆　r);

  ~intrusive_ptr();

  intrusive_ptr & operator=(intrusive_ptr const & r);
  template <typename Y>
  intrusive_ptr& operator=(intrusive_ptr<Y> const & r);
  intrusive_ptr& operator=(T *r);

  void reset();
  void reset(T* r);
  void reset(T* r, bool add_ref);

  T& operator*() const;
  T* operator->() const;
  explicit operator bool() const;

  T* get() const;
  T* detach() const;
  void swap(intrusive_ptr& b);
｝
```   
- it requires the traits as follows:    
```cpp
void intrusive_ptr_add_ref(T* p);
void intrusive_ptr_release(T* p);
```


