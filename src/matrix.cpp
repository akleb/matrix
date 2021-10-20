/*
    Alex Kleb
    NERS 570
    
    Matrix Class
*/

#include "matrix.hpp"
#include <stdlib.h>

// -----------------------
//  MATRIX INITIALIZATION
// -----------------------

template <class T>
Matrix<T>::Matrix(const unsigned n_, const unsigned m_) : m(m_), n(n_){
    arr = new T[n*m];

    for (unsigned i = 0; i < n*m; ++i) arr[i] = 0;

    return;
} //Matrix

template <class T>
Matrix<T>::Matrix(const Matrix &mat){

} //Matrix

template <class T>
Matrix<T>::~Matrix(){
    delete[] arr;
    n = 0;
    m = 0;
} //~Matrix

template <class T>
void Matrix<T>::setVal(const unsigned i, const unsigned j, const T val){

}

template <class T>
void Matrix<T>::setRow(const unsigned i, const T *val){

}

template <class T>
void Matrix<T>::setCol(const unsigned j, const void *val){

}

// -------------
//  MATRIX MATH
// -------------

template <class T>
Matrix<T> Matrix<T>::transpose(){

}

template <class T>
void Matrix<T>::itranspose(){

}

// -----------------
//  MATRIX BOOLEANS
// -----------------

template <class T>
bool Matrix<T>::Matrix_equal(const Matrix *p_m, const T tol){

}

// Specify templates to compile
template class Matrix<int>;
template class Matrix<double>; 
template class Matrix<float>;