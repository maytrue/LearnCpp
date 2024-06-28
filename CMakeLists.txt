cmake_minimum_required(VERSION 3.14)
project(CAndCppTrick)
set(CMAKE_CXX_STANDARD 20)
find_package(Threads REQUIRED)
# find_package(gflags REQUIRED)
# find_package(glog REQUIRED)
# add_subdirectory(./thirdparty/gflags)
# add_subdirectory(./thirdparty/glog)
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/thirdparty/spdlog/include
    ${CMAKE_SOURCE_DIR}/thirdparty/sigslot/include
    # ${CMAKE_SOURCE_DIR}/thirdparty/build/include
)

link_directories(
    # ${CMAKE_SOURCE_DIR}/thirdparty/build/lib
)

add_subdirectory(./ThreadSafeSingleton)
add_subdirectory(./DynamicRegisterModule)
add_subdirectory(./FindSubTree)
add_subdirectory(./ClassNotDestruct)
add_subdirectory(./basic)
add_subdirectory(./sigslot)
add_subdirectory(./lambda)
add_subdirectory(./rvalue_reference)
add_subdirectory(./pimpl)
