add_executable(
    roaring_test
    roaring_test.cc
)

target_link_libraries(
    roaring_test
    roaring::roaring
)