#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int res_code = (rows <= 0 || columns <= 0) ? 1 : 0;
    if (!res_code) {
        result->rows = rows;
        result->columns = columns;

        result->matrix = (double**)malloc(rows * sizeof(double*) );
        for (int i = 0; i < rows; ++i) {
            result->matrix[i] = (double*)calloc(columns, sizeof(double) );
        }
    }

    return res_code;
}


void s21_remove_matrix(matrix_t *A) {
    if (A->matrix) {
        for (int i = 0; i < A->rows; ++i) {
            free(A->matrix[i]);
        }
        free(A->matrix);
        A->rows = 0;
        A->columns = 0;
    }
}