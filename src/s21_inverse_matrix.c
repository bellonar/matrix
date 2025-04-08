#include "helpers.h"
#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (!A || !A->matrix || !result) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    double det = 0;
    s21_determinant(A, &det);
    if (det != 0) {
      matrix_t tmp_calc;
      matrix_t tmp_trans;
      s21_calc_complements(A, &tmp_calc);
      s21_transpose(&tmp_calc, &tmp_trans);
      s21_mult_number(&tmp_trans, 1 / det, result);
      s21_remove_matrix(&tmp_calc);
      s21_remove_matrix(&tmp_trans);
    } else {
      status = CALCULATION_ERROR;
    }
  }
  return status;
}