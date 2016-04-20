cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(engineering_ctrl_optimize_lib)

#=============================================================
# main()
#=============================================================
if (NOT DEFINED CXXTEST_TESTGEN_ARGS)
    set(CXXTEST_TESTGEN_ARGS --error-printer)
endif ()

find_package(PythonInterp QUIET)
find_package(Perl QUIET)

find_path(CXXTEST_INCLUDE_DIR cxxtest/TestSuite.h)
find_program(CXXTEST_PYTHON_TESTGEN_EXECUTABLE
        NAMES cxxtestgen cxxtestgen.py
        PATHS ${CXXTEST_INCLUDE_DIR})
find_program(CXXTEST_PERL_TESTGEN_EXECUTABLE cxxtestgen.pl
        PATHS ${CXXTEST_INCLUDE_DIR})

if (PYTHONINTERP_FOUND OR PERL_FOUND)
    #include(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)

    if (PYTHONINTERP_FOUND AND (CXXTEST_USE_PYTHON OR NOT PERL_FOUND OR NOT DEFINED CXXTEST_USE_PYTHON))
        set(CXXTEST_TESTGEN_EXECUTABLE ${CXXTEST_PYTHON_TESTGEN_EXECUTABLE})
        set(CXXTEST_TESTGEN_INTERPRETER ${PYTHON_EXECUTABLE})
        FIND_PACKAGE_HANDLE_STANDARD_ARGS(CxxTest DEFAULT_MSG
                CXXTEST_INCLUDE_DIR CXXTEST_PYTHON_TESTGEN_EXECUTABLE)

    elseif (PERL_FOUND)
        set(CXXTEST_TESTGEN_EXECUTABLE ${CXXTEST_PERL_TESTGEN_EXECUTABLE})
        set(CXXTEST_TESTGEN_INTERPRETER ${PERL_EXECUTABLE})
        FIND_PACKAGE_HANDLE_STANDARD_ARGS(CxxTest DEFAULT_MSG
                CXXTEST_INCLUDE_DIR CXXTEST_PERL_TESTGEN_EXECUTABLE)
    endif ()

    if (CXXTEST_FOUND)
        set(CXXTEST_INCLUDE_DIRS ${CXXTEST_INCLUDE_DIR})
    endif ()

else ()

    set(CXXTEST_FOUND false)
    if (NOT CxxTest_FIND_QUIETLY)
        if (CxxTest_FIND_REQUIRED)
            message(FATAL_ERROR "Neither Python nor Perl found, cannot use CxxTest, aborting!")
        else ()
            message(STATUS "Neither Python nor Perl found, CxxTest will not be used.")
        endif ()
    endif ()

endif ()

#
# Testing stuff
#

find_package(CxxTest)

if (CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR} /eco/)
    enable_testing()

    CXXTEST_ADD_TEST(test_linear_algebra_matrix test_linear_algebra_matrix.cc
            ${CMAKE_CURRENT_SOURCE_DIR}/eco/linear_algebra/test/test_matrix.h)

    CXXTEST_ADD_TEST(test_linear_algebra_linalg test_linear_algebra_linalg.cc
            ${CMAKE_CURRENT_SOURCE_DIR}/eco/linear_algebra/test/test_linalg.h)
endif ()

set(SOURCE_FILES main.cpp)
add_executable(engineering_ctrl_optimize_lib ${SOURCE_FILES})