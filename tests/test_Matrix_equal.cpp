/*
    Alex Kleb

    Test to check Matrix initialization
*/

#include "matrix.hpp"

#ifndef D_TYPE
#define D_TYPE int
#endif

int main(){

    int i, j;
    Matrix<D_TYPE> mat1(2, 2);
    Matrix<D_TYPE> mat2(2, 2);
    Matrix<D_TYPE> mat3(3, 2);
    D_TYPE values[2][2] = {{1, 2}, {3, 4}};
    D_TYPE values3[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            mat1.setVal(i, j, values[i][j]);
            mat2.setVal(i, j, values[i][j]);
        } //for
    } //for
    for(i = 0; i < 3; i++){
        for(j = 0; j < 2; j++){
            mat3.setVal(i, j, values3[i][j]);
        } //for
    } //for

    if(!mat1.equal(&mat2, static_cast<D_TYPE>(0))) return 1;
    if(mat1.equal(&mat3, static_cast<D_TYPE>(0))) return 1;
    
    return 0;

} //main
