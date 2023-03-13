#include <stdio.h>
#include "s21_matrix.h"

int main() {

    matrix_t A;
    matrix_t B;
    matrix_t C;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(2, 2, &B);
    s21_create_matrix(2, 4, &C);
    mats_print(3, &A, &B, &C);

    return 0;
}