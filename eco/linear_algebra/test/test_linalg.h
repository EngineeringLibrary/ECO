//
// Created by joey on 4/19/16.
//

#ifndef ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_LINALG_H_H

#include <cxxtest/TestSuite.h>
#include "../header/matrix.h"
#include "../header/linalg.h"

class LinalgTestSuite : public CxxTest::TestSuite {
public:

    void test_matrix_balancing(void) {

        LinAlg::Matrix<double> test_matrix(
                        "1,2,3;"
                        "4,5,6;"
                        "7,8,9;"
                        "3,2,2");

        TS_TRACE("INSTANCIANDO MATRIZ 4x3");
        LinAlg::Balance(test_matrix);  //Will balance matrix. By reference

        TS_ASSERT_DELTA(test_matrix(1, 1), 1.0000, 0.0001);
        TS_ASSERT_DELTA(test_matrix(1, 2), 2.0000, 0.0001);
        TS_ASSERT_DELTA(test_matrix(1, 3), 3.0000, 0.0001);

        TS_ASSERT_DELTA(test_matrix(2, 1), 4.0000, 0.0001);
        TS_ASSERT_DELTA(test_matrix(2, 2), 5.0000, 0.0001);
        TS_ASSERT_DELTA(test_matrix(2, 3), 6.0000, 0.0001);

        TS_ASSERT_DELTA(test_matrix(3, 1), 7.0000, 0.0001);
        TS_ASSERT_DELTA(test_matrix(3, 2), 8.0000, 0.0001);
        TS_ASSERT_DELTA(test_matrix(3, 3), 9.0000, 0.0001);

        //Balance might reset last row
        TS_ASSERT_DELTA(test_matrix(4, 1), 0.0000, 0.0001);
        TS_ASSERT_DELTA(test_matrix(4, 2), 0.0000, 0.0001);
        TS_ASSERT_DELTA(test_matrix(4, 3), 0.0000, 0.0001);

    }
};

#define ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_LINALG_H_H

#endif //ENGINEERING_CTRL_OPTIMIZE_LIB_TEST_LINALG_H_H
