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
    arr = new T[mat.n*mat.m];
    n = mat.n;
    m = mat.m;

    for(unsigned i = 0; i < n*m; ++i) arr[i] = mat.arr[i];

    return;
} //Matrix

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

}

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