cmake_minimum_required(VERSION 3.14 FATAL_ERROR) #мин допустимая версия 
project(test_proj VERSION 0.0.0 LANGUAGES CXX)#c++ 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(my_lib)#кда перейти

add_executable(exec_trg 5.all.cpp)
set_source_files_properties(5.all.cpp PROPERTIES
    LANGUAGE CXX
    
)
target_link_libraries(exec_trg PUBLIC mylib)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()