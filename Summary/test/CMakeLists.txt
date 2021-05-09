find_package(doctest 2.3.6 REQUIRED)
find_library(LIBRARY libPDFNetC.so PATHS ../libs)
include_directories(../libs)

add_executable(tests test.cpp ../src/PicturesChecker.cpp ../src/PicturesChecker.h)

target_sources(tests PRIVATE ../src/Settings.cpp ../src/Settings.h ../src/Parser.cpp ../src/Parser.h ../src/Result.cpp ../src/Result.h ../src/Rule.h ../src/HeadChecker.cpp ../src/HeadChecker.h ../src/StyleChecker.cpp ../src/StyleChecker.h ../src/TestChecker.cpp ../src/TestChecker.h ../src/TableOfContentChecker.cpp ../src/TableOfContentChecker.h)

target_link_libraries(tests
    PRIVATE
        doctest::doctest
        ${LIBRARY}
)

add_custom_target(check ALL COMMAND tests)