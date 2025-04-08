#include "test_s21_matrix.h"

START_TEST(s21_remove_matrix1) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

Suite *test_s21_remove_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_REMOVE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s21_remove_matrix");
  tcase_add_test(tc, s21_remove_matrix1);
  suite_add_tcase(s, tc);
  return s;
}