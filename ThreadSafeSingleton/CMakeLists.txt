add_executable(
    thread_safe_singleton
    main.cpp
    TestClass.cpp
)
target_link_libraries(thread_safe_singleton Threads::Threads)

add_executable(singleton_static singleton_static_test.cc)
target_link_libraries(singleton_static -pthread)