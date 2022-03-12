cmake_minimum_required(VERSION 3.14)
project(nmp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(main main.cpp)
add_dependencies(main gtest)
target_link_libraries(main gtest_main)

find_package (Threads REQUIRED)

target_link_libraries(main
    ${CMAKE_THREAD_LIBS_INIT}
)
add_compile_options(-pthread)
