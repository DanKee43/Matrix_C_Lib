#include "s21_matrix.h"


int s21_transpose(matrix_t *A, matrix_t *result) {
    int res_code = 1;
    if(!is_null(A)) {
        res_code = 0;
        s21_create_matrix(A->columns, A->rows, result);
        for (int i = 0; i < result->rows; ++i) {
            for (int j = 0; j < result->columns; ++j) {
                result->matrix[i][j] = A->matrix[j][i];
            }
        }
    }

    return res_code;
}


int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int res_code = 0;

    return res_code;
}


int s21_determinant(matrix_t *A, double *result) {
    int res_code = 0;

    return res_code;
}


int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int res_code = 0;

    return res_code;
}