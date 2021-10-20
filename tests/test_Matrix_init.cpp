/*
    Alex Kleb

    Test to check Matrix initialization
*/

#include <assert.h>
#include "matrix.hpp"

#ifndef D_TYPE
#define D_TYPE int
#endif

int main(){

    int i, j, n = 3, m = 2;
    Matrix<D_TYPE> mat(n, m);

    if(mat.m != m) return 1;
    if(mat.n != n) return 1;

    return 0;

} //main
