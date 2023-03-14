#include <stdio.h>
#include "s21_matrix.h"

int main() {

    matrix_t A;
    s21_create_matrix(3, 2, &A);
//    A.matrix[0][0] = 1.0;
//    A.matrix[1][0] = 2.0;
//    A.matrix[0][1] = 3.0;
//    A.matrix[1][1] = 4.0000002;
      A.matrix[0][0] = 1;
    A.matrix[0][1] = 4;
    A.matrix[1][0] = 2;
    A.matrix[1][1] = 5;
    A.matrix[2][0] = 3;
    A.matrix[2][0] = 6;

    matrix_t B;
    s21_transpose(&A, &B);

    mats_print(2, &A, &B);
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