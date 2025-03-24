add_executable(friend_class_test friend_class_test.cc)

add_executable(call_back_test call_static_variable.cc)

target_link_libraries(call_back_test pthread)

add_executable(listener listener.cc)

add_executable(console_color console_color.cc)

add_executable(shared_ptr_test shared_ptr_test.cc)
target_link_libraries(shared_ptr_test pthread)

add_executable(std_generator std_generator.cc)

add_executable(
    std_clamp_test
    std_clamp_test.cc
)
