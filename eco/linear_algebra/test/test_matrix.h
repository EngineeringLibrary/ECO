//
// Created by joey on 4/18/16.
//

#ifndef ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_MATRIX_H

#include <cxxtest/TestSuite.h>
#include "../header/matrix.h"

class MatrixTestSuite : public CxxTest::TestSuite {
public:

    void test_build_matrix_from_string_1x3(void) {

        LinAlg::Matrix<int> M1 = "1 ,2, 3";

        TS_TRACE("INSTANCIANDO MATRIZ 1x3");
        TS_ASSERT_EQUALS(M1(1, 1), 1);
        TS_ASSERT_EQUALS(M1(1, 2), 2);
        TS_ASSERT_EQUALS(M1(1, 3), 3);
    }

    void test_build_matrix_from_string_2x3(void) {
        LinAlg::Matrix<int> M2 = "1,2 ,3; 4, 5,6";

        TS_TRACE("INSTANCIANDO MATRIZ 2x3 DE INTEIROS");
        TS_ASSERT_EQUALS(M2(1, 1), 1);
        TS_ASSERT_EQUALS(M2(1, 2), 2);
        TS_ASSERT_EQUALS(M2(1, 3), 3);
        TS_ASSERT_EQUALS(M2(2, 1), 4);
        TS_ASSERT_EQUALS(M2(2, 2), 5);
        TS_ASSERT_EQUALS(M2(2, 3), 6);
    }
};

#define ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_MATRIX_H

#endif //ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_MATRIX_H
