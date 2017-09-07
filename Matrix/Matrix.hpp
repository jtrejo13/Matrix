//
//  Matrix.hpp
//  Matrix
//
//  Created by Juan Trejo on 9/7/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef __MATRIX_H
#define __MATRIX_H

#include <vector>
#include <functional>
#include <iostream>
#include <sstream>

template <typename T> class Matrix{
    
private:
    std::vector<std::vector<T> > _mat;
    size_t _rows;
    size_t _cols;
    Matrix<T> scalarOperation(const T& rhs, std::function<T(T,T)> func) const;
    
public:
    
    //    typedef T* iterator;
    //    typedef const T* const_iterator;
    
    //Constructors
    Matrix();
    Matrix(size_t rows, size_t cols, const T& initial = T());
    Matrix(const Matrix<T>& rhs);
    
    //Destructor
    ~Matrix();
    
    //Copy assignment
    Matrix<T>& operator=(const Matrix<T>& rhs);
    //
    //    //Matrix/Matrix operations
    //    Matrix<T> operator+(const Matrix<T>& rhs) const;
    //    Matrix<T> operator-(const Matrix<T>& rhs) const;
    //    Matrix<T> operator*(const Matrix<T>& rhs) const;
    //    Matrix<T>& operator+=(const Matrix<T>& rhs);
    //    Matrix<T>& operator-=(const Matrix<T>& rhs);
    //    Matrix<T>& operator*=(const Matrix<T>& rhs);
    //    Matrix<T> transpose() const;
    //
    //Matrix/Scalar operations
    Matrix<T> operator+(const T& rhs) const;
    Matrix<T> operator-(const T& rhs) const;
    Matrix<T> operator*(const T& rhs) const;
    Matrix<T> operator/(const T& rhs) const;
    
    //    //Matrix/Vector operations
    //    std::vector<T> operator*(const std::vector<T>& rhs) const;
    
    //Element Access functions
    T& at(const size_t& row, const size_t& col);
    const T& at(const size_t& row, const size_t& col) const;
    T& operator()(const size_t& row, const size_t& col);
    const T& operator()(const size_t& row, const size_t& col) const;
    
    //Access row and column sizes
    size_t getRows() const;
    size_t getCols() const;
    
    //Print Matrix
    std::string toString() const;
    
    //    //Iterators
    //    iterator begin();
    //    iterator end();
    //    const_iterator begin() const;
    //    const_iterator end() const;
};

#include "Matrix.cpp"

#endif //__MATRIX_H
