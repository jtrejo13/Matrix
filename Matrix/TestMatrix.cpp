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

TEST(test_matrix, test_getters)
{
    Matrix<int> A(1, 3, 1);
    ASSERT_EQ(A.getRows(), 1);
}
