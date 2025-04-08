#include "test_s21_matrix.h"

START_TEST(s21_determinant_1) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 8;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t a;
  double result = 0;
  double standard = 116;
  s21_create_matrix(10, 10, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 0;
  a.matrix[0][2] = 1;
  a.matrix[0][3] = 2;
  a.matrix[0][4] = 0;
  a.matrix[0][5] = 1;
  a.matrix[0][6] = 0;
  a.matrix[0][7] = 1;
  a.matrix[0][8] = 0;
  a.matrix[0][9] = 0;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 2;
  a.matrix[1][3] = 2;
  a.matrix[1][4] = 2;
  a.matrix[1][5] = 2;
  a.matrix[1][6] = 2;
  a.matrix[1][7] = 0;
  a.matrix[1][8] = 2;
  a.matrix[1][9] = 1;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 1;
  a.matrix[2][2] = 2;
  a.matrix[2][3] = 1;
  a.matrix[2][4] = 0;
  a.matrix[2][5] = 1;
  a.matrix[2][6] = 2;
  a.matrix[2][7] = 0;
  a.matrix[2][8] = 0;
  a.matrix[2][9] = 1;
  a.matrix[3][0] = 0;
  a.matrix[3][1] = 1;
  a.matrix[3][2] = 0;
  a.matrix[3][3] = 2;
  a.matrix[3][4] = 1;
  a.matrix[3][5] = 2;
  a.matrix[3][6] = 2;
  a.matrix[3][7] = 2;
  a.matrix[3][8] = 0;
  a.matrix[3][9] = 0;
  a.matrix[4][0] = 1;
  a.matrix[4][1] = 1;
  a.matrix[4][2] = 1;
  a.matrix[4][3] = 2;
  a.matrix[4][4] = 2;
  a.matrix[4][5] = 1;
  a.matrix[4][6] = 0;
  a.matrix[4][7] = 1;
  a.matrix[4][8] = 1;
  a.matrix[4][9] = 1;
  a.matrix[5][0] = 2;
  a.matrix[5][1] = 2;
  a.matrix[5][2] = 2;
  a.matrix[5][3] = 0;
  a.matrix[5][4] = 0;
  a.matrix[5][5] = 1;
  a.matrix[5][6] = 1;
  a.matrix[5][7] = 2;
  a.matrix[5][8] = 2;
  a.matrix[5][9] = 0;
  a.matrix[6][0] = 2;
  a.matrix[6][1] = 2;
  a.matrix[6][2] = 0;
  a.matrix[6][3] = 2;
  a.matrix[6][4] = 0;
  a.matrix[6][5] = 1;
  a.matrix[6][6] = 2;
  a.matrix[6][7] = 1;
  a.matrix[6][8] = 2;
  a.matrix[6][9] = 0;
  a.matrix[7][0] = 2;
  a.matrix[7][1] = 1;
  a.matrix[7][2] = 2;
  a.matrix[7][3] = 1;
  a.matrix[7][4] = 1;
  a.matrix[7][5] = 0;
  a.matrix[7][6] = 1;
  a.matrix[7][7] = 1;
  a.matrix[7][8] = 1;
  a.matrix[7][9] = 0;
  a.matrix[8][0] = 1;
  a.matrix[8][1] = 1;
  a.matrix[8][2] = 2;
  a.matrix[8][3] = 1;
  a.matrix[8][4] = 2;
  a.matrix[8][5] = 1;
  a.matrix[8][6] = 1;
  a.matrix[8][7] = 1;
  a.matrix[8][8] = 0;
  a.matrix[8][9] = 0;
  a.matrix[9][0] = 1;
  a.matrix[9][1] = 2;
  a.matrix[9][2] = 1;
  a.matrix[9][3] = 1;
  a.matrix[9][4] = 0;
  a.matrix[9][5] = 2;
  a.matrix[9][6] = 1;
  a.matrix[9][7] = 1;
  a.matrix[9][8] = 2;
  a.matrix[9][9] = 2;
  ck_assert_int_eq(OK, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, standard, ACCURACY);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t a;
  double result = 0;
  double standard = 110;
  s21_create_matrix(6, 6, &a);
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
  ck_assert_int_eq(OK, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, standard, ACCURACY);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-45, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-21, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_7) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_8) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_9) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_11) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_12) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_13) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_14) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_15) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_16) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_17) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_18) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_19) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_20) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;

  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(1, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_21) {
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_22) {
  double result;
  ck_assert_int_eq(s21_determinant(NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_23) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -1;

  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-1, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_24) {
  matrix_t A;
  s21_create_matrix(256, 256, &A);
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      A.matrix[i][j] = 1;
    }
  }

  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, ACCURACY);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_s21_determinant(void) {
  Suite *s = suite_create("\033[45m-=S21_DETERMINANT=-\033[0m");
  TCase *tc = tcase_create("s21_determinant");
  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);
  tcase_add_test(tc, s21_determinant_9);
  tcase_add_test(tc, s21_determinant_10);
  tcase_add_test(tc, s21_determinant_11);
  tcase_add_test(tc, s21_determinant_12);
  tcase_add_test(tc, s21_determinant_13);
  tcase_add_test(tc, s21_determinant_14);
  tcase_add_test(tc, s21_determinant_15);
  tcase_add_test(tc, s21_determinant_16);
  tcase_add_test(tc, s21_determinant_17);
  tcase_add_test(tc, s21_determinant_18);
  tcase_add_test(tc, s21_determinant_19);
  tcase_add_test(tc, s21_determinant_20);
  tcase_add_test(tc, s21_determinant_21);
  tcase_add_test(tc, s21_determinant_22);
  tcase_add_test(tc, s21_determinant_23);
  tcase_add_test(tc, s21_determinant_24);
  suite_add_tcase(s, tc);
  return s;
}