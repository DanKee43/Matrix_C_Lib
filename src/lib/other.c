#include <stdarg.h>

#include "../s21_matrix.h"

int els_cmp(double a, double b) { return fabs(a - b) < EPS; }

int is_eq_size(matrix_t* a, matrix_t* b) {
  return (a->rows == b->rows && a->columns == b->columns);
}

int is_null(matrix_t* M) { return (M == NULL || M->matrix == NULL); }

// void mats_print(int num, ...) {
//   matrix_t* next;

//   va_list argptr;
//   va_start(argptr, num);

//   for (; num; num--) {
//     next = va_arg(argptr, matrix_t*);

//     for (int i = 0; i < next->rows; ++i) {
//       for (int j = 0; j < next->columns; ++j) {
//         printf("%.8lf ", next->matrix[i][j]);
//       }
//       printf("\n");
//     }
//     printf("\n-------------\n");
//   }

//   va_end(argptr);
// }

double mult_vects(double* vec1, double** mat, int ind, int size) {
  double res = 0.0;
  double vec2[size];
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      vec2[j] = mat[j][ind];
    }

    res += vec1[i] * vec2[i];
  }

  return res;
}

void get_Minor(matrix_t* A, int size, int row, int col, matrix_t* B) {
  int row_shift = 0;
  int col_shift = 0;
  for (int i = 0; i < size - 1; i++) {
    if (i == row) {
      row_shift = 1;
    }
    col_shift = 0;
    for (int j = 0; j < size - 1; j++) {
      if (j == col) {
        col_shift = 1;
      }
      B->matrix[i][j] = A->matrix[i + row_shift][j + col_shift];
    }
  }
}