/*
    Alex Kleb

    Test to check Matrix initialization
*/

#include "matrix.hpp"

#ifndef D_TYPE
#define D_TYPE int
#endif

int main(){

    int i, j, n = 3, m = 2;
    D_TYPE val = 2;
    D_TYPE set = -2;

    Matrix<D_TYPE> mat(n, m);

    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            mat.setVal(i, j, set);
            mat.getVal(i, j, &val);
            if (val != -2) return 1;
            val = 0;
        } //for
    } //for

    return 0;

} //main
