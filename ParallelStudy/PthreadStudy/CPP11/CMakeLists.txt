add_executable(CPP11HelloWorld CPP11ThreadBasicUsage.cpp)
target_link_libraries(CPP11HelloWorld ${CMAKE_THREAD_LIBS_INIT})

add_executable(CPP11ThreadInterrupt CPP11ThreadInterrupt.cpp)
target_link_libraries(CPP11ThreadInterrupt ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} )

add_executable(CPP11CallOnce CPP11CallOnce.cpp)
target_link_libraries(CPP11CallOnce ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})

add_executable(CPP11ProducerConsumerFILO CPP11ProducerConsumerFILO.cpp)
target_link_libraries(CPP11ProducerConsumerFILO ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})

add_executable(CPP11SharedMutex CPP11SharedMutex.cpp)
target_link_libraries(CPP11SharedMutex ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})

add_executable(CPP11FutureComputation CPP11FutureComputation.cpp)
target_link_libraries(CPP11FutureComputation ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})

add_executable(CPP11Atomic CPP11Atomic.cpp)
target_link_libraries (CPP11Atomic ${Boost_LIBRARIES})

add_executable(CPP11AtomicRefCount CPP11AtomicRefCount.cpp)
target_link_libraries (CPP11AtomicRefCount ${Boost_LIBRARIES})
