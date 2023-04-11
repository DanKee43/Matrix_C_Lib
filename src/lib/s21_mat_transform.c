#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res_code = 1;
  if (!is_null(A)) {
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

  if (is_null(A)) {
    res_code = 1;
  } else if (A->columns != A->rows) {
    res_code = 2;
  } else {
    int size = A->rows;
    s21_create_matrix(size, size, result);

    matrix_t M;
    s21_create_matrix(size - 1, size - 1, &M);
    double minor_det;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        minor_det = 0.0;
        get_Minor(A, size, i, j, &M);
        s21_determinant(&M, &minor_det);
        result->matrix[i][j] = pow(-1, (i + j)) * minor_det;
      }
    }
    s21_remove_matrix(&M);
  }

  return res_code;
}

int s21_determinant(matrix_t *A, double *result) {
  int res_code = 0;

  if (is_null(A)) {
    res_code = 1;
  } else if (A->columns != A->rows) {
    res_code = 2;
  } else {
    if (A->rows == 1) {
      *result += A->matrix[0][0];
    } else if (A->rows == 2) {
      *result +=
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      for (int i = 0; i < A->columns; i++) {
        double det = 0.0;
        // Если элемент равен 0, то не ищем определитель его минора
        if (fabs(A->matrix[0][i]) > EPS) {
          matrix_t M;
          s21_create_matrix(A->rows - 1, A->columns - 1, &M);
          get_Minor(A, A->rows, 0, i, &M);
          s21_determinant(&M, &det);
          *result += pow(-1, i) * A->matrix[0][i] * det;
          s21_remove_matrix(&M);
        }
      }
    }
  }
  return res_code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res_code = 0;

  double A_det = 0.0;
  int flag = s21_determinant(A, &A_det);
  if (flag == 1) {
    res_code = 1;
  } else if (flag == 2 || fabs(A_det) <= EPS) {
    res_code = 2;
  } else {
    // s21_create_matrix(A->rows, A->columns, result);
    matrix_t tmp;
    s21_calc_complements(A, &tmp);
    matrix_t tmp_t;
    s21_transpose(&tmp, &tmp_t);
    s21_mult_number(&tmp_t, 1 / A_det, result);

    s21_remove_matrix(&tmp);
    s21_remove_matrix(&tmp_t);
  }
  return res_code;
}