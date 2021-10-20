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

    Matrix<D_TYPE> mat(n, m);
    Matrix<D_TYPE> mat2(m, n);
    D_TYPE values[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    D_TYPE correct[2][3] = {{1, 3, 5}, {2, 4, 6}};
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
    Matrix<D_TYPE> matT(mat.transpose());

    if(!mat2.equal(&matT, static_cast<D_TYPE>(0))) return 1;

    return 0;

} //main
