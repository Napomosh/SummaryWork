cmake_minimum_required(VERSION 3.1)


project(Summary_work)

find_library(LIBRARY libPDFNetC.so PATHS /home/alex/Summary/Summary/Lib)

include_directories(Headers)

set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(main CPP/main.cpp)

target_link_libraries(main ${LIBRARY})


# g++ main.cpp -I../Headers -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp