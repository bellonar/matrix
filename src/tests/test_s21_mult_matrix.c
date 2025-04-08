#include "test_s21_matrix.h"

START_TEST(s21_mult_matrix1) {
  matrix_t A;
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix2) {
  matrix_t A;
  matrix_t B;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 4, &B);
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix4) {
  matrix_t A, B, result, std;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &std);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  std.matrix[0][0] = 7;
  std.matrix[0][1] = 10;
  std.matrix[1][0] = 15;
  std.matrix[1][1] = 22;
  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

START_TEST(s21_mult_matrix5) {
  matrix_t A, B, result, std;
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);
  s21_create_matrix(2, 2, &std);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  std.matrix[0][0] = 1;
  std.matrix[0][1] = 2;
  std.matrix[1][0] = 2;
  std.matrix[1][1] = 4;
  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

START_TEST(s21_mult_matrix6) {
  matrix_t A, B, result, std;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &B);
  s21_create_matrix(1, 1, &std);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 2;
  std.matrix[0][0] = 5;
  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

Suite *test_s21_mult_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_MULT_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s21_mult_matrix");
  tcase_add_test(tc, s21_mult_matrix1);
  tcase_add_test(tc, s21_mult_matrix2);
  tcase_add_test(tc, s21_mult_matrix3);
  tcase_add_test(tc, s21_mult_matrix4);
  tcase_add_test(tc, s21_mult_matrix5);
  tcase_add_test(tc, s21_mult_matrix6);
  suite_add_tcase(s, tc);
  return s;
}