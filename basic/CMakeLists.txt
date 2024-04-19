add_executable(friend_class_test friend_class_test.cc)

add_executable(call_back_test call_static_variable.cc)

target_link_libraries(call_back_test pthread)

add_executable(listener listener.cc)