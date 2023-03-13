#include "s21_matrix.h"
#include <stdarg.h>

int els_cmp(double a, double b) {
    return fabs(a-b) < 0.0000001;
}

int is_eq_size(matrix_t* a, matrix_t* b) {
    return (a->rows == b->rows && a->columns == b->columns);
}

int is_null(matrix_t* M) {
    return (M != NULL && M->matrix != NULL);
}

void mats_print(int num, ...) {
    matrix_t* next;

    va_list argptr;
    va_start(argptr, num);

    for (; num; num--) {
        next = va_arg(argptr, matrix_t*);

        for (int i = 0; i < next->rows; ++i) {
            for (int j = 0; j < next->columns; ++j) {
                printf("%lf ", next->matrix[i][j]);
            }
            printf("\n");
        }
    }

    va_end(argptr);
}