//
//  TestMatrix.cpp
//  Matrix
//
//  Created by Juan Trejo on 9/7/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "Matrix.hpp"

TEST(test_matrix, test_getters_1)
{
    Matrix<int> A(1, 3, 1);
    ASSERT_EQ(A.getRows(), 1);
    ASSERT_EQ(A.getCols(), 3);
}

TEST(test_matrix, test_getters_2)
{
    Matrix<int> A = Matrix<int>();
    ASSERT_EQ(A.getRows(), 1);
    ASSERT_EQ(A.getCols(), 1);
}

TEST(test_matrix, test_index_operator_1)
{
    Matrix<int> A(3, 3);
    ASSERT_EQ(A.at(1, 1), 0);
    ASSERT_EQ(A(1,1), 0);
}

TEST(test_matrix, test_index_operator_2)
{
    Matrix<int> A(1,1);
    ASSERT_THROW(A.at(2, 2), std::out_of_range);
}
