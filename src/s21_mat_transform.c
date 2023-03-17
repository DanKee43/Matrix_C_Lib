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
    
    // mats_print(1, A);
    if(is_null(A)) {
        res_code = 1;
    } else if(A->columns != A->rows) {
        res_code = 2;
    } else {

        if(A->rows == 1) { 
            *result +=  A->matrix[0][0];
        } else if (A->rows == 2) {
            *result +=  A->matrix[0][0]*A->matrix[1][1] - A->matrix[0][1]*A->matrix[1][0];
        } else {
    
            for (int i = 0; i < A->columns; i++) {
                // Если элемент равен 0, то не ищем определитель его минора
                if(fabs(A->matrix[0][i]) > EPS) {
                    matrix_t M;
                    s21_create_matrix(A->rows-1, A->columns-1, &M);
                    getMinor(A, A->rows, i, &M); 
                    *result += pow(-1, i) * s21_determinant(&M, result);
                    s21_remove_matrix(&M);
                }
            }
        }

    }
    return res_code;
}


int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int res_code = 0;

    return res_code;
}