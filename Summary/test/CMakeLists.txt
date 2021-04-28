find_package(doctest 2.3.6 REQUIRED)
find_library(LIBRARY libPDFNetC.so PATHS ../libs)
include_directories(../libs)

add_executable(tests test.cpp)

target_sources(tests PRIVATE ../src/Settings.cpp ../src/Settings.h ../src/Parser.cpp ../src/Parser.h ../src/Checker.cpp ../src/Checker.h ../src/Rule.h ../src/HeadChecker.cpp ../src/HeadChecker.h ../src/StyleChecker.cpp ../src/StyleChecker.h ../src/TestChecker.cpp ../src/TestChecker.h)

target_link_libraries(tests
    PRIVATE
        doctest::doctest
        ${LIBRARY}
)

add_custom_target(check ALL COMMAND tests)