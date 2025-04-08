#ifndef _TEST_S21_MATRIX_H_
#define _TEST_S21_MATRIX_H_

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite *test_s21_calc_complements();
Suite *test_s21_create_matrix();
Suite *test_s21_determinant();
Suite *test_s21_eq_matrix();
Suite *test_s21_inverse_matrix();
Suite *test_s21_mult_matrix();
Suite *test_s21_mult_number();
Suite *test_s21_remove_matrix();
Suite *test_s21_sub_matrix();
Suite *test_s21_sum_matrix();
Suite *test_s21_transpose();

#endif  // _TEST_S21_MATRIX_H_