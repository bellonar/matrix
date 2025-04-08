#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (rows <= 0 || columns <= 0 || !result) {
    status = INCORRECT_MATRIX;
  } else {
    result->matrix = (double **)calloc(
        1, rows * sizeof(double *) + rows * columns * sizeof(double));
    if (result->matrix == NULL) {
      status = INCORRECT_MATRIX;
    } else {
      result->rows = rows;
      result->columns = columns;
      result->matrix[0] = (double *)(result->matrix + result->rows);
      for (int i = 1; i < result->rows; i++) {
        result->matrix[i] = result->matrix[0] + i * result->columns;
      }
    }
  }
  return status;
}