/*
    Alex Kleb
    NERS 570
    
    Matrix Class Header
*/
#ifndef AKLEB_MATRIX_H
#define AKLEB_MATRIX_H

#define TYPE int

typedef struct Matrix{
    TYPE *arr; 
    unsigned n, m;
} Matrix;

typedef Matrix* p_Matrix;

void Matrix_init(p_Matrix *pp_Matrix, unsigned n, unsigned m);

void Matrix_destroy(p_Matrix *pp_Matrix);

#endif