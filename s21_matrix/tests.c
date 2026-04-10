#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

START_TEST(base_s21_create_matrix_test) {
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test_matrix = {0};
  s21_create_matrix(rows, columns, &test_matrix);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, test_matrix.matrix[i][j], 1e-06);
    }
  }
  ck_assert_int_eq(test_matrix.rows, rows);
  ck_assert_int_eq(test_matrix.columns, columns);
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(no_rows_test) {
  const int rows = 0;
  const int columns = 10;
  matrix_t test_matrix = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), 1);
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(no_columns_test) {
  const int rows = 10;
  const int columns = 0;

  matrix_t test_matrix = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), 1);
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_create_matrix_fixed_number_test) {
  matrix_t my_matrix;

  int result = s21_create_matrix(7, 7, &my_matrix);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&my_matrix);

  result = s21_create_matrix(-7, 7, &my_matrix);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&my_matrix);

  result = s21_create_matrix(-7, 0, &my_matrix);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&my_matrix);
}
END_TEST

START_TEST(s21_eq_matrix_test_1) {
  matrix_t matrix_1, matrix_2;

  s21_create_matrix(7, 7, &matrix_1);
  s21_create_matrix(7, 7, &matrix_2);
  int result = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  result = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t matrix_1, matrix_2;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(10, 10, &matrix_2);
  int result = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t matrix_1, matrix_2;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);
  matrix_1.matrix[2][3] = -7;
  int result = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t matrix_1, matrix_2;

  s21_create_matrix(8, 8, &matrix_1);
  s21_create_matrix(8, 8, &matrix_2);
  matrix_1.matrix[2][3] = -7;
  matrix_2.matrix[2][3] = -7;
  int result = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_sum_matrix_test_1) {
  matrix_t matrix_1, matrix_2, res_my, r_fixed;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);
  s21_create_matrix(5, 5, &r_fixed);
  int result = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t matrix_1, matrix_2;
  matrix_t res_my = {0};

  s21_create_matrix(2, 5, &matrix_1);
  s21_create_matrix(2, 4, &matrix_2);
  int result = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  matrix_t matrix_1, matrix_2;
  matrix_t res_my = {0};

  s21_create_matrix(5, 6, &matrix_1);
  s21_create_matrix(3, 5, &matrix_2);
  int result = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  matrix_t matrix_1, matrix_2, res_my, r_fixed;

  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  s21_create_matrix(3, 3, &r_fixed);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1.matrix[i][j] = i + j;
      r_fixed.matrix[i][j] = i + j;
    }
  }
  int result = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  matrix_t matrix_1, matrix_2, res_my, r_fixed;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &r_fixed);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
      r_fixed.matrix[i][j] = (i + j) * 2;
    }
  }
  int result = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_sub_matrix_1) {
  matrix_t matrix_1, matrix_2, res_my, r_fixed;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);
  s21_create_matrix(5, 5, &r_fixed);
  int result = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t matrix_1, matrix_2;
  matrix_t res_my = {0};

  s21_create_matrix(5, 6, &matrix_1);
  s21_create_matrix(4, 5, &matrix_2);
  int result = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_2);
  result = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  matrix_t matrix_1, matrix_2, r_fixed;
  matrix_t res_my = {0};

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &r_fixed);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      r_fixed.matrix[i][j] = i + j;
    }
  }
  int result = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_sub_matrix_4) {
  matrix_t matrix_1, matrix_2, res_my, r_fixed;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &matrix_2);
  s21_create_matrix(5, 5, &r_fixed);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
    }
  }
  int result = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_mult_number_1) {
  matrix_t matrix_1, res_my, r_fixed;

  s21_create_matrix(5, 5, &matrix_1);
  s21_create_matrix(5, 5, &r_fixed);
  int result = s21_mult_number(&matrix_1, 2, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &r_fixed);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      r_fixed.matrix[i][j] = (i + j) * (-2);
    }
  }
  result = s21_mult_number(&matrix_1, -2, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);

  s21_create_matrix(4, 4, &r_fixed);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
    }
  }
  result = s21_mult_number(&matrix_1, 0, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_my, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_mult_matrix_1) {
  matrix_t mat_1, mat_2, res_mat, r_fixed;

  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(2, 2, &r_fixed);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat_1.matrix[i][j] = i + j + 1;
      mat_2.matrix[i][j] = i + j + 1;
    }
  }
  r_fixed.matrix[0][0] = 5;
  r_fixed.matrix[0][1] = 8;
  r_fixed.matrix[1][0] = 8;
  r_fixed.matrix[1][1] = 13;
  int result = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_mat, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t mat_1, mat_2, res_mat, r_fixed;

  s21_create_matrix(3, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(3, 2, &r_fixed);
  int result = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_mat, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t mat_1, mat_2, res_mat;

  s21_create_matrix(2, 7, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  int result = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
}
END_TEST

START_TEST(test_s21_transpose) {
  matrix_t mat_1, res_mat, r_fixed;

  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &r_fixed);
  mat_1.matrix[0][0] = 1;
  mat_1.matrix[0][1] = 2;
  mat_1.matrix[1][0] = 3;
  mat_1.matrix[1][1] = 4;
  r_fixed.matrix[0][0] = 1;
  r_fixed.matrix[0][1] = 3;
  r_fixed.matrix[1][0] = 2;
  r_fixed.matrix[1][1] = 4;
  int result = s21_transpose(&mat_1, &res_mat);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_mat, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&r_fixed);

  double matrix[2][2] = {
      {1, 2},
      {3, 4},
  };
  double res[2][2] = {{1, 3}, {2, 4}};
  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &r_fixed);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat_1.matrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      r_fixed.matrix[i][j] = res[i][j];
    }
  }
  result = s21_transpose(&mat_1, &res_mat);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&res_mat, &r_fixed);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_determinant) {
  matrix_t matrix;

  s21_create_matrix(3, 3, &matrix);
  int count = 1;
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = count++;
    }
  }
  matrix.matrix[2][2] = 10;
  double res;
  int result = s21_determinant(&matrix, &res);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_calc_complements) {
  double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t matrix, r_fixed, res_my;

  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &r_fixed);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      r_fixed.matrix[i][j] = r[i][j];
    }
  }
  int result = s21_calc_complements(&matrix, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&r_fixed, &res_my);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

START_TEST(test_s21_inverse_matrix) {
  double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_t matrix, r_fixed, res_my;

  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &r_fixed);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      r_fixed.matrix[i][j] = r[i][j];
    }
  }
  int result = s21_inverse_matrix(&matrix, &res_my);
  ck_assert_int_eq(result, 0);
  result = s21_eq_matrix(&r_fixed, &res_my);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&r_fixed);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, base_s21_create_matrix_test);
  tcase_add_test(tc1_1, no_rows_test);
  tcase_add_test(tc1_1, no_columns_test);
  tcase_add_test(tc1_1, s21_create_matrix_fixed_number_test);
  tcase_add_test(tc1_1, s21_eq_matrix_test_1);
  tcase_add_test(tc1_1, s21_eq_matrix_test_2);
  tcase_add_test(tc1_1, s21_eq_matrix_test_3);
  tcase_add_test(tc1_1, s21_eq_matrix_test_4);
  tcase_add_test(tc1_1, s21_sum_matrix_test_1);
  tcase_add_test(tc1_1, s21_sum_matrix_test_2);
  tcase_add_test(tc1_1, s21_sum_matrix_test_3);
  tcase_add_test(tc1_1, s21_sum_matrix_test_4);
  tcase_add_test(tc1_1, s21_sum_matrix_test_5);
  tcase_add_test(tc1_1, test_s21_sub_matrix_1);
  tcase_add_test(tc1_1, test_s21_sub_matrix_2);
  tcase_add_test(tc1_1, test_s21_sub_matrix_3);
  tcase_add_test(tc1_1, test_s21_sub_matrix_4);
  tcase_add_test(tc1_1, test_s21_mult_number_1);
  tcase_add_test(tc1_1, test_s21_mult_matrix_1);
  tcase_add_test(tc1_1, test_s21_mult_matrix_2);
  tcase_add_test(tc1_1, test_s21_mult_matrix_3);
  tcase_add_test(tc1_1, test_s21_transpose);
  tcase_add_test(tc1_1, test_s21_determinant);
  tcase_add_test(tc1_1, test_s21_calc_complements);
  tcase_add_test(tc1_1, test_s21_inverse_matrix);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
