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
    D_TYPE values[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            mat.setVal(i, j, values[i][j]);
        } //for
    } //for

    Matrix<D_TYPE> mat2(mat);
    if(!mat.equal(&mat2, static_cast<D_TYPE>(0))) return 1;

    mat2.setVal(0, 0, 4);
    if(mat.equal(&mat2, static_cast<D_TYPE>(0))) return 1;
    
    return 0;

} //main
