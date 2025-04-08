#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if (!A || !B || !A->matrix || !B->matrix || A->rows != B->rows ||
      A->columns != B->columns) {
    status = FAILURE;
  } else {
    for (int i = 0; i < A->rows && status == SUCCESS; i++) {
      for (int j = 0; j < A->columns && status == SUCCESS; j++) {
        double diff = 0;
        if (A->matrix[i][j] >= B->matrix[i][j]) {
          diff = A->matrix[i][j] - B->matrix[i][j];
        } else {
          diff = B->matrix[i][j] - A->matrix[i][j];
        }
        if (diff > ACCURACY) {
          status = FAILURE;
        }
      }
    }
  }
  return status;
}