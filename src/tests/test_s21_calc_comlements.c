#include "test_s21_matrix.h"

START_TEST(s21_calc_complements1) {
  matrix_t A;
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements2) {
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements3) {
  matrix_t A, result, std;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &std);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  std.matrix[0][0] = 0;
  std.matrix[0][1] = 10;
  std.matrix[0][2] = -20;
  std.matrix[1][0] = 4;
  std.matrix[1][1] = -14;
  std.matrix[1][2] = 8;
  std.matrix[2][0] = -8;
  std.matrix[2][1] = -2;
  std.matrix[2][2] = 4;
  ck_assert_int_eq(OK, s21_calc_complements(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

START_TEST(s21_calc_complements4) {
  matrix_t A, std;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &std);
  std.matrix[0][0] = 1;
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&std);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_s21_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=S21_CALC_COMPLEMENTS=-\033[0m");
  TCase *tc = tcase_create("s21_calc_complements");
  tcase_add_test(tc, s21_calc_complements1);
  tcase_add_test(tc, s21_calc_complements2);
  tcase_add_test(tc, s21_calc_complements3);
  tcase_add_test(tc, s21_calc_complements4);
  suite_add_tcase(s, tc);
  return s;
}