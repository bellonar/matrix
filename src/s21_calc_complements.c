#include "helpers.h"
#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (!A || !result || !A->matrix) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = get_minor(i, j, A);
        }
      }
    }
  }
  return status;
}