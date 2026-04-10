#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    if (result != NULL) result->matrix = NULL;
    result->rows = 0;
    result->columns = 0;
    return INCORRECT_MATRIX_ERROR;
  }

  result->rows = rows;
  result->columns = columns;

  // allocate memory for the array of pointers (rows)
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix != NULL) {
    // allocate memory for the each row
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
        result->matrix = NULL;
        return INCORRECT_MATRIX_ERROR;
      }
    }
  } else
    return INCORRECT_MATRIX_ERROR;

  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    // if (A != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
    }
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) return FAILURE;
  if (A == NULL || B == NULL || A->rows != B->rows || A->columns != B->columns)
    return FAILURE;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) return FAILURE;
    }
  }
  return SUCCESS;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) return INCORRECT_MATRIX_ERROR;

  if ((A->rows != B->rows) || (A->columns != B->columns))
    return CALCULATION_ERROR;

  if (s21_create_matrix(A->columns, A->rows, result) != OK || result == NULL)
    return INCORRECT_MATRIX_ERROR;

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];

  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) return INCORRECT_MATRIX_ERROR;

  if ((A->rows != B->rows) || (A->columns != B->columns))
    return CALCULATION_ERROR;

  if (s21_create_matrix(A->rows, A->columns, result) != OK || result == NULL)
    return INCORRECT_MATRIX_ERROR;

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];

  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!s21_is_correct(A)) return INCORRECT_MATRIX_ERROR;

  if (s21_create_matrix(A->rows, A->columns, result) != OK || result == NULL)
    return INCORRECT_MATRIX_ERROR;

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] * number;

  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_correct(A) || !s21_is_correct(B)) return INCORRECT_MATRIX_ERROR;

  if (A == NULL || B == NULL ||
      s21_create_matrix(A->rows, B->columns, result) != OK)
    return INCORRECT_MATRIX_ERROR;

  if ((A->columns != B->rows)) return CALCULATION_ERROR;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] =
            result->matrix[i][j] + A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A)) return INCORRECT_MATRIX_ERROR;

  if (A == NULL || s21_create_matrix(A->columns, A->rows, result) != OK)
    return INCORRECT_MATRIX_ERROR;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_is_correct(A) || !result) return INCORRECT_MATRIX_ERROR;

  if (A->rows != A->columns) return CALCULATION_ERROR;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else {
    *result = s21_determinant_calculation(A->matrix, A->rows);
  }
  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A) || !result) return INCORRECT_MATRIX_ERROR;

  if (s21_create_matrix(A->columns, A->rows, result) != OK)
    return INCORRECT_MATRIX_ERROR;

  s21_adjoint_matrix(A, result);
  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_is_correct(A) || !result) return INCORRECT_MATRIX_ERROR;

  if (A->rows != A->columns) return CALCULATION_ERROR;

  double det_A = 0;
  int result_code = s21_determinant(A, &det_A);

  if (fabs(det_A) < 1e-6 || result_code != OK) return CALCULATION_ERROR;

  matrix_t adjoint_A = {0};
  if (s21_calc_complements(A, &adjoint_A)) return INCORRECT_MATRIX_ERROR;

  matrix_t transposed_A = {0};

  if (s21_transpose(&adjoint_A, &transposed_A) ||
      s21_create_matrix(A->rows, A->rows, result))
    return INCORRECT_MATRIX_ERROR;

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->rows; j++)
      result->matrix[i][j] = transposed_A.matrix[i][j] / det_A;

  s21_remove_matrix(&transposed_A);
  s21_remove_matrix(&adjoint_A);
  return OK;
}