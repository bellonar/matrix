#include "test_s21_matrix.h"

START_TEST(s21_create_matrix1) {
  ck_assert_int_eq(s21_create_matrix(2, 2, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix2) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(0, 5, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix3) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(6, 0, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix4) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix5) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(-1, 1, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix6) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3000000, 3000000, &A), INCORRECT_MATRIX);
}
END_TEST

Suite *test_s21_create_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_CREATE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s21_create_matrix");
  tcase_add_test(tc, s21_create_matrix1);
  tcase_add_test(tc, s21_create_matrix2);
  tcase_add_test(tc, s21_create_matrix3);
  tcase_add_test(tc, s21_create_matrix4);
  tcase_add_test(tc, s21_create_matrix5);
  tcase_add_test(tc, s21_create_matrix6);
  suite_add_tcase(s, tc);
  return s;
}