##CPP11/Boost Thread Wrapper
###Atomic
####Atomic Basic Usage
- atomic can make the operations of type T atomic, type T has to satisfy either
    - scalar, e.g, c++ built-in algorithm types, enum and pointers
    - trivial copy/move constructor, copy/move assignment constructor and destructor, able to use memcmp to 
     conduct comparison operation, often this kind of classes are all POD(plain old type)
- class abstract
```cpp
template<typename T>
class atomic: public atomics::detail::base_atomic<T
{
public:
    atomic() = default;
    explicit atomic(T v);   
    
    atomic(atomic const&) = delete;
    atomic& operator=(atomic const&) = delete;
    
    bool is_lock_free();
    void store(T value);
    T load();
    
    T operator=(T v) volatile;     //equals to sotre
    operator T() volatile const;   //implicit tyep-conversion, equals to load
    
    T exchange(T new_value);       // save value
    bool compare_exchange_weak(T& expected, T desired);
    bool compuare_exchange_strong(T& expected, T desired);
    
    T& storage();
    T const& storage() const;
};

//Sepcialization
template<>
class atomic<I>
{
public:
    T fetch_add(T v);
    T fetch_sub(T v);
    T fetch_and(T v);
    T fetch_or(T v);
    T fetch_xor(T v);
 
    T operator++();
    T operator--();
};

template<typename T>
class atomic<T*>
{
public:
    T* fetch_add(ptrdiff_t v);
    T* fetch_sub(ptrdiff_t v);
}
```
- atomic most operations are not return l-value, which means it is quite different from non-atomic operations
- usage: basically use store() and load()
    - actually we are provided with operator overriding, operator=() equals to sotre(), implicit operator T() equals to load()
    - exchange(), atomically exchange two values and reuturn the store value, compare_exchange_weak() and compare_exchange_strong() is 
    compare-and-swap, i.e, compare expected value, if two are equal, then store the desired value. 
    - difference between weak and strong is that, compare_exchange_weak is much more fast, but it is possible that it successes but return 
    false
    - atomic storage() can make us get the atomic value reference, which could not guarantee the atomic feature

####Instruction Order for Parallel Program
- compiler and cpu's optimization will have the chance to make instruction out-of-order, which may influence the sequential execution of 
   the program.
- actually, c++11 define the parallel memory model for this, including cpu, registers, machine codes, .etc these concepts
- <boost/memory_order.hpp> define the concetps of memory access order as follows   
```cpp
enum memory_order
{
    memory_order_relaxed =0 ;
    memory_order_consume =1 ;
    memory_order_acquire =2 ;
    memory_order_release =4 ;
    memory_order_acq_rel = 6;   //acquire | release
    memory_order_seq_cst = 14;  // acq_rel | 8
}
```
    
###Thread
####Basics
- static function: hardware_concurrency(), physical_concurrency()
- free functions(not in thread): get_id(), yield(), sleep_for(), sleep_until()
- thread function could be function/function object/bind/lambda expression, providing operator().
- usage: sleep_wait, join, detach(after which, thread object not represents for any threading, joinable()==false)
- thread_guard(RAII specifies the behaviors in destructor of thread), scoped_thread(similar to scoped_ptr)    

####Thread-Interrupt
- thread library defines 12 types of interrupt points, which are all functions
    - thread::join()
    - thread::try_join_for()/ try_join_until()
    - condition_variable::wait()
    - condition_variable::wait_for()/wait_until()
    - condition_variable_any::wait()
    - condition_variable_any::wait_for()/wait_until()
    - this_thread::sleep_for()/sleep_until()

####Call-Once
- this mechanism requires to use static one_flag object, which is used as the initialization flag
    
###Mutex
####Shared-Mutex
- share mutex is different from mutex and recursive_mutex, which allows threads have multiple share-ownership and single 
private ownership, implementing the mechanism of read-write-lock, i.e, multiple read-threads and single write thread
- class abstract is as follows
```cpp
class shared_mutex
{
    public:
        shared_mutex();
        ~shared_mutex();
       
        void lock();
        bool try_lock();
        void unlock();
        bool try_lock_for(const chrono::duration& rel_time);
        bool try_lock_until(cosnt chrono::time_point& abs_time);
        
        //single ownership functions:
        bool lock_shared();
        bool try_lock_shared();
        void unlock_shared();
        
        bool try_lock_shared_for(const duration& rel_time);
        bool try_lock_shared_until(const time_point& abs_time);
        
}
```      
####Lock-Adapter

###Condition-Variable
- condition_variable_any's class abstract is as follows:   
```cpp
enum class cv_status{no_timeout, timeout};
class condition_variable_any
{
    public:
        void notify_one();
        void notify_all();
        
        void wait(lock_type& lock);
        void wait(lock_type& lock, predicate_type predicate);
        
        cv_status_wait_for(lock_type& lock, const duration& d);
        cv_status_wait_for(lock_type& lock, const duration& d, predicate_type predicate);
        cv_status_wait_until(lock_type& lock, const time_point& t);
        cv_status_wait_until(lock_type& lock, const time_point&t, predicate_type predicate);
}
```
- Usage
    - In thread, which executes the instruction-flow that requires certain condition met, 
    wait(lock_type& lock), unlock, i.e, moving the thread_id from mutex_queue into condition_variable_queue
    - In thread, which checks the condition and arouse the waiting threads, 
    notify_one(), move one thread_id from the condition_variable_queue to the mutex_queue. notify_all(), move 
    all thread_ids from the condition_variable_queue to the mutex_queue
    
###Future
####Unique_Feature
- class abstract:   
```cpp
enum class future_status{
    ready,
    timeout,
    deferred
}

template<typename T>
class future
{
public:
    T get();
    
    void wait() const;
    future_status wait_for(const duration& rel_time) const;
    future_status wait_until(const time_pint& abs_time) const;
    
    bool valid() const; 
    bool is_ready() const;
    bool has_exception() const;
    bool has_value() const;
    
    shared_future share();
}
```    
- future's member function wait() is used for waiting for the asynchronous computation result, blocking wait the 
 execution of threads until getting the result
- future's member function get() is used for acquiring the result of future computation, in default, it will invoke 
wait() to wait for the end of computation
- function async() is used for generating future objects
- usage is as follows:   
```cpp
async(bind(dummy,10));

auto f = async([]{cout << "hello" << endl});
f.wait();
```
- the above code is equal to the following code:   
```cpp
thread(dummy, 10).detach();
thread t([]{cout << "hello" << endl});
t.join();
```    
####Shared_Feature
- unique_feature's result could merely be accessed once, which gives the restriction that it could not be 
accessed by multiple threads
- share feature make it possible to be invoked its get() to get the computation result and guarantee thread-safety