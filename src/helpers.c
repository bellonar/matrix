#include "helpers.h"

void copy_matrix(matrix_t *A, matrix_t *B) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      B->matrix[i][j] = A->matrix[i][j];
    }
  }
}
void triangule_matrix(matrix_t *A) {
  for (int i = 1; i < A->columns; i++) {
    for (int j = i; j < A->columns; j++) {
      if (A->matrix[j][i - 1] != 0) {
        if (A->matrix[i - 1][i - 1] == 0) {
          swap_rows(A, i - 1, j);
        }
        int sign = -1;
        double delta = A->matrix[j][i - 1] / A->matrix[i - 1][i - 1];
        if (delta < 0) {
          delta *= -1;
          sign = 1;
        }
        for (int k = i; k < A->columns; k++) {
          A->matrix[j][k] += A->matrix[i - 1][k] * delta * sign;
          A->matrix[j][i - 1] = 0;
        }
      }
    }
  }
}

void swap_rows(matrix_t *A, int k, int n) {
  for (int i = 0; i < A->rows; i++) {
    double temp = A->matrix[n][i];
    A->matrix[n][i] = A->matrix[k][i];
    A->matrix[k][i] = temp * -1;
  }
}

double get_minor(int row, int column, matrix_t *A) {
  double result = 0;
  matrix_t minor;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != row) {
      for (int j = 0; j < A->columns; j++) {
        if (j != column) {
          minor.matrix[m_row][m_col] = A->matrix[i][j];
          m_col++;
        }
      }
      m_row++;
      m_col = 0;
    }
  }
  s21_determinant(&minor, &result);
  if ((row + column) % 2 != 0) {
    result *= -1;
  }
  s21_remove_matrix(&minor);
  return result;
}