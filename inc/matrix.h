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

// -----------------------
//  MATRIX INITIALIZATION
// -----------------------

/*
    Function : Matrix_init
        Initializes a matrix to zeros of size n by m.
        
        REQUIRES MATCHING DESTROY

    Parameters
    ----------
    pp_m : a pointer to a p_Matrix to initiialize
    n    : the number of rows
    m    : the number of columns

    Returns
    -------
    void
*/
void Matrix_init(p_Matrix *pp_m, const unsigned n, const unsigned m);

/*
    Function : Matrix_destory
        Destroys a matrix

    Parameters
    ----------
    pp_m : a pointer to the p_Matrix to destroy
void Matrix_destroy(p_Matrix *pp_m);

void Matrix_set_val(p_Matrix p_m, const unsigned i, const unsigned j, const TYPE val);

void Matrix_set_row(p_Matrix p_m, const unsigned i, const TYPE *val);

void Matrix_set_col(p_Matrix p_m, const unsigned j, const TYPE *val);

// -------------
//  MATRIX MATH
// -------------

void Matrix_add(p_Matrix p_m, const TYPE val);

p_Matrix Matrix_add(const p_Matrix p_m1, const p_Matrix p_m2);

void Matrix_add_inplace(p_Matrix p_m1, const p_Matrix p_m2);

p_Matrix Matrix_multiply(const p_Matrix p_m1, const p_Matrix p_m2);

p_Matrix Matrix_transpose(const p_Matrix p_m);

void Matrix_transpose_inplace(p_Matrix p_m);

// -----------------
//  MATRIX BOOLEANS
// -----------------

int Matrix_equal(p_Matrix p_m1, p_Matrix p_m2);

#endif