//
//  Matrix.cpp
//  Matrix
//
//  Created by Juan Trejo on 9/7/17.
//  Copyright © 2017 PocketMatlab. All rights reserved.
//

#ifndef __MATRIX_CPP
#define __MATRIX_CPP

#include "Matrix.hpp"

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, const T& initial) {
    _mat.resize(cols);
    for (uint c = 0; c < cols; ++c) {
        _mat[c].resize(rows, initial);
    }
    _rows = rows;
    _cols = cols;
}

template <typename T>
Matrix<T>::Matrix() {
    _mat.resize(1);
    _mat[0].resize(1, T());
    _rows = 1;
    _cols = 1;
}

template <typename T>
Matrix<T>::~Matrix() {
    std::cout << "Matrix Destroyed" << std::endl;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &rhs)
{
    _mat  = rhs._mat;
    _rows = rhs._rows;
    _cols = rhs._cols;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &rhs) {
    _rows = rhs._rows;
    _cols = rhs._cols;
    _mat = rhs._mat;
    return *this;
}

///*//////////////////////Matrix/Matrix operations//////////////////////*/

template <typename T>
Matrix<T> Matrix<T>::elementByElementOp(const Matrix<T> &rhs, std::function<T(T,T)> func) const
{
    if (rhs._rows != _rows || rhs._cols != _cols) {
        throw std::length_error("Matrix dimensions must agree");
    }
    
    Matrix<T> result(_rows, _cols);
    for (uint c = 0; c < _cols; ++c) {
        for (uint r = 0; r < _rows; ++r) {
            result(r, c) = func(this->operator()(r, c) , rhs.operator()(r, c));
        }
    }
    return result;
}

template <typename T>
void Matrix<T>::elementByElementOp(const Matrix<T> &rhs, std::function<T(T,T)> func)
{
    if (rhs._rows != _rows || rhs._cols != _cols) {
        throw std::length_error("Matrix dimensions must agree.");
    }
    
    for (uint c = 0; c < _cols; ++c) {
        for (uint r = 0; r < _rows; ++r) {
            this->operator()(r, c) = func(this->operator()(r, c) , rhs.operator()(r, c));
        }
    }
}

template <typename T>
Matrix<T> Matrix<T>::matrixMultiplication(const Matrix<T> &rhs) const
{
    if (_cols != rhs._rows) {
        throw std::length_error("Inner matrix dimensions must agree.");
    }
    
    /*Multiplying sizes 'n x m' by 'm x p', resulting in an n x p Matrix*/
    Matrix<T> result(_rows, rhs._cols);
    for (uint n = 0; n < _rows; ++n) {
        for (uint p = 0; p < rhs._cols; ++p) {
            T sum = T();
            for (uint m = 0; m < _cols; ++m) {
                sum += this->operator()(n , m) * rhs(m, p);
            }
            result(n, p) = sum;
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
{
    return elementByElementOp(rhs, std::plus<T>());
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
{
    return elementByElementOp(rhs, std::minus<T>());
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    elementByElementOp(rhs, std::plus<T>());
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    elementByElementOp(rhs, std::minus<T>());
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const
{
    return matrixMultiplication(rhs);
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs)
{
    *this = matrixMultiplication(rhs);
    return *this;
}

//template <typename T>
//Matrix<T> Matrix<T>::transpose() const {
//    return Matrix<T>(0, 0);
//}

/*//////////////////////Matrix/Scalar operations//////////////////////*/

template <typename T>
Matrix<T> Matrix<T>::scalarOperation(const T& rhs, std::function<T(T,T)> func) const
{
    Matrix<T> result = Matrix(*this);
    
    for (uint c = 0; c < _cols; ++c) {
        for (uint r = 0; r < _rows; ++r) {
            result(r, c) = func(this->operator()(r, c) , rhs);
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T &rhs) const
{
    return scalarOperation(rhs, std::plus<T>());
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const T &rhs) const
{
    return scalarOperation(rhs, std::minus<T>());
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &rhs) const
{
    return scalarOperation(rhs, std::multiplies<T>());
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &rhs) const
{
    return scalarOperation(rhs, std::divides<T>());
}


///*//////////////////////Matrix/Vector operations//////////////////////*/

template <typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T> &rhs) const
{
    if (_cols != rhs.size()) {
        throw std::length_error("Vector dimensions must agree.");
    }
    /*Multiplying sizes 'n x m' by 'm x 1', resulting in an n x 1 vector*/
    std::vector<T> result{};
    for (uint n = 0; n < _rows; ++n) {
        for (uint p = 0; p < 1; ++p) {
            T sum = T();
            for (uint m = 0; m < _cols; ++m) {
                sum += this->operator()(n , m) * rhs.at(m);
            }
            result.push_back(sum);
        }
    }
    return result;
}

template <typename T>
std::vector<T> Matrix<T>::diag_vec() const
{
    std::vector<T> diag{};
    for (uint c = 0; c < _cols; ++c) {
        for (uint r = 0; r < _rows; ++r) {
            if (c == r) diag.push_back(this->operator()(r, c));
        }
    }
    return diag;
}


/*//////////////////////Element Access functions//////////////////////*/

template <typename T>
T &Matrix<T>::at(const size_t &row, const size_t &col) {
    return _mat.at(col).at(row);
}

template <typename T>
const T &Matrix<T>::at(const size_t &row, const size_t &col) const {
    return _mat.at(col).at(row);
}

template <typename T>
T &Matrix<T>::operator()(const size_t &row, const size_t &col) {
    return _mat[col].operator[](row);
}

template <typename T>
const T &Matrix<T>::operator()(const size_t &row, const size_t &col) const {
    return _mat[col].operator[](row);
}

/*//////////////////////Access row and column sizes//////////////////////*/

template <typename T>
size_t Matrix<T>::getRows() const {
    return _rows;
}

template <typename T>
size_t Matrix<T>::getCols() const {
    return _cols;
}


/*//////////////////////Printing//////////////////////*/

template <typename T>
std::string Matrix<T>::toString() const
{
    std::ostringstream sout;
    sout << "{ ";
    for (uint r = 0; r < _rows; ++r) {
        sout << "{";
        for (uint c = 0; c < _cols; ++c) {
            sout << " " << this->at(r, c);
            if (c != _cols - 1) { sout << ","; }
        }
        sout << " } ";
    }
    sout << "}";
    return sout.str();
}



/*//////////////////////Iterators//////////////////////*/

//template <typename T>
//typename Matrix<T>::iterator Matrix<T>::begin() {
//    return &this->operator()(0, 0);
//}
//
//template <typename T>
//typename Matrix<T>::iterator Matrix<T>::end() {
//    return &this->operator()(_rows, _cols);
//}
//
//template <typename T>
//typename Matrix<T>::const_iterator Matrix<T>::begin() const {
//    return &this->operator()(0, 0);
//}
//
//template <typename T>
//typename Matrix<T>::const_iterator Matrix<T>::end() const {
//    return &this->operator()(_rows, _cols);
//}

#endif
