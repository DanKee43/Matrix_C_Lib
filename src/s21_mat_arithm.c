#include "s21_matrix.h"


// Пофиксить проверку на NULL
int s21_eq_matrix(matrix_t *A, matrix_t *B) {

    int eq_sizes = is_eq_size(A, B);

    int res_code = (eq_sizes && A->matrix != NULL
                             && B->matrix != NULL) ? SUCCESS : FAILURE;

    if(res_code) {
        for (int i = 0; i < A->rows; ++i) {
            for (int j = 0; j < A->columns; ++j) {
                if (els_cmp(A->matrix[i][j], B->matrix[i][j]) == FAILURE) {
                    res_code = FAILURE;
                }

            }
        }

    }
    return res_code;
}


int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

    int res_code = 0;

    if(is_null(A) && is_null(B)) {
        res_code = 1;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        res_code = 2;
    } else {
        res_code = s21_create_matrix(A->rows, A->columns, result);
        if (!res_code) {
            for (int i = 0; i < A->rows; ++i) {
                for (int j = 0; j < A->columns; ++j) {
                    result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                }
            }
        }

    }

    return res_code;
}


int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

    int res_code = 0;

    if(is_null(A) && is_null(B)) {
        res_code = 1;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        res_code = 2;
    } else {
        res_code = s21_create_matrix(A->rows, A->columns, result);
        if (!res_code) {
            for (int i = 0; i < A->rows; ++i) {
                for (int j = 0; j < A->columns; ++j) {
                    result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
                }
            }
        }

    }

    return res_code;
}


int s21_mult_number(matrix_t *A, double number, matrix_t *result) {

    int res_code = 0;

    if(is_null(A) && is_null(B)) {
        res_code = 1;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        res_code = 2;
    } else {
        res_code = s21_create_matrix(A->rows, A->columns, result);
        if (!res_code) {
            for (int i = 0; i < A->rows; ++i) {
                for (int j = 0; j < A->columns; ++j) {
                    result->matrix[i][j] = A->matrix[i][j] * number;
                }
            }
        }

    }

    return res_code;
}


int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

    int res_code = 0;
    if (is_null(A) && is_null(B)) {
        res_code = 1;
    } else if (A->columns != B->rows) {
        res_code = 2;
    } else {
        s21_create_matrix(A->rows, B->columns, result);



    }
}