#include "test_s21_matrix.h"

START_TEST(s21_mult_number1) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, 1, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_mult_number(&A, 1, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, 1, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number4) {
  matrix_t A, result, std;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &std);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  std.matrix[0][0] = 2;
  std.matrix[0][1] = 4;
  std.matrix[1][0] = 6;
  std.matrix[1][1] = 8;
  ck_assert_int_eq(OK, s21_mult_number(&A, 2, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

Suite *test_s21_mult_number(void) {
  Suite *s = suite_create("\033[45m-=S21_MULT_NUMBER=-\033[0m");
  TCase *tc = tcase_create("s21_mult_number");
  tcase_add_test(tc, s21_mult_number1);
  tcase_add_test(tc, s21_mult_number2);
  tcase_add_test(tc, s21_mult_number3);
  tcase_add_test(tc, s21_mult_number4);
  suite_add_tcase(s, tc);
  return s;
}