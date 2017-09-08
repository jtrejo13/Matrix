//
//  TestMatrix.cpp
//  Matrix
//
//  Created by Juan Trejo on 9/7/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>
#include "Matrix.hpp"

//////////////////
//   Getters    //
//////////////////

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

////////////////////////
//   Element Access   //
////////////////////////

TEST(test_matrix, test_index_operator_1)
{
    Matrix<int> A(3, 3);
    ASSERT_EQ(A.at(1, 1), 0);
    ASSERT_EQ(A(1, 1), 0);
}

TEST(test_matrix, test_index_operator_2)
{
    Matrix<double> A(10, 10, 2.5);
    ASSERT_EQ(A.at(8, 3), 2.5);
    ASSERT_EQ(A(9, 9), 2.5);
}

TEST(test_matrix, test_index_operator_3)
{
    Matrix<int> A(1, 1);
    ASSERT_THROW(A.at(2, 2), std::out_of_range);
}

////////////////////////
//     Scalar Ops     //
////////////////////////

TEST(test_matrix, test_scalarOp_sum_1)
{
    Matrix<int> A(3, 3, 2);
    Matrix<int> B = A + 5;
    ASSERT_EQ(B.toString(), "{ { 7, 7, 7 } { 7, 7, 7 } { 7, 7, 7 } }");
}

TEST(test_matrix, test_scalarOp_sum_2)
{
    Matrix<int> A = Matrix<int>();
    Matrix<int> B = A + 3;
    ASSERT_EQ(B.toString(), "{ { 3 } }");
}

TEST(test_matrix, test_scalarOp_sub_1)
{
    Matrix<int> A(3, 3, 12);
    Matrix<int> B = A - 5;
    ASSERT_EQ(B.toString(), "{ { 7, 7, 7 } { 7, 7, 7 } { 7, 7, 7 } }");
}

TEST(test_matrix, test_scalarOp_sub_2)
{
    Matrix<int> A = Matrix<int>();
    Matrix<int> B = A - 3;
    ASSERT_EQ(B.toString(), "{ { -3 } }");
}

TEST(test_matrix, test_scalarOp_mult_1)
{
    Matrix<double> A(3, 3, 3.5);
    Matrix<double> B = A * 2;
    ASSERT_EQ(B.toString(), "{ { 7, 7, 7 } { 7, 7, 7 } { 7, 7, 7 } }");
}

TEST(test_matrix, test_scalarOp_mult_2)
{
    Matrix<int> A = Matrix<int>();
    Matrix<int> B = A * 3;
    ASSERT_EQ(B.toString(), "{ { 0 } }");
}

TEST(test_matrix, test_scalarOp_div_1)
{
    Matrix<double> A(3, 3, 14);
    Matrix<double> B = A / 2;
    ASSERT_EQ(B.toString(), "{ { 7, 7, 7 } { 7, 7, 7 } { 7, 7, 7 } }");
}

TEST(test_matrix, test_scalarOp_div_2)
{
    Matrix<int> A = Matrix<int>();
    Matrix<int> B = A / 3;
    ASSERT_EQ(B.toString(), "{ { 0 } }");
}

////////////////////////////
//    Matrix/Matrix Ops   //
////////////////////////////

TEST(test_matrix, test_mat_matOp_sum_1)
{
    Matrix<double> A(3, 3, 2);
    Matrix<double> B(3, 3, 5);
    Matrix<double> C = A + B;
    ASSERT_EQ(C.toString(), "{ { 7, 7, 7 } { 7, 7, 7 } { 7, 7, 7 } }");
}

TEST(test_matrix, test_mat_matOp_sum_2)
{
    Matrix<double> A(3, 3, 2);
    Matrix<double> B(4, 4, 5);
    Matrix<double> C;
    ASSERT_THROW(C = A + B, std::length_error);
}

TEST(test_matrix, test_mat_matOp_sub_1)
{
    Matrix<double> A(3, 3, 10);
    Matrix<double> B(3, 3, 3);
    Matrix<double> C = A - B;
    ASSERT_EQ(C.toString(), "{ { 7, 7, 7 } { 7, 7, 7 } { 7, 7, 7 } }");
}

TEST(test_matrix, test_mat_matOp_sumEQ_1)
{
    Matrix<double> A(3, 3, 2);
    Matrix<double> B(3, 3, 5);
    A += B;
    ASSERT_EQ(A.toString(), "{ { 7, 7, 7 } { 7, 7, 7 } { 7, 7, 7 } }");
}

TEST(test_matrix, test_mat_matOp_subEQ_1)
{
    Matrix<double> A(3, 3, 10.5);
    Matrix<double> B(3, 3, 3.5);
    A -= B;
    ASSERT_EQ(A.toString(), "{ { 7, 7, 7 } { 7, 7, 7 } { 7, 7, 7 } }");
}


TEST(test_matrix, test_mat_matOp_mult_1)
{
    Matrix<double> A(3, 3, 2);
    Matrix<double> B(3, 3, 5);
    Matrix<double> C = A * B;
    ASSERT_EQ(C.toString(), "{ { 30, 30, 30 } { 30, 30, 30 } { 30, 30, 30 } }");
}

TEST(test_matrix, test_mat_matOp_multEQ_1)
{
    Matrix<double> A(3, 3, 2);
    Matrix<double> B(3, 3, 5);
    A *= B;
    ASSERT_EQ(A.toString(), "{ { 30, 30, 30 } { 30, 30, 30 } { 30, 30, 30 } }");
}

