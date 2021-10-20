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
    D_TYPE val[3];
    D_TYPE set[3] = {-2, 4, 10};

    Matrix<D_TYPE> mat(n, m);

    for(j = 0; j < m; ++j){
        for(i = 0; i < n; ++i){
            mat.setVal(i, j, set[i]);
        } //for
        mat.getCol(j, val);
        for(i = 0; i < m; ++i){
            if (val[i] != set[i]) return 1;
        }
    } //for

    return 0;

} //main
