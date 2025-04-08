#include "s21_matrix.h"

void copy_matrix(matrix_t *A, matrix_t *B);
void triangule_matrix(matrix_t *A);
void swap_rows(matrix_t *A, int k, int n);
double get_minor(int row, int column, matrix_t *A);