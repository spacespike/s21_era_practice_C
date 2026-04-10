#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#define SUCCESS 1
#define FAILURE 0

// #include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT_MATRIX_ERROR 1
#define CALCULATION_ERROR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// helpers
int s21_is_correct(matrix_t *A);
double s21_determinant_calculation(double **matrix, int size);
void s21_cofactor_calc(double **matrix, double **cofactor, int skip_row,
                       int skip_col, int size);
void s21_adjoint_matrix(matrix_t *A, matrix_t *result);
#endif