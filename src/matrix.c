/*
    Alex Kleb
    NERS 570
    
    Matrix Class
*/

#include <stdlib.h>
#cmakedefine HEADER_INCLUDE ${HEADER_INCLUDE}
#ifndef HEADER_INCLUDE
#include "matrix.h"
#endif

// -----------------------
//  MATRIX INITIALIZATION
// -----------------------

Matrix_init{
    unsigned i;

    *pp_m = malloc(sizeof(Matrix));

    (*pp_m)->m = m;
    (*pp_m)->n = n;

    (*pp_m)->arr = malloc(sizeof(TYPE)*n*m);

    for (i = 0; i < n*m; ++i) (*pp_m)->arr[i] = 0;

    return;
} //Matrix_init

//void Matrix_copy(p_Matrix *pp_m, const p_Matrix p_m){

} //Matrix_init

Matrix_destroy{
    free((*pp_m)->arr);
    free(*pp_m);

    *pp_m = NULL;

    return;
} // Matrix_destroy

// ---------------
//  MATRIX ACCESS
// ---------------

// void Matrix_get_val(const p_Matrix p_m, const unsigned i, const unsigned j, void *val){

// } // Matrix_get_val

// void Matrix_get_row(const p_Matrix p_m, const unsigned i, void *row){

// } //Matrix_get_row

// void Matrix_get_col(const p_Matrix p_m, const unsigned j, void *col){

// } //Matrix_get_col

// void Matrix_set_val(p_Matrix p_m, const unsigned i, const unsigned j, const void *val){

// } //Matrix_set_val

// void Matrix_set_row(p_Matrix p_m, const unsigned i, const void *val){

// } //Matrix_set_row

// void Matrix_set_col(p_Matrix p_m, const unsigned j, const void *val){

// } //Matrix_set_col

// // -------------
// //  MATRIX MATH
// // -------------

// void Matrix_add_val(p_Matrix p_m, const void *val){

// } //Matrix_add

// p_Matrix Matrix_add_mat(const p_Matrix p_m1, const p_Matrix p_m2){

//     return NULL;
// } //Matrix_add

// void Matrix_iadd_mat(p_Matrix p_m1, const p_Matrix p_m2){

// } //Matrix_iadd_mat

// p_Matrix Matrix_multiply(const p_Matrix p_m1, const p_Matrix p_m2){

//     return NULL;
// } //Matrix_multiply

// p_Matrix Matrix_transpose(const p_Matrix p_m){

//     return NULL;
// } //Matrix_transpose

// void Matrix_itranspose(p_Matrix p_m){

// } //Matrix_itranspose

// // -----------------
// //  MATRIX BOOLEANS
// // -----------------

// int Matrix_equal(p_Matrix p_m1, p_Matrix p_m2, void *tol){

//     return 0;
// } //Matrix_equal