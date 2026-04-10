#include "s21_matrix.h"

int s21_is_correct(matrix_t *A) { return A && A->rows > 0 && A->columns > 0; }

double s21_determinant_calculation(double **matrix, int size) {
  double result = 0;
  matrix_t cofactor = {0};
  if (s21_create_matrix(size, size, &cofactor) != OK)
    return INCORRECT_MATRIX_ERROR;

  // creating a variable, that will store our sign
  int sign = 1;
  // or use while until size == 2, and then use formula ad-bc?
  for (int i = 0; i < size; i++) {
    s21_cofactor_calc(matrix, cofactor.matrix, 0, i, size);
    result += sign * matrix[0][i] *
              s21_determinant_calculation(cofactor.matrix, size - 1);
    sign = -sign;
  }
  s21_remove_matrix(&cofactor);

  return result;
}

void s21_cofactor_calc(double **matrix, double **cofactor, int skip_row,
                       int skip_col, int size) {
  for (int i = 0, row = 0; row < size; row++) {
    for (int j = 0, col = 0; col < size; col++) {
      if (row != skip_row && col != skip_col) {
        cofactor[i][j] = matrix[row][col];
        j++;
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

void s21_adjoint_matrix(matrix_t *A, matrix_t *result) {
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
    return;
  }

  matrix_t tmp = {0};

  if (s21_create_matrix(A->rows, A->rows, &tmp) != OK) return;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      s21_cofactor_calc(A->matrix, tmp.matrix, i, j, A->rows);

      int sign = ((i + j) % 2 == 0) ? 1 : -1;

      result->matrix[i][j] =
          sign * s21_determinant_calculation(tmp.matrix, A->rows - 1);
    }
  }

  s21_remove_matrix(&tmp);
}