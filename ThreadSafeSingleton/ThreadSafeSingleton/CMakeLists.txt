add_executable(
    thread_safe_singleton
    main.cpp
    TestClass.cpp
)

target_link_libraries(thread_safe_singleton Threads::Threads)
