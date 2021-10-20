/*
    Alex Kleb
    NERS 570
    
    Matrix Class Header
*/
#ifndef AKLEB_MATRIX_H
#define AKLEB_MATRIX_H

#cmakedefine TYPE ${TYPE}
#ifndef TYPE
#define TYPE int
#endif

typedef struct{
    TYPE *arr;
    unsigned n, m;
    TYPE t;
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
#cmakedefine Matrix_init void Matrix_init_${TYPE}(p_Matrix *pp_m, const unsigned n, const unsigned m)
Matrix_init;

/*
    Function : Matrix_copy
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
//void Matrix_copy(p_Matrix *pp_m, const p_Matrix p_m);

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
#define Matrix_destroy void Matrix_destroy_ ## TYPE(p_Matrix *pp_m)
Matrix_destroy;

// // ---------------
// //  MATRIX ACCESS
// // ---------------

// /*  Function : Matrix_get_val
//         Gets the value in matrix p_m at location [i, j]
    
//     Parameters
//     ----------
//     p_m : The matrix to get a value from
//     i   : row index
//     j   : column index
//     val : Modified to hold the value retrieved

//     Returns
//     -------
//     void
// */
// void Matrix_get_val(const p_Matrix p_m, const unsigned i, const unsigned j, void *val);

// /*  Function : Matrix_get_row
//         Get row i from Matrix p_m 
    
//     Parameters
//     ----------
//     p_m : The matrix to get a row from
//     i   : The row index
//     row : Modified to hold the row, must be allocated beforehand to size p_m->m

//     Returns
//     -------
//     void
// */
// void Matrix_get_row(const p_Matrix p_m, const unsigned i, void *row);

// /*  Function : Matrix_get_col
//         Gets row j from Matrix p_m 
    
//     Parameters
//     ----------
//     p_m : The matrix to get a column from
//     j   : The column index
//     col : Modified to hold the column, must be allocated beforehand to size p_m->n

//     Returns
//     -------
//     void
// */
// void Matrix_get_col(const p_Matrix p_m, const unsigned j, void *col);

// /*
//     Function : Matrix_set_val
//         Sets the value in matrix p_m at location [i, j] to val
    
//     Parameters
//     ----------
//     p_m : the matrix to modify
//     i   : the row index
//     j   : the column index
//     val : pointer to the value to set

//     Returns
//     -------
//     void
// */
// void Matrix_set_val(p_Matrix p_m, const unsigned i, const unsigned j, const void *val);

// /*
//     Function : Matrix_set_row
//         sets the values in row i to match the values in val

//     Parameters
//     ----------
//     p_m : matrix to modify
//     i   : row to change
//     val : new row to insert, must be of length p_m->m

//     Returns
//     -------
//     void
// */
// void Matrix_set_row(p_Matrix p_m, const unsigned i, const void *val);

// /*
//     Function : Matrix_set_col
//         sets the values in column j to match the values in val.


//     Parameters
//     ----------
//     p_m : the matrix to modify
//     j   : the column to replace
//     val : the new row to add, must be of length p_m->n

//     Returns
//     -------
//     void
// */
// void Matrix_set_col(p_Matrix p_m, const unsigned j, const void *val);

// // -------------
// //  MATRIX MATH
// // -------------

// /*
//     Function : Matrix_add_val
//         Adds the value in val to every element in p_m

//     Parameters
//     ----------
//     p_m : matrix to modify
//     val : pointer to value to add

//     Returns
//     -------
//     void
// */
// void Matrix_add_val(p_Matrix p_m, const void *val);

// /*
//     Function : Matrix_add_mat
//         Allocates a new matrix and initializes each value to p_m1[i,j] + p_m2[i,j].

//         REQUIRES MATCHING DESTROY
    
//     Parameters
//     ----------
//     p_m1 : first matrix to add
//     p_m2 : second matrix to add

//     Returns
//     -------
//     A new matrix with value at [i,j] = p_m1[i,j] + p_m2[i,j]
// */
// p_Matrix Matrix_add_mat(const p_Matrix p_m1, const p_Matrix p_m2);

// /*
//     Function : Matrix_iadd_mat
//         Preforms elementwise addition between p_m1 and p_m2, storing them in p_m1

//     Parameters
//     ----------
//     p_m1 : matrix to modify
//     p_m2 : matrix to add elementwise to p_m1

//     Returns
//     -------
//     void
// */
// void Matrix_iadd_mat(p_Matrix p_m1, const p_Matrix p_m2);

// /*
//     Function : Matrix_multiply
//         Allocates a new matrix with values set to the result of p_m1 x p_m2
//         p_m1-> must equal p_m2->n

//         REQUIRES MATCHING DESTROY

//     Parameters
//     ----------
//     p_m1 : matrix on the left
//     p_m2 : matrix on the right

//     Returns
//     -------
//     A new matrix of size p_m1->n by p_m2->m created by multiplying p_m1 x p_m2
// */
// p_Matrix Matrix_multiply(const p_Matrix p_m1, const p_Matrix p_m2);

// /*
//     Function : Matrix_transpose
//         Allocates a new matrix with values set to the result of p_m^T

//         REQUIRES MATCHING DESTROY
    
//     Parameters
//     ----------
//     p_m : matrix to return the transpose of

//     Returns
//     -------
//     the result of the matrix transpose
// */
// p_Matrix Matrix_transpose(const p_Matrix p_m);

// /*
//     Function Matrix_itranspose
//         Preforms a matrix tranpose on a square matrix in-place.

//     Parameters
//     ----------
//     p_m : matrix to transpose, must be square

//     Returns
//     -------
//     void
// */
// void Matrix_itranspose(p_Matrix p_m);

// // -----------------
// //  MATRIX BOOLEANS
// // -----------------

// /*
//     Function : Matrix_equal
//         Checks if p_m1 and p_m2 are equal within the given absolute tolerance
    
//     Parameters
//     ----------
//     p_m1 : first matrix
//     p_m2 : second matrix
//     tol  : pointer to the absolute tolerance between the two matricies

//     Returns
//     -------
//     0 if the Matricies differ and 1 if they are identical
// */
// int Matrix_equal(p_Matrix p_m1, p_Matrix p_m2, void *tol);

#endif