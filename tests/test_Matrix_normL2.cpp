/*
    Alex Kleb

    Test to check Matrix initialization
*/

#include "matrix.hpp"
#include <cmath>
#include <stdlib.h>

#ifndef D_TYPE
#define D_TYPE int
#endif

int main(){

    int i, j, n = 3, m = 2;
    Matrix<D_TYPE> mat(n, m);
    D_TYPE values[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for (unsigned i = 0; i < 3; ++i){
        mat.setRow(i, values[i]);
    } //for

    if(abs(sqrt(91)  - mat.normL2()) > 0.000001) return 1;

    return 0;

} //main
