/*
    Alex Kleb

    Test to check Matrix initialization
*/

#include "matrix.hpp"

#ifndef D_TYPE
#define D_TYPE int
#endif

int main(){

    int i, j, n = 2, m = 2;

    Matrix<D_TYPE> mat(n, m);
    Matrix<D_TYPE> mat2(m, n);
    D_TYPE values[2][2] = {{1, 2}, {3, 4}};
    D_TYPE correct[2][2] = {{1, 3}, {2, 4}};
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            mat.setVal(i, j, values[i][j]);
        } //for
    }//for
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            mat2.setVal(i, j, correct[i][j]);
        } //for
    } //for
    mat.itranspose();

    if(!mat2.equal(&mat, static_cast<D_TYPE>(0))) return 1;

    return 0;

} //main
