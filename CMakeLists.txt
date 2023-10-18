cmake_minimum_required(VERSION 3.14)
project(CAndCppTrick)
find_package(Threads REQUIRED)
# find_package(gflags REQUIRED)
# find_package(glog REQUIRED)
# add_subdirectory(./thirdparty/gflags)
# add_subdirectory(./thirdparty/glog)
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/thirdparty/spdlog/include
    # ${CMAKE_SOURCE_DIR}/thirdparty/build/include
)

link_directories(
    # ${CMAKE_SOURCE_DIR}/thirdparty/build/lib
)

add_subdirectory(./ThreadSafeSingleton)
add_subdirectory(./DynamicRegisterModule/DynamicRegisterModule)
add_subdirectory(./FindSubTree)
add_subdirectory(./ClassNotDestruct)
add_subdirectory(./basic)
