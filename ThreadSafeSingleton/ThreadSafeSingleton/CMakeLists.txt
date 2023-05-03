add_executable(
    thread_safe_singleton
    main.cpp
    TestClass.cpp
)
target_link_directories(thread_safe_singleton -lpthread)