#include "helpers.h"
#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (!A || !result || !A->matrix) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    matrix_t temp;
    s21_create_matrix(A->rows, A->columns, &temp);
    copy_matrix(A, &temp);
    triangule_matrix(&temp);
    *result = temp.matrix[0][0];
    for (int i = 1; i < temp.rows; i++) {
      *result *= temp.matrix[i][i];
    }
    s21_remove_matrix(&temp);
  }
  return status;
}