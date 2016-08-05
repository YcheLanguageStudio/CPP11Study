##CPP11/Boost Thread Wrapper
###Thread
####Basics
- static function: hardware_concurrency(), physical_concurrency()
- free functions(not in thread): get_id(), yield(), sleep_for(), sleep_until()
- thread function could be function/function object/bind/lambda expression, providing operator().
- usage: sleep_wait, join, detach(after which, thread object not represents for any threading, joinable()==false)
- thread_guard(RAII specifies the behaviors in destructor of thread), scoped_thread(similar to scoped_ptr)

####Interrupt
- thread library defines 12 types of interrupt points, which are all functions
    - thread::join()
    - thread::try_join_for()/ try_join_until()
    - condition_variable::wait()
    - condition_variable::wait_for()/wait_until()
    - condition_variable_any::wait()
    - condition_variable_any::wait_for()/wait_until()
    - this_thread::sleep_for()/sleep_until()
    
###Mutex
###Lock-Adapter
###Condition-Variable