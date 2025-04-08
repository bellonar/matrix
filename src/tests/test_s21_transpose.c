#include "test_s21_matrix.h"

START_TEST(s21_transpose1) {
  matrix_t A;
  ck_assert_int_eq(s21_transpose(&A, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_transpose2) {
  matrix_t A, std;
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 3, &std);
  matrix_t result;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

START_TEST(s21_transpose3) {
  matrix_t A, result, std;
  s21_create_matrix(1, 4, &A);
  s21_create_matrix(4, 1, &std);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  std.matrix[0][0] = 1;
  std.matrix[1][0] = 2;
  std.matrix[2][0] = 3;
  std.matrix[3][0] = 4;
  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

START_TEST(s21_transpose4) {
  matrix_t A, result, std;
  s21_create_matrix(4, 1, &A);
  s21_create_matrix(1, 4, &std);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  A.matrix[2][0] = 3;
  A.matrix[3][0] = 4;
  std.matrix[0][0] = 1;
  std.matrix[0][1] = 2;
  std.matrix[0][2] = 3;
  std.matrix[0][3] = 4;
  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

START_TEST(s21_transpose5) {
  matrix_t A, result, std;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &std);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  std.matrix[0][0] = 1;
  std.matrix[0][1] = 4;
  std.matrix[0][2] = 7;
  std.matrix[1][0] = 2;
  std.matrix[1][1] = 5;
  std.matrix[1][2] = 8;
  std.matrix[2][0] = 3;
  std.matrix[2][1] = 6;
  std.matrix[2][2] = 9;
  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &std));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&std);
}
END_TEST

Suite *test_s21_transpose(void) {
  Suite *s = suite_create("\033[45m-=S21_TRANSPOSE=-\033[0m");
  TCase *tc = tcase_create("s21_transpose");
  tcase_add_test(tc, s21_transpose1);
  tcase_add_test(tc, s21_transpose2);
  tcase_add_test(tc, s21_transpose3);
  tcase_add_test(tc, s21_transpose4);
  tcase_add_test(tc, s21_transpose5);
  suite_add_tcase(s, tc);
  return s;
}