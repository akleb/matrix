/*
    Alex Kleb
    NERS 570
    
    Matrix Class Header
*/
#ifndef AKLEB_MATRIX_H
#define AKLEB_MATRIX_H

template <typename T>
class Matrix{
public:
    T *arr; 
    unsigned n, m;

    // -----------------------
    //  MATRIX INITIALIZATION
    // -----------------------

    /*
        Function : Matrix_init
            Initializes a matrix to zeros of size n by m.
            
            REQUIRES MATCHING DESTROY

        Parameters
        ----------
        n    : the number of rows
        m    : the number of columns

        Returns
        -------
        constructor
    */
    Matrix(const unsigned n_, const unsigned m_);

    /*
        Function : Matrix_copy
            A copy constructor that intializes pp_m to p_m

            REQUIRES MATCHING DESTROY
        
        Parameters
        ----------
        p_m  : the matrix to copy

        Returns
        -------
        constructor
    */
    Matrix(const Matrix &mat);

    /*
        Function : Matrix_destory
            Destroys a matrix

        Returns
        -------
        destructor
    */
    ~Matrix();

    /*
        Function : setVal
            Sets the value in matrix at location [i, j] to val
        
        Parameters
        ----------
        i   : the row index
        j   : the column index
        val : pointer to the value to set

        Returns
        -------
        void
    */
    void setVal(const unsigned i, const unsigned j, const T val);

    /*
        Function : setRow
            sets the values in row i to match the values in val

        Parameters
        ----------
        i   : row to change
        val : new row to insert, must be of length p_m->m

        Returns
        -------
        void
    */
    void setRow(const unsigned i, const T *val);

    /*
        Function : setCol
            sets the values in column j to match the values in val.

        Parameters
        ----------
        j   : the column to replace
        val : the new row to add, must be of length p_m->n

        Returns
        -------
        void
    */
    void setCol(const unsigned j, const void *val);

    // -------------
    //  MATRIX MATH
    // -------------

    /*
        Function : Matrix_transpose
            Allocates a new matrix with values set to the result of p_m^T

            REQUIRES MATCHING DESTROY
        
        Returns
        -------
        the result of the matrix transpose
    */
    Matrix<T> transpose();

    /*
        Function itranspose
            Preforms a matrix tranpose on a square matrix in-place.

        Returns
        -------
        void
    */
    void itranspose();

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
        tol  : pointer to the absolute tolerance between the two matricies

        Returns
        -------
        returns true if matrices are identical
    */
    bool Matrix_equal(const Matrix *p_m, const T tol);
};

#endif