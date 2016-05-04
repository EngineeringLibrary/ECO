//
// Created by joey on 4/18/16.
//

#ifndef ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_MATRIX_H

#include <cxxtest/TestSuite.h>
#include "../header/matrix.h"

class MatrixTestSuite : public CxxTest::TestSuite {
public:

    void test_build_matrix_int_from_string_1x3(void) {

        TS_TRACE("MATRIZ 1x3 - INT");
        LinAlg::Matrix<int> M1 = "1 ,2, 3";

        TS_ASSERT_EQUALS(M1(1, 1), 1);
        TS_ASSERT_EQUALS(M1(1, 2), 2);
        TS_ASSERT_EQUALS(M1(1, 3), 3);
    }

    void test_build_matrix_int_from_string_2x3(void) {
        TS_TRACE("MATRIZ 2x3 - INT");

        LinAlg::Matrix<int> M2 = "1,2 ,3; 4, 5,6";

        TS_ASSERT_EQUALS(M2(1, 1), 1);
        TS_ASSERT_EQUALS(M2(1, 2), 2);
        TS_ASSERT_EQUALS(M2(1, 3), 3);
        TS_ASSERT_EQUALS(M2(2, 1), 4);
        TS_ASSERT_EQUALS(M2(2, 2), 5);
        TS_ASSERT_EQUALS(M2(2, 3), 6);
    }

    void test_build_matrix_int_from_string(void) {
        TS_TRACE("MATRIZ 3x3 - INT");

        LinAlg::Matrix<int> M1 = "1 ,2, 3; 4, 5, 6; 7, 8, 9";

        TS_ASSERT_EQUALS(M1(1, 1), 1);
        TS_ASSERT_EQUALS(M1(1, 2), 2);
        TS_ASSERT_EQUALS(M1(1, 3), 3);
        TS_ASSERT_EQUALS(M1(2, 1), 4);
        TS_ASSERT_EQUALS(M1(2, 2), 5);
        TS_ASSERT_EQUALS(M1(2, 3), 6);
        TS_ASSERT_EQUALS(M1(3, 1), 7);
        TS_ASSERT_EQUALS(M1(3, 2), 8);
        TS_ASSERT_EQUALS(M1(3, 3), 9);

    }

    void test_build_matrix_float_from_string(void) {
        TS_TRACE("MATRIZ 1x3 - FLOAT");

        LinAlg::Matrix<float> M1 = "1.1, 2, 3.45";

        TS_ASSERT_DELTA(M1(1, 1), 1.1, 0.01);
        TS_ASSERT_DELTA(M1(1, 2), 2.0, 0.01);
        TS_ASSERT_DELTA(M1(1, 3), 3.45, 0.01);

    }
};

#define ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_MATRIX_H

#endif //ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_MATRIX_H
