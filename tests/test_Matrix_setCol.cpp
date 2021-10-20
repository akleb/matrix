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
    D_TYPE set[3] = {-2, 4, 10};

    Matrix<D_TYPE> mat(n, m);

    for(j = 0; j < m; ++j){
        mat.setCol(j, set);
        for(i = 0; i < n; ++i){
            mat.getVal(i, j, &val);
            if (val != set[i]) return 1;
        } //for
    } //for

    return 0;

} //main
