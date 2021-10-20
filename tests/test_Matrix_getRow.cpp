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
    D_TYPE val[2];
    D_TYPE set[2] = {-2, 4};

    Matrix<D_TYPE> mat(n, m);

    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            mat.setVal(i, j, set[j]);
        } //for
        mat.getRow(i, val);
        for(j = 0; j < m; ++j){
            if (val[j] != set[j]) return 1;
        }
    } //for

    return 0;

} //main
