
#include <check.h>

#include "s21_matrix.h"

START_TEST(s21_create_matrix_1) {
  for (int rows = -100, columns = -100; rows < 100 || columns < 100;
       rows++, columns++) {
    matrix_t A = {0};
    if (rows <= 0 || columns <= 0) {
      ck_assert_int_eq(s21_create_matrix(rows, columns, &A), 1);
      s21_remove_matrix(&A);
    } else {
      ck_assert_int_eq(s21_create_matrix(rows, columns, &A), 0);
      s21_remove_matrix(&A);
    }
    // s21_remove_matrix(&A);
  }
}
END_TEST

START_TEST(s21_create_matrix_2) {
  for (int rows = 100, columns = -100; columns < 1000; rows++, columns *= -3) {
    matrix_t A = {0};
    if (rows <= 0 || columns <= 0) {
      ck_assert_int_eq(s21_create_matrix(rows, columns, &A), 1);
      s21_remove_matrix(&A);
    } else {
      ck_assert_int_eq(s21_create_matrix(rows, columns, &A), 0);
      s21_remove_matrix(&A);
    }
    // s21_remove_matrix(&A);
  }
}
END_TEST

START_TEST(s21_create_matrix_3) {
  for (int rows = -10, columns = 10; rows < 100; rows++, columns++) {
    matrix_t A = {0};
    if (rows <= 0 || columns <= 0) {
      ck_assert_int_eq(s21_create_matrix(rows, columns, &A), 1);
      s21_remove_matrix(&A);
    } else {
      ck_assert_int_eq(s21_create_matrix(rows, columns, &A), 0);
      s21_remove_matrix(&A);
    }
    // s21_remove_matrix(&A);
  }
}
END_TEST

START_TEST(s21_remove_matrix_1) {
  matrix_t A = {0};
  s21_create_matrix(100, 100, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);

  // test s21_eq_matrix
}
END_TEST

START_TEST(s21_eq_matrix_1) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 4.12345678;
  A->matrix[1][0] = 7;
  A->matrix[1][1] = 13;
  s21_create_matrix(2, 2, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4.12345679;
  B->matrix[1][0] = 7;
  B->matrix[1][1] = 13.0000001;
  ck_assert_int_eq(s21_eq_matrix(A, B), SUCCESS);
  s21_remove_matrix(A);
  s21_remove_matrix(B);
  free(A);
  free(B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 64;
  A->matrix[0][1] = 13;
  A->matrix[1][0] = 7;
  A->matrix[1][1] = 23;
  s21_create_matrix(2, 2, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4;
  B->matrix[0][0] = 7;
  B->matrix[1][1] = 13;
  ck_assert_int_eq(s21_eq_matrix(A, B), FAILURE);
  s21_remove_matrix(A);
  s21_remove_matrix(B);
  free(A);
  free(B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 3, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 4;
  A->matrix[0][2] = 7;
  A->matrix[1][0] = 13;
  A->matrix[1][1] = 13;
  A->matrix[1][2] = 13;
  s21_create_matrix(3, 2, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4;
  B->matrix[1][0] = 7;
  B->matrix[1][1] = 13;
  B->matrix[2][0] = 13;
  B->matrix[2][1] = 13;
  ck_assert_int_eq(s21_eq_matrix(A, B), FAILURE);
  s21_remove_matrix(A);
  s21_remove_matrix(B);
  free(A);
  free(B);

  // test s21_sum_matrix
}
END_TEST

START_TEST(s21_sum_matrix_1) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t *comparisor = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 4;
  A->matrix[1][0] = 7;
  A->matrix[1][1] = 13;
  s21_create_matrix(2, 2, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4;
  B->matrix[1][0] = 7;
  B->matrix[1][1] = 13;
  s21_create_matrix(2, 2, result);
  s21_create_matrix(2, 2, comparisor);
  comparisor->matrix[0][0] = 2;
  comparisor->matrix[0][1] = 8;
  comparisor->matrix[1][0] = 14;
  comparisor->matrix[1][1] = 26;

  s21_sum_matrix(A, B, result);
  ck_assert_int_eq(s21_eq_matrix(result, comparisor), SUCCESS);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  s21_remove_matrix(comparisor);
  free(A);
  free(B);
  free(comparisor);
  free(result);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t *comparisor = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 14;
  A->matrix[0][1] = 4;
  A->matrix[1][0] = 7;
  A->matrix[1][1] = 13;
  s21_create_matrix(2, 2, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4;
  B->matrix[1][0] = 7;
  B->matrix[1][1] = 13;
  s21_create_matrix(2, 2, result);
  s21_create_matrix(2, 2, comparisor);
  comparisor->matrix[0][0] = 2;
  comparisor->matrix[0][1] = 8;
  comparisor->matrix[1][0] = 14;
  comparisor->matrix[1][1] = 26;

  s21_sum_matrix(A, B, result);
  ck_assert_int_eq(s21_eq_matrix(result, comparisor), FAILURE);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  s21_remove_matrix(comparisor);
  free(A);
  free(B);
  free(comparisor);
  free(result);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t *comparisor = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 3, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 4;
  A->matrix[0][2] = 7;
  A->matrix[1][0] = 13;
  A->matrix[1][1] = 13;
  A->matrix[1][2] = 13;
  s21_create_matrix(3, 2, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4;
  B->matrix[1][0] = 7;
  B->matrix[1][1] = 13;
  B->matrix[2][0] = 13;
  B->matrix[2][1] = 13;
  s21_create_matrix(2, 2, result);
  s21_create_matrix(2, 2, comparisor);
  comparisor->matrix[0][0] = 2;
  comparisor->matrix[0][1] = 8;
  comparisor->matrix[1][0] = 14;
  comparisor->matrix[1][1] = 26;

  s21_sum_matrix(A, B, result);
  ck_assert_int_eq(s21_eq_matrix(result, comparisor), FAILURE);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  s21_remove_matrix(comparisor);
  free(A);
  free(B);
  free(comparisor);
  free(result);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t *comparisor = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 3, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 4;
  A->matrix[0][2] = 7;
  A->matrix[1][0] = 13;
  A->matrix[1][1] = 13;
  A->matrix[1][2] = 13;
  s21_create_matrix(2, 3, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4;
  B->matrix[0][2] = 7;
  B->matrix[1][0] = 13;
  B->matrix[1][1] = 13;
  B->matrix[1][2] = 13;
  s21_create_matrix(2, 3, result);
  s21_create_matrix(2, 3, comparisor);
  comparisor->matrix[0][0] = 2;
  comparisor->matrix[0][1] = 8;
  comparisor->matrix[0][2] = 14;
  comparisor->matrix[1][0] = 26;
  comparisor->matrix[1][1] = 26;
  comparisor->matrix[1][2] = 26;

  s21_sum_matrix(A, B, result);
  ck_assert_int_eq(s21_eq_matrix(result, comparisor), SUCCESS);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  s21_remove_matrix(comparisor);
  free(A);
  free(B);
  free(comparisor);
  free(result);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t *A = malloc(sizeof(matrix_t));
  A->rows = 2;
  A->columns = 3;
  A->matrix = NULL;
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 3, B);
  s21_create_matrix(2, 3, result);

  ck_assert_int_eq(s21_sum_matrix(A, B, result), 1);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  free(A);
  free(B);
  free(result);

  // test s21_sub_matrix
}
END_TEST

START_TEST(s21_sub_matrix_1) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t *comparisor = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 4;
  A->matrix[1][0] = 7;
  A->matrix[1][1] = 13;
  s21_create_matrix(2, 2, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4;
  B->matrix[1][0] = 7;
  B->matrix[1][1] = 13;
  s21_create_matrix(2, 2, result);
  s21_create_matrix(2, 2, comparisor);
  comparisor->matrix[0][0] = 0;
  comparisor->matrix[0][1] = 0;
  comparisor->matrix[1][0] = 0;
  comparisor->matrix[1][1] = 0;

  s21_sub_matrix(A, B, result);
  ck_assert_int_eq(s21_eq_matrix(result, comparisor), SUCCESS);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  s21_remove_matrix(comparisor);
  free(A);
  free(B);
  free(comparisor);
  free(result);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t *comparisor = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 4;
  A->matrix[1][0] = 7;
  A->matrix[1][1] = 13;
  s21_create_matrix(2, 2, B);
  B->matrix[0][0] = 1;
  B->matrix[0][1] = 4;
  B->matrix[1][0] = 7;
  B->matrix[1][1] = 13;
  s21_create_matrix(2, 2, result);
  s21_create_matrix(2, 2, comparisor);
  comparisor->matrix[0][0] = 0;
  comparisor->matrix[0][1] = 0;
  comparisor->matrix[1][0] = 0;
  comparisor->matrix[1][1] = 1;

  s21_sub_matrix(A, B, result);
  ck_assert_int_eq(s21_eq_matrix(result, comparisor), FAILURE);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  s21_remove_matrix(comparisor);
  free(A);
  free(B);
  free(comparisor);
  free(result);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t *A = malloc(sizeof(matrix_t));
  A->rows = 2;
  A->columns = 3;
  A->matrix = NULL;
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));

  s21_create_matrix(2, 3, B);
  s21_create_matrix(2, 3, result);

  ck_assert_int_eq(s21_sub_matrix(A, B, result), 1);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  free(A);
  free(B);
  free(result);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));

  s21_create_matrix(3, 2, A);
  s21_create_matrix(2, 3, B);
  s21_create_matrix(2, 3, result);

  ck_assert_int_eq(s21_sub_matrix(A, B, result), 2);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  free(A);
  free(B);
  free(result);

  // test s21_mult_number
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  matrix_t A, B, result, comparisor;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &comparisor);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = -1;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = -3;
  B.matrix[1][1] = -4;

  comparisor.matrix[0][0] = 2;
  comparisor.matrix[0][1] = 4;
  comparisor.matrix[1][0] = 6;
  comparisor.matrix[1][1] = 8;

  s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &comparisor), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comparisor);
}
END_TEST

START_TEST(s21_mult_number_1) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t *comparisor = malloc(sizeof(matrix_t));
  double multiplier = 2;
  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 4;
  A->matrix[1][0] = 7;
  A->matrix[1][1] = 13;
  s21_create_matrix(2, 2, comparisor);
  comparisor->matrix[0][0] = 2;
  comparisor->matrix[0][1] = 8;
  comparisor->matrix[1][0] = 14;
  comparisor->matrix[1][1] = 26;
  s21_create_matrix(2, 2, result);
  ck_assert_int_eq(s21_mult_number(A, multiplier, result), 0);
  ck_assert_int_eq(s21_eq_matrix(result, comparisor), SUCCESS);

  s21_remove_matrix(A);
  s21_remove_matrix(result);
  s21_remove_matrix(comparisor);
  free(A);
  free(comparisor);
  free(result);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t *A = malloc(sizeof(matrix_t));
  A->rows = 2;
  A->columns = 2;
  A->matrix = NULL;
  matrix_t *result = malloc(sizeof(matrix_t));
  double multiplier = 2;
  s21_create_matrix(2, 2, result);
  ck_assert_int_eq(s21_mult_number(A, multiplier, result), 1);

  s21_remove_matrix(A);
  s21_remove_matrix(result);
  free(A);
  free(result);

  // test s21_mult_matrix
}
END_TEST

START_TEST(s21_mult_matrix_1) {
  matrix_t *A = malloc(sizeof(matrix_t));
  A->rows = 2;
  A->columns = 2;
  A->matrix = NULL;
  matrix_t *B = malloc(sizeof(matrix_t));
  s21_create_matrix(2, 2, B);
  matrix_t *result = malloc(sizeof(matrix_t));
  s21_create_matrix(2, 2, result);
  ck_assert_int_eq(s21_mult_matrix(A, B, result), 1);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  free(A);
  free(B);
  free(result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t *A = malloc(sizeof(matrix_t));
  matrix_t *B = malloc(sizeof(matrix_t));
  matrix_t *result = malloc(sizeof(matrix_t));
  matrix_t *comparisor = malloc(sizeof(matrix_t));
  s21_create_matrix(2, 2, A);
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 2;
  A->matrix[1][0] = 3;
  A->matrix[1][1] = 4;
  s21_create_matrix(2, 2, B);
  B->matrix[0][0] = 5;
  B->matrix[0][1] = 6;
  B->matrix[1][0] = 7;
  B->matrix[1][1] = 8;
  s21_create_matrix(2, 2, comparisor);
  comparisor->matrix[0][0] = 19;
  comparisor->matrix[0][1] = 22;
  comparisor->matrix[1][0] = 43;
  comparisor->matrix[1][1] = 50;
  ck_assert_int_eq(s21_mult_matrix(A, B, result), 0);
  ck_assert_int_eq(s21_eq_matrix(result, comparisor), SUCCESS);

  s21_remove_matrix(A);
  s21_remove_matrix(B);
  s21_remove_matrix(result);
  s21_remove_matrix(comparisor);
  free(A);
  free(B);
  free(comparisor);
  free(result);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A, B, result;

  s21_create_matrix(3, 2, &A);

  s21_create_matrix(3, 2, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_1) {
  matrix_t A, comparisor, result;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &comparisor);
  comparisor.matrix[0][0] = 1;
  comparisor.matrix[0][1] = 3;
  comparisor.matrix[1][0] = 2;
  comparisor.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &result);
  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &comparisor), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comparisor);
}
END_TEST

START_TEST(s21_determinant_1) {
  matrix_t *A = malloc(sizeof(matrix_t));
  s21_create_matrix(2, 2, A);
  double result = 0.0;
  double comparisor = -2.0;
  A->matrix[0][0] = 1;
  A->matrix[0][1] = 2;
  A->matrix[1][0] = 3;
  A->matrix[1][1] = 4;
  ck_assert_int_eq(s21_determinant(A, &result), 0);
  ck_assert_double_eq(result, comparisor);

  s21_remove_matrix(A);
  free(A);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t *A = malloc(sizeof(matrix_t));
  s21_create_matrix(2, 1, A);
  double result = 0.0;
  A->matrix[0][0] = 1;
  A->matrix[1][0] = 2;
  A->matrix[1][0] = 3;
  ck_assert_int_eq(s21_determinant(A, &result), 2);

  s21_remove_matrix(A);
  free(A);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t *A = malloc(sizeof(matrix_t));
  double result = 0.0;
  A->matrix = NULL;
  ck_assert_int_eq(s21_determinant(A, &result), 1);

  s21_remove_matrix(A);
  free(A);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t *A = malloc(sizeof(matrix_t));
  s21_create_matrix(1, 1, A);
  double result = 0.0;
  double comparisor = 1.0;
  A->matrix[0][0] = 1;

  ck_assert_int_eq(s21_determinant(A, &result), 0);
  ck_assert_double_eq(result, comparisor);

  s21_remove_matrix(A);
  free(A);
}
END_TEST

START_TEST(s21_determinant_5) {
  matrix_t *A = malloc(sizeof(matrix_t));
  s21_create_matrix(3, 3, A);
  double result = 0.0;
  double comparisor = 576.0;
  A->matrix[0][0] = 45;
  A->matrix[0][1] = 16;
  A->matrix[0][2] = 0;
  A->matrix[1][0] = 3;
  A->matrix[1][1] = 6;
  A->matrix[1][2] = 4;
  A->matrix[2][0] = 9;
  A->matrix[2][1] = 0;
  A->matrix[2][2] = 0;
  ck_assert_int_eq(s21_determinant(A, &result), 0);
  ck_assert_double_eq(result, comparisor);

  s21_remove_matrix(A);
  free(A);

  // test s21_calc_complements
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 3;

  double result;

  s21_determinant(&A, &result);

  ck_assert_int_eq(els_cmp(result, 6.0), SUCCESS);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_1) {
  matrix_t A, result;
  A.matrix = NULL;
  ck_assert_int_eq(s21_calc_complements(&A, &result), 1);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t A, result;

  s21_create_matrix(2, 1, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;

  ck_assert_int_eq(s21_calc_complements(&A, &result), 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t A, comparisor, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 3;

  s21_create_matrix(3, 3, &comparisor);
  comparisor.matrix[0][0] = 9;
  comparisor.matrix[0][1] = -2;
  comparisor.matrix[0][2] = -3;
  comparisor.matrix[1][0] = 3;
  comparisor.matrix[1][1] = 14;
  comparisor.matrix[1][2] = -1;
  comparisor.matrix[2][0] = -7;
  comparisor.matrix[2][1] = -18;
  comparisor.matrix[2][2] = 17;

  s21_create_matrix(3, 3, &result);
  ck_assert_int_eq(s21_calc_complements(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &comparisor), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comparisor);
}
END_TEST

START_TEST(s21_inverse_matrix_1) {
  matrix_t A, result;
  A.matrix = NULL;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 1);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t A, result;
  s21_create_matrix(2, 1, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][0] = 3;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t comparisor;
  s21_create_matrix(2, 2, &comparisor);
  comparisor.matrix[0][0] = -2.000000;
  comparisor.matrix[0][1] = 1.000000;
  comparisor.matrix[1][0] = 1.500000;
  comparisor.matrix[1][1] = -0.500000;

  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &comparisor), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comparisor);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 0;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  matrix_t A;
  matrix_t result;
  matrix_t comp;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 10;
  A.matrix[2][0] = 15;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 20;

  s21_create_matrix(3, 3, &comp);
  comp.matrix[0][0] = 0;
  comp.matrix[0][1] = -2;
  comp.matrix[0][2] = 1;
  comp.matrix[1][0] = 10;
  comp.matrix[1][1] = -5;
  comp.matrix[1][2] = 1;
  comp.matrix[2][0] = -3;
  comp.matrix[2][1] = 3;
  comp.matrix[2][2] = -1;

  s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &comp), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&comp);
  s21_remove_matrix(&result);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_create_matrix_1);
  tcase_add_test(tc1_1, s21_create_matrix_2);
  tcase_add_test(tc1_1, s21_create_matrix_3);
  tcase_add_test(tc1_1, s21_remove_matrix_1);
  tcase_add_test(tc1_1, s21_eq_matrix_1);
  tcase_add_test(tc1_1, s21_eq_matrix_2);
  tcase_add_test(tc1_1, s21_eq_matrix_3);
  tcase_add_test(tc1_1, s21_sum_matrix_1);
  tcase_add_test(tc1_1, s21_sum_matrix_2);
  tcase_add_test(tc1_1, s21_sum_matrix_3);
  tcase_add_test(tc1_1, s21_sum_matrix_4);
  tcase_add_test(tc1_1, s21_sum_matrix_5);
  tcase_add_test(tc1_1, s21_sub_matrix_1);
  tcase_add_test(tc1_1, s21_sub_matrix_2);
  tcase_add_test(tc1_1, s21_sub_matrix_3);
  tcase_add_test(tc1_1, s21_sub_matrix_4);
  tcase_add_test(tc1_1, s21_sub_matrix_5);
  tcase_add_test(tc1_1, s21_mult_number_1);
  tcase_add_test(tc1_1, s21_mult_number_2);
  tcase_add_test(tc1_1, s21_mult_matrix_1);
  tcase_add_test(tc1_1, s21_mult_matrix_2);
  tcase_add_test(tc1_1, s21_mult_matrix_3);
  tcase_add_test(tc1_1, s21_transpose_1);
  tcase_add_test(tc1_1, s21_determinant_1);
  tcase_add_test(tc1_1, s21_determinant_2);
  tcase_add_test(tc1_1, s21_determinant_3);
  tcase_add_test(tc1_1, s21_determinant_4);
  tcase_add_test(tc1_1, s21_determinant_5);
  tcase_add_test(tc1_1, s21_determinant_6);
  tcase_add_test(tc1_1, s21_calc_complements_1);
  tcase_add_test(tc1_1, s21_calc_complements_2);
  tcase_add_test(tc1_1, s21_calc_complements_3);
  tcase_add_test(tc1_1, s21_inverse_matrix_1);
  tcase_add_test(tc1_1, s21_inverse_matrix_2);
  tcase_add_test(tc1_1, s21_inverse_matrix_3);
  tcase_add_test(tc1_1, s21_inverse_matrix_4);
  tcase_add_test(tc1_1, s21_inverse_matrix_5);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
