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
    Function : Matrix_init
        A copy constructor that intializes pp_m to p_m

        REQUIRES MATCHING DESTROY
    
    Parameters
    ----------
    pp_m : a pointer to a p_Matrix to copy the Matrix to
    p_m  : the matrix to copy

    Returns
    -------
    void
*/
void Matrix_init(p_Matrix *pp_m, const p_Matrix p_m);

/*
    Function : Matrix_destory
        Destroys a matrix

    Parameters
    ----------
    pp_m : a pointer to the p_Matrix to destroy

    Returns
    -------
    void
*/
void Matrix_destroy(p_Matrix *pp_m);

/*
    Function : Matrix_set_val
        Sets the value in matrix p_m at location [i, j] to val
    
    Parameters
    ----------
    p_m : the matrix to modify
    i   : the row index
    j   : the column index
    val : the value to set

    Returns
    -------
    void
*/
void Matrix_set_val(p_Matrix p_m, const unsigned i, const unsigned j, const TYPE val);

/*
    Function : Matrix_set_row
        sets the values in row i to match the values in val

    Parameters
    ----------
    p_m : matrix to modify
    i   : row to change
    val : new row to insert, must be of length p_m->m

    Returns
    -------
    void
*/
void Matrix_set_row(p_Matrix p_m, const unsigned i, const TYPE *val);

/*
    Function : Matrix_set_col
        sets the values in column j to match the values in val.


    Parameters
    ----------
    p_m : the matrix to modify
    j   : the column to replace
    val : the new row to add, must be of length p_m->n

    Returns
    -------
    void
*/
void Matrix_set_col(p_Matrix p_m, const unsigned j, const TYPE *val);

// -------------
//  MATRIX MATH
// -------------

/*
    Function : Matrix_add
        Adds the value in val to every element in p_m

    Parameters
    ----------
    p_m : matrix to modify
    val : value to add

    Returns
    -------
    void
*/
void Matrix_add(p_Matrix p_m, const TYPE val);

/*
    Function : Matrix_add
        Allocates a new matrix and initializes each value to p_m1[i,j] + p_m2[i,j].

        REQUIRES MATCHING DESTROY
    
    Parameters
    ----------
    p_m1 : first matrix to add
    p_m2 : second matrix to add

    Returns
    -------
    A new matrix with value at [i,j] = p_m1[i,j] + p_m2[i,j]
*/
p_Matrix Matrix_add(const p_Matrix p_m1, const p_Matrix p_m2);

/*
    Function : Matrix_add_inplace
        Preforms elementwise addition between p_m1 and p_m2, storing them in p_m1

    Parameters
    ----------
    p_m1 : matrix to modify
    p_m2 : matrix to add elementwise to p_m1

    Returns
    -------
    void
*/
void Matrix_add_inplace(p_Matrix p_m1, const p_Matrix p_m2);

/*
    Function : Matrix_multiply
        Allocates a new matrix with values set to the result of p_m1 x p_m2
        p_m1-> must equal p_m2->n

        REQUIRES MATCHING DESTROY

    Parameters
    ----------
    p_m1 : matrix on the left
    p_m2 : matrix on the right

    Returns
    -------
    A new matrix of size p_m1->n by p_m2->m created by multiplying p_m1 x p_m2
*/
p_Matrix Matrix_multiply(const p_Matrix p_m1, const p_Matrix p_m2);

/*
    Function : Matrix_transpose
        Allocates a new matrix with values set to the result of p_m^T

        REQUIRES MATCHING DESTROY
    
    Parameters
    ----------
    p_m : matrix to return the transpose of

    Returns
    -------
    the result of the matrix transpose
*/
p_Matrix Matrix_transpose(const p_Matrix p_m);

/*
    Function Matrix_transpose_inplace
        Preforms a matrix tranpose on a square matrix in place.

    Parameters
    ----------
    p_m : matrix to transpose, must be square

    Returns
    -------
    void
*/
void Matrix_transpose_inplace(p_Matrix p_m);

// -----------------
//  MATRIX BOOLEANS
// -----------------

/*
    Function : Matrix_equal
        Checks if p_m1 and p_m2 are equal within the given absolute tolerance
    
    Parameters
    ----------
    p_m1 : first matrix
    p_m2 : second matrix
    tol  : the absolute tolerance between the two matricies

    Returns
    -------
    0 if the Matricies differ and 1 if they are identical
*/
int Matrix_equal(p_Matrix p_m1, p_Matrix p_m2, TYPE tol);

#endif