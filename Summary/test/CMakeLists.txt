cmake_minimum_required(VERSION 3.1)
project(Summary_work_test VERSION 1.0.0 LANGUAGES CXX)

find_library(LIBRARY libPDFNetC.so PATHS Lib)

include_directories(libs)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(test test.cpp)

target_link_libraries(test ${LIBRARY} )

# g++ main.cpp -I../libs -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp