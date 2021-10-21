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

    Matrix<D_TYPE> mat(2, 3);
    Matrix<D_TYPE> mat2(3, 2);
    Matrix<D_TYPE> mat3(2, 2);
    D_TYPE values[2][3] = {{1, 2, 3}, {4, 5, 6}};
    D_TYPE values2[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    D_TYPE correct[2][2] = {{22, 28}, {49, 64}};
    for(i = 0; i < 2; i++){
        mat.setRow(i, values[i]);
        mat3.setRow(i, correct[i]);
    }//for
    for(i = 0; i < 3; i++){
        mat2.setRow(i, values[i]);
    }//for
    Matrix<D_TYPE> multiplied = mat * mat2;

    if(!multiplied.equal(&mat3, static_cast<D_TYPE>(0.0000001))) return 1;

    return 0;

} //main
