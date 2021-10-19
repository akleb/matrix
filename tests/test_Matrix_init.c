/*
    Alex Kleb

    Test to check Matrix initialization
*/

#include <assert.h>
#include "matrix.h"

int main(){

    p_Matrix p_m;
    int i, j, n = 3, m = 3;

    Matrix_init(&p_m, n, m, D_TYPE);

    if(p_m->m != m) return 1;
    if(p_m->n != n) return 1;
    if(p_m->t != D_TYPE) return 1;

    Matrix_destroy(&p_m);

    if(p_m) return 1;

    return 0;

} //main
