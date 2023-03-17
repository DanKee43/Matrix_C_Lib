#include <stdio.h>
#include "s21_matrix.h"

int main() {

    matrix_t A;
    s21_create_matrix(3, 3, &A);
    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 2.0;
    A.matrix[0][2] = 3.0;

    A.matrix[1][0] = 4.0;
    A.matrix[1][1] = 5.0;
    A.matrix[1][2] = 6.0;
    
    A.matrix[2][0] = 7.0;
    A.matrix[2][1] = 8.0;
    A.matrix[2][2] = 99.5;


    double chislo = 0;
    mats_print(1, &A);
    s21_determinant(&A, &chislo);
    printf("%.7lf\n", chislo);

//
//    matrix_t B;
//    s21_create_matrix(2, 2, &B);
//    B.matrix[0][0] = 1.0;
//    B.matrix[1][0] = 2.0;
//    B.matrix[0][1] = 3.0;
//    B.matrix[1][1] = 4.0000003;

//    matrix_t C;
//    s21_sub_matrix(&A, &B, &C);
//
//
//    mats_print(3, &A, &B, &C);
//    int l = s21_eq_matrix(&A, &B);
//    printf("\n%d\n", l);

    return 0;
}