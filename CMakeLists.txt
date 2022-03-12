cmake_minimum_required(VERSION 3.8)
project(nmp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_executable(main main.cpp)

find_package (Threads REQUIRED)

target_link_libraries(main
    ${CMAKE_THREAD_LIBS_INIT}
)
add_compile_options(-pthread)


enable_testing()

target_link_libraries(main gtest gtest_main)

# include(ExternalProject)
# ExternalProject_Add(gtest
#   URL https://github.com/google/googletest/archive/release-1.8.0.zip
#   PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
#   INSTALL_COMMAND ""
# )
# ExternalProject_Get_Property(gtest source_dir binary_dir)

# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})
#add_dependencies(main gtest)