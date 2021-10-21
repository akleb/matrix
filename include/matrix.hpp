/*
    Alex Kleb
    NERS 570
    
    Matrix Class Header
*/
#ifndef AKLEB_MATRIX_H
#define AKLEB_MATRIX_H

template <class T>
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
        Function : operator = 
            A copy constructor that intializes matrix to p_m

        Parameters
        ----------
        p_m  : the matrix to copy

        Returns
        -------
        constructor
    */
    Matrix(const Matrix<T> &mat);  

    /*
        Function : operator = 
            A copy constructor that intializes matrix to p_m

        Parameters
        ----------
        p_m  : the matrix to copy

        Returns
        -------
        constructor
    */
    Matrix<T>& operator=(const Matrix<T> &mat);

    /*
        Function : operator=
            Assignment operator

        Parameters
        ----------
        m : the matrix to copy

        Returns
        -------
        copied matrix
    */
        
    /*
        Function : Matrix_destory
            Destroys a matrix

        Returns
        -------
        destructor
    */
    ~Matrix();

    // --------------
    //  MATRIX ACCESS
    // --------------

    /*
        Function : getVal
            Gets the value stored in the matrix at location [i j]
        
        Parameters
        ----------
        i   : the row index
        j   : the column index
        val : updated to the value stored in the matrix

        Returns
        -------
        The value stored in the array
    */
    void getVal(const unsigned i, const unsigned j, T *val);

    /*
        Function : getVal
            Returns the value stored in the matrix at location [i j]
        
        Parameters
        ----------
        i   : the row index
        row : updated to the values in row i, requires row to be preallocated to size m

        Returns
        -------
        The value stored in the array
    */
    void getRow(const unsigned i, T *row);

    /*
        Function : getVal
            Returns the value stored in the matrix at location [i j]
        
        Parameters
        ----------
        j   : the columns index
        col : updated to the values in column j, requires column to be preallocated to size n

        Returns
        -------
        void
    */
    void getCol(const unsigned j, T *col);

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
        row : new row to insert, must be of length p_m->m

        Returns
        -------
        void
    */
    void setRow(const unsigned i, const T *row);

    /*
        Function : setCol
            sets the values in column j to match the values in val.

        Parameters
        ----------
        j   : the column to replace
        col : the new row to add, must be of length p_m->n

        Returns
        -------
        void
    */
    void setCol(const unsigned j, const T *col);

    /*
        Function : print
            prints the matrix
        
        Parameters
        ----------

        Returns
        -------
        void
    */
    void print();

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

    /*
        Function : operator*
            Preforms matrix multiplication

        Parameters
        ----------
        m2 : right hand side matrix

        Returns
        -------
        Multiplied matrix
    */
    Matrix<T> &operator*(const Matrix<T> m2);

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
    bool equal(const Matrix *p_m, const T tol);
};

#endif