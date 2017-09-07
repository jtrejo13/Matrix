//
//  main.cpp
//  Matrix
//
//  Created by Juan Trejo on 9/7/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>
#include "Matrix.hpp"

int main(int argc, char * argv[]) {
//    Matrix<int> A(3, 3, 1);
//    std::cout << A.toString() << "\n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
