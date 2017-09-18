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

/////////////////////////
// MARK: Constructors
/////////////////////////

TEST(test_matrix, test_const_1)
{
    Matrix<int> A(2, 2, {1, 2,
                         3, 4});
    ASSERT_EQ(A.toString(), "{ { 1, 2 } { 3, 4 } }");
}

TEST(test_matrix, test_const_2)
{
    Matrix<int> A(4, 2, {1, 2,
                         3, 4,
                         5, 6,
                         7, 8});
    ASSERT_EQ(A.toString(), "{ { 1, 2 } { 3, 4 } { 5, 6 } { 7, 8 } }");
}

////////////////////
// MARK: Getters
////////////////////

TEST(test_matrix, test_getters_1)
{
    Matrix<int> A(1, 3, 1);
    ASSERT_EQ(A.size_rows(), 1);
    ASSERT_EQ(A.size_cols(), 3);
}

TEST(test_matrix, test_getters_2)
{
    Matrix<int> A = Matrix<int>();
    ASSERT_EQ(A.size_rows(), 1);
    ASSERT_EQ(A.size_cols(), 1);
}

TEST(test_matrix, test_getters_3)
{
    Matrix<int> A(2, 2, {1, 2, 3, 4});
    ASSERT_EQ(A.size_rows(), 2);
    ASSERT_EQ(A.size_cols(), 2);
}

////////////////////////////
// MARK: Element Access
////////////////////////////


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

TEST(test_matrix, test_index_operator_4)
{
    Matrix<int> A(3, 3, {0, 1, 2,
                         3, 4, 5,
                         6, 7, 8});
    ASSERT_EQ(A.at(1, 1), 4);
}

////////////////////////
// MARK: Scalar Ops
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

TEST(test_matrix, test_scalarOp_sum_3)
{
    Matrix<int> A(3, 3, {0, 1, 2,
                         3, 4, 5,
                         6, 7, 8});
    Matrix<int> B = A + 3;
    ASSERT_EQ(B.toString(), "{ { 3, 4, 5 } { 6, 7, 8 } { 9, 10, 11 } }");
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

TEST(test_matrix, test_scalarOp_mult_3)
{
    Matrix<int> A(3, 3, {0, 1, 2,
        3, 4, 5,
        6, 7, 8});
    Matrix<int> B = A * 3;
    ASSERT_EQ(B.toString(), "{ { 0, 3, 6 } { 9, 12, 15 } { 18, 21, 24 } }");
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

//////////////////////////////
// MARK: Matrix/Matrix Ops
//////////////////////////////

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

//////////////////////////////
// MARK: Matrix/Vector Ops
//////////////////////////////

TEST(test_matrix, test_mat_vecOp_mult_1)
{
    Matrix<double>      A(3, 3, 2);
    std::vector<double> x(3, 2);
    std::vector<double> b = A * x;
    ASSERT_EQ(b, std::vector<double>(3, 12));
}

TEST(test_matrix, test_mat_vecOp_mult_2)
{
    Matrix<double>      A(3, 3, 2);
    std::vector<double> x(10, 2);
    std::vector<double> b;
    ASSERT_THROW(b = A * x, std::length_error);
}

TEST(test_matrix, test_mat_prop_1)
{
    Matrix<double> A(4, 4, {1,  2,  3,  4,
                         5,  6,  7,  8,
                         9, 10, 11, 12,
                        13, 14, 15, 16});
    std::vector<double> v = A.diag_vec();
    ASSERT_EQ(v, std::vector<double>({1, 6, 11, 16}));
}
