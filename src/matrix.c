/*
    Alex Kleb
    NERS 570
    
    Matrix Class
*/

#include "matrix.h"
#include <stdlib.h>

// -----------------------
//  MATRIX INITIALIZATION
// -----------------------

void Matrix_init(p_Matrix *pp_m, const unsigned n, const unsigned m, const TYPE t){

    *pp_m = malloc(sizeof(Matrix));

    (*pp_m)->m = m;
    (*pp_m)->n = n;

    switch(t){
        case DOUBLE:
            (*pp_m)->arr = malloc(sizeof(double));
            break;
        case FLOAT:
            (*pp_m)->arr = malloc(sizeof(float));
            break;
        case INT:
            (*pp_m)->arr = malloc(sizeof(int));
            break;
    } //switch

    (*pp_m)->t = t;

    return;
} //Matrix_init

void Matrix_copy(p_Matrix *pp_m, const p_Matrix p_m){

} //Matrix_init

void Matrix_destroy(p_Matrix *pp_m){
    free((*pp_m)->arr);
    free(*pp_m);

    *pp_m = NULL;

    return;
} // Matrix_destroy

void Matrix_set_val(p_Matrix p_m, const unsigned i, const unsigned j, const void *val){

} //Matrix_set_val

void Matrix_set_row(p_Matrix p_m, const unsigned i, const void *val){

} //Matrix_set_row

void Matrix_set_col(p_Matrix p_m, const unsigned j, const void *val){

} //Matrix_set_col

// -------------
//  MATRIX MATH
// -------------

void Matrix_add_val(p_Matrix p_m, const void *val){

} //Matrix_add

p_Matrix Matrix_add_mat(const p_Matrix p_m1, const p_Matrix p_m2){

    return NULL;
} //Matrix_add

void Matrix_iadd_mat(p_Matrix p_m1, const p_Matrix p_m2){

} //Matrix_iadd_mat

p_Matrix Matrix_multiply(const p_Matrix p_m1, const p_Matrix p_m2){

    return NULL;
} //Matrix_multiply

p_Matrix Matrix_transpose(const p_Matrix p_m){

    return NULL;
} //Matrix_transpose

void Matrix_itranspose(p_Matrix p_m){

} //Matrix_itranspose

// -----------------
//  MATRIX BOOLEANS
// -----------------

int Matrix_equal(p_Matrix p_m1, p_Matrix p_m2, void *tol){

    return 0;
} //Matrix_equal