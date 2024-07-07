#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define s21_BUFSIZ 1024
#define SPECIFIERS "cdieEfgGosuxXpn%"
#define SPEC_FLAGS "-+ #0"
// #define SPEC_LENGTHES "hlL"

typedef struct atributes {
  int fl_minus;
  int fl_plus;
  int fl_space;
  int fl_sharp;
  int fl_zero;
  int fl_asterisk_width;
  int fl_asterisk_precision;

  int width;
  int precision;
  int length;
  int length_2;
  int specifier;
} s21_atributes;

void s21_init(char **out_str, s21_atributes *atr);
void s21_init_atributes(s21_atributes *atr);
int s21_check_atributes(s21_atributes atr);
void s21_print_atributes(s21_atributes atr);
void s21_add_char_to_str(char **out_str, char symb, int *str_len);
int s21_parse_format(char **format, s21_atributes *atr);
int s21_parse_flags(s21_atributes *atr, char **format);
int s21_parse_width(s21_atributes *atr, char **format);
int s21_parse_precision(s21_atributes *atr, char **format);
int s21_parse_length(s21_atributes *atr, char **format);
int s21_parse_specifier(s21_atributes *atr, char **format);
void s21_add_arg(char **str_out, va_list *ap, s21_atributes atr, int *str_len);
void s21_add_arg_c(s21_atributes *atr, va_list *ap, char *arg_char);
void s21_add_arg_d(s21_atributes *atr, va_list *ap, char **arg_str);
void s21_add_arg_s(s21_atributes *atr, va_list *ap, char **arg_str);
void s21_add_fchar(char **str_out, s21_atributes atr, int *str_len, char symb);
void s21_add_fstr(char **str_out, s21_atributes atr, int *str_len,
                  char *str_in);
#endif  // #ifndef S21_SPRINTF_H