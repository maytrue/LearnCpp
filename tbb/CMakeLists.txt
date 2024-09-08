add_executable(
    sub_string_finder
    sub_string_finder.cc
)

target_link_libraries(
    sub_string_finder
    PRIVATE
    tbb
)

add_executable(
    square
    square.cc
)

target_link_libraries(
    square
    PRIVATE
    tbb
)
