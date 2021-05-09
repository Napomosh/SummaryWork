cmake_minimum_required(VERSION 3.1)
project(Summary_work VERSION 1.0.0 LANGUAGES CXX)

find_library(LIBRARY libPDFNetC.so PATHS libs)
find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(libs)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_subdirectory(test)

add_executable(main src/main.cpp src/Settings.cpp src/Settings.h src/Parser.cpp src/Parser.h src/Result.cpp src/Result.h src/Rule.h src/HeadChecker.cpp src/HeadChecker.h src/StyleChecker.cpp src/StyleChecker.h src/TestChecker.cpp src/TestChecker.h src/TableOfContentChecker.cpp src/TableOfContentChecker.h src/PicturesChecker.cpp src/PicturesChecker.h src/TitleChecker.cpp src/TitleChecker.h)

target_link_libraries(main ${LIBRARY})
target_link_libraries(main nlohmann_json::nlohmann_json)