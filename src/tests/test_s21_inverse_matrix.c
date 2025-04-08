#include "test_s21_matrix.h"

START_TEST(inverse_matrix_1) {
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t a;
  s21_create_matrix(3, 3, &a);
  ck_assert_int_eq(s21_inverse_matrix(&a, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t a;
  a.matrix = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&a, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t a;
  matrix_t result;
  s21_create_matrix(3, 3, &a);
  ck_assert_int_eq(s21_inverse_matrix(&a, &result), CALCULATION_ERROR);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t a;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &check);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 4;
  a.matrix[0][2] = -1;
  a.matrix[1][0] = 7;
  a.matrix[1][1] = 3;
  a.matrix[1][2] = 1;
  a.matrix[2][0] = -3;
  a.matrix[2][1] = 5;
  a.matrix[2][2] = 6;

  check.matrix[0][0] = -13.0 / 198.0;
  check.matrix[0][1] = 29.0 / 198.0;
  check.matrix[0][2] = -7.0 / 198.0;
  check.matrix[1][0] = 5.0 / 22.0;
  check.matrix[1][1] = -1.0 / 22.0;
  check.matrix[1][2] = 1.0 / 22.0;
  check.matrix[2][0] = -2.0 / 9.0;
  check.matrix[2][1] = 1.0 / 9.0;
  check.matrix[2][2] = 1.0 / 9.0;

  ck_assert_int_eq(s21_inverse_matrix(&a, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t a;
  matrix_t result;
  s21_create_matrix(3, 4, &a);
  ck_assert_int_eq(s21_inverse_matrix(&a, &result), CALCULATION_ERROR);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t a;
  matrix_t b;
  matrix_t check;
  s21_create_matrix(4, 4, &check);
  s21_create_matrix(4, 4, &a);

  a.matrix[0][0] = -1.0;
  a.matrix[0][1] = 2.0;
  a.matrix[0][2] = 7.0;
  a.matrix[0][3] = 9.0;
  a.matrix[1][0] = 1.0;
  a.matrix[1][1] = 0.0;
  a.matrix[1][2] = 0.0;
  a.matrix[1][3] = 0.0;
  a.matrix[2][0] = 47.0;
  a.matrix[2][1] = 13.0;
  a.matrix[2][2] = 17.0;
  a.matrix[2][3] = 21.0;
  a.matrix[3][0] = 22.0;
  a.matrix[3][1] = 7.0;
  a.matrix[3][2] = 1.0;
  a.matrix[3][3] = 3.0;

  check.matrix[0][0] = 0.0;
  check.matrix[0][1] = 1.0;
  check.matrix[0][2] = 0.0;
  check.matrix[0][3] = 0.0;
  check.matrix[1][0] = -5.0 / 23.0;
  check.matrix[1][1] = -121.0 / 23.0;
  check.matrix[1][2] = 2.0 / 23.0;
  check.matrix[1][3] = 1.0 / 23.0;
  check.matrix[2][0] = -18.0 / 23.0;
  check.matrix[2][1] = -379.0 / 46.0;
  check.matrix[2][2] = 19.0 / 46.0;
  check.matrix[2][3] = -25.0 / 46.0;
  check.matrix[3][0] = 53.0 / 69.0;
  check.matrix[3][1] = 1061.0 / 138.0;
  check.matrix[3][2] = -47.0 / 138.0;
  check.matrix[3][3] = 19.0 / 46.0;

  s21_inverse_matrix(&a, &b);
  s21_remove_matrix(&a);
  ck_assert_int_eq(s21_eq_matrix(&check, &b), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_matrix_8) {
  matrix_t a, result, check;
  s21_create_matrix(6, 6, &a);
  s21_create_matrix(6, 6, &check);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = -1;
  a.matrix[0][2] = -1;
  a.matrix[0][3] = 1;
  a.matrix[0][4] = 1;
  a.matrix[0][5] = 2;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 1;
  a.matrix[1][3] = 0;
  a.matrix[1][4] = 0;
  a.matrix[1][5] = -2;
  a.matrix[2][0] = 0;
  a.matrix[2][1] = -1;
  a.matrix[2][2] = -2;
  a.matrix[2][3] = -2;
  a.matrix[2][4] = -1;
  a.matrix[2][5] = 2;
  a.matrix[3][0] = -2;
  a.matrix[3][1] = 2;
  a.matrix[3][2] = 0;
  a.matrix[3][3] = -1;
  a.matrix[3][4] = -2;
  a.matrix[3][5] = 1;
  a.matrix[4][0] = 0;
  a.matrix[4][1] = 0;
  a.matrix[4][2] = -1;
  a.matrix[4][3] = -1;
  a.matrix[4][4] = -1;
  a.matrix[4][5] = 0;
  a.matrix[5][0] = 2;
  a.matrix[5][1] = 0;
  a.matrix[5][2] = 1;
  a.matrix[5][3] = 0;
  a.matrix[5][4] = -2;
  a.matrix[5][5] = 0;

  check.matrix[0][0] = 7. / 55;
  check.matrix[0][1] = 5. / 22;
  check.matrix[0][2] = 8. / 55;
  check.matrix[0][3] = -1. / 11;
  check.matrix[0][4] = -4. / 55;
  check.matrix[0][5] = 13. / 110;
  check.matrix[1][0] = 12. / 55;
  check.matrix[1][1] = 7. / 22;
  check.matrix[1][2] = -2. / 55;
  check.matrix[1][3] = 3. / 11;
  check.matrix[1][4] = 1. / 55;
  check.matrix[1][5] = -17. / 110;
  check.matrix[2][0] = -0.4;
  check.matrix[2][1] = 0;
  check.matrix[2][2] = 0.4;
  check.matrix[2][3] = 0;
  check.matrix[2][4] = -1.2;
  check.matrix[2][5] = 0.2;
  check.matrix[3][0] = 26. / 55;
  check.matrix[3][1] = -5. / 22;
  check.matrix[3][2] = -41. / 55;
  check.matrix[3][3] = 1. / 11;
  check.matrix[3][4] = 48. / 55;
  check.matrix[3][5] = 9. / 110;
  check.matrix[4][0] = -4. / 55;
  check.matrix[4][1] = 5. / 22;
  check.matrix[4][2] = 19. / 55;
  check.matrix[4][3] = -1. / 11;
  check.matrix[4][4] = -37. / 55;
  check.matrix[4][5] = -31. / 110;
  check.matrix[5][0] = 8. / 55;
  check.matrix[5][1] = 1. / 22;
  check.matrix[5][2] = 17. / 55;
  check.matrix[5][3] = 2. / 11;
  check.matrix[5][4] = -36. / 55;
  check.matrix[5][5] = 7. / 110;

  ck_assert_int_eq(OK, s21_inverse_matrix(&a, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_matrix_9) {
  matrix_t a, result, check;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 1;
  s21_create_matrix(1, 1, &check);
  check.matrix[0][0] = 1;
  ck_assert_int_eq(s21_inverse_matrix(&a, &result), OK);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&a);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_10) {
  matrix_t a, result, check;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 2;
  s21_create_matrix(1, 1, &check);
  check.matrix[0][0] = 1.0 / 2.0;
  ck_assert_int_eq(s21_inverse_matrix(&a, &result), OK);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&a);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_s21_inverse_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_INVERSE_MATRIX=-\033[0m");
  TCase *tc = tcase_create("s21_inverse_matrix");

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);
  tcase_add_test(tc, inverse_matrix_5);
  tcase_add_test(tc, inverse_matrix_6);
  tcase_add_test(tc, inverse_matrix_7);
  tcase_add_test(tc, inverse_matrix_8);
  tcase_add_test(tc, inverse_matrix_9);
  tcase_add_test(tc, inverse_matrix_10);

  suite_add_tcase(s, tc);
  return s;
}