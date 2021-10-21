/*
    Alex Kleb
    NERS 570
    
    Matrix Class
*/

#include "matrix.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

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
Matrix<T>::Matrix(const Matrix<T> &mat){
    arr = new T[mat.n*mat.m];
    n = mat.n;
    m = mat.m;

    for(unsigned i = 0; i < n*m; ++i) arr[i] = mat.arr[i];

    return;
} //Matrix

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &mat){
    n = mat.n;
    m = mat.m;

    arr = new T[n*m];
    for (unsigned i = 0; i < n; i++){
        for (unsigned j = 0; j < m; j++){
            arr[i*m + j] = mat.arr[i*m + j];
        } //for
    } //for

    return *this;
} //operator=

template <class T>
Matrix<T>::~Matrix(){
    delete[] arr;
    n = 0;
    m = 0;
} //~Matrix

// ---------------
//  MATRIX ACCESS
// ---------------

template <class T>
void Matrix<T>::getVal(const unsigned i, const unsigned j, T *val){
    *val = arr[i*m + j];
    return;
} //getVal

template <class T>
void Matrix<T>::getRow(const unsigned i, T *row){
    for (unsigned j = 0; j < m; ++j) row[j] = arr[i*m + j]; 
    return;
} //getRow

template <class T>
void Matrix<T>::getCol(const unsigned j, T *col){
    for (unsigned i = 0; i < n; ++i) col[i] = arr[i*m + j];
    return;
} //getCol

template <class T>
void Matrix<T>::setVal(const unsigned i, const unsigned j, const T val){
    arr[i*m + j] = val;
    return;
} //setVal

template <class T>
void Matrix<T>::setRow(const unsigned i, const T *row){
    for (unsigned j = 0; j < m; ++j) arr[i*m + j] = row[j];
    return;
} //setRow

template <class T>
void Matrix<T>::setCol(const unsigned j, const T *col){
    for (unsigned i = 0; i < n; ++i) arr[i*m + j] = col[i];
    return;
} //setCol

template <class T>
void Matrix<T>::print(){
    for (unsigned i = 0; i < n; i++){
        std::cout << " | ";
        for(unsigned j = 0; j < m; j++){
            std::cout << arr[i*m+j] << " ";
        } //for
        std::cout << "|\n";
    } //for

    return;
}

// -------------
//  MATRIX MATH
// -------------

template <class T>
Matrix<T> Matrix<T>::transpose(){
    Matrix<T> new_matrix(m, n);
    for(unsigned i = 0; i < n; i++){
        for(unsigned j = 0; j < m; j++){
            getVal(i, j, new_matrix.arr + (j*n + i));
        } //for
   } //for

   return new_matrix;
} //transpose

template <class T>
void Matrix<T>::itranspose(){
    if (n != m){
        printf("Error: The matrix must be square to do an inplace transpose");
        return;
    } //if

    T temp;

    for(unsigned i = 1; i < n; ++i){
        for(unsigned j = 0; j < i; ++j){
            temp = arr[i*m + j];
            arr[i*m + j] = arr[j*m +i];
            arr[j*m + i] = temp;
        } //for
    }//for

    return;
}//itranspose

template <class T>
Matrix<T> &Matrix<T>::operator*(const Matrix<T> m2){
    if(m != m2.n){
        std::cerr << "Matrix dimensions not compatabile for mulitplication: " << m << " " << m2.n <<std::endl;
        exit(1);
    } //if

    Matrix<T> new_matrix(this->n, m2.m);

    for(unsigned i = 0; i < new_matrix.n; i++){
        for(unsigned j = 0; j < new_matrix.m; j++){
            for(unsigned k = 0; k < this->m; ++k){
                new_matrix.arr[i*new_matrix.m + j] += this->arr[i*this->m + k]*m2.arr[k*m2.m + j];
            } //for
        } //for
    } //for

    *this = new_matrix;
    return *this;
}//operator*

// -----------------
//  MATRIX BOOLEANS
// -----------------

template <class T>
bool Matrix<T>::equal(const Matrix *p_m, const T tol){
    if(m != p_m->m || n != p_m->n) return false;
    for (unsigned i = 0; i < m*n; ++i){
        if(abs(arr[i] - p_m->arr[i]) > tol) return false;
    } //for

    return true;
} //equal

// Specify templates to compile
template class Matrix<int>;
template class Matrix<double>; 
template class Matrix<float>;