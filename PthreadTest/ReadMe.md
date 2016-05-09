#Basic Concepts for Pthread
##Condition Variable
- Linux Posix Implementation  
There will be a cond queue and mutex queue.  

- Def  
Condition variable is a mechanism to synchronize threads with shared global variable. Two actions:
block and wait for the reaching of condition, signal that condition has reached.  
In order to avoid race condition, condition variable is always used together with mutex variable.

- Create(Static/Dynamic)  
```cpp
      pthread_cond_t   cond=PTHREAD_COND_INITIALIZER
      int   pthread_cond_init(pthread_cond_t   *cond,   pthread_condattr_t   *cond_attr)    
```

- Wait(With/Without Timeout)  
```cpp
    int   pthread_cond_wait(pthread_cond_t   *cond,   pthread_mutex_t   *mutex)   
    int   pthread_cond_timedwait(pthread_cond_t   *cond,   pthread_mutex_t   *mutex,   const   struct   timespec   *abstime)    
```

- Signal  
```cpp
    pthread_cond_signal()
    pthread_cond_broadcast()
```

- Demonstration :
  - [CVTest](./CVTest.cpp)  Also include thread_cancel operation.
  - [GlobalQueueTest](./CVTest2GlobalQueue.cpp) Use vector as global queue, mimic reduce operation.

- Explanation for while(pthread_cont_wait)  
  Because multi-threads can receive the signal and awake, but the execution of one thread may change the condition status.

#Reference  
- [Condition Variable Blog in Chinese](http://blog.csdn.net/hairetz/article/details/4535920)
- [Analysis For while(wait...) of CV in Chinese](http://www.cppblog.com/izualzhy/archive/2011/11/14/160120.html)

#Todo
Translate all the comments in [CVTest.cpp](./CVTest.cpp) to English. And remove useless and misleading codes.