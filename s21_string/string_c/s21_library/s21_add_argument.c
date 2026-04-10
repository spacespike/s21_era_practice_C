#include "../../s21_sprintf.h"
/*
arg c: width, -, *, 0
arg d: width, precision, -, ' ', +, 0, *
arg s: width, precision, -, ' ', +, 0, *
 */

void s21_add_arg(char** str_out, va_list* ap, s21_atributes atr, int* str_len) {
  char* arg_str = (char*)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  (*arg_str) = '\0';
  char arg_char = '\0';
  switch (atr.specifier) {
    case 'c':
      s21_add_arg_c(&atr, ap, &arg_char);
      s21_add_fchar(str_out, atr, str_len, arg_char);
      break;
    case 'd':
      s21_add_arg_d(&atr, ap, &arg_str);
      s21_add_fstr(str_out, atr, str_len, arg_str);
      break;
    case 's':
      s21_add_arg_s(&atr, ap, &arg_str);
      s21_add_fstr(str_out, atr, str_len, arg_str);
      break;

    case '%':
      s21_add_fchar(str_out, atr, str_len, '%');
      break;

    default:
      // s21_strerror()
      printf("Error in add_arg: no such specifier\n");
      break;
  }
  // if (*arg_str != '\0') free(arg_str);
  //  if (arg_str2) free(arg_str2);
}

void s21_add_arg_c(s21_atributes* atr, va_list* ap, char* arg_char) {
  if (atr->fl_asterisk_width == 1) {
    atr->width = va_arg(*ap, int);
  }
  *arg_char = va_arg(*ap, int);
}
void s21_add_arg_d(s21_atributes* atr, va_list* ap, char** arg_str) {
  if (atr->fl_asterisk_width == 1) {
    atr->width = va_arg(*ap, int);
  }
  if (atr->fl_asterisk_precision == 1) {
    atr->precision = va_arg(*ap, int);
  }

  char* p_arg_str = *arg_str;
  int arg_int = va_arg(*ap, int);
  s21_itoa(arg_int, *arg_str);
  int len_arg_str = (int)s21_strlen(*arg_str);
  int zero_length = atr->precision - len_arg_str;

  if ((arg_int > 0 && atr->fl_plus) || atr->fl_space) {
    if (atr->fl_plus) {
      s21_memset(p_arg_str, '+', 1);
      (p_arg_str)++;
    } else if (atr->fl_space) {
      s21_memset(p_arg_str, ' ', 1);
      (p_arg_str)++;
    }
  }

  if (atr->precision != -1 && zero_length > 0) {
    s21_memset(p_arg_str, '0', zero_length);
    p_arg_str += zero_length;
    atr->precision = -1;
  }

  s21_itoa(arg_int, p_arg_str);
}

void s21_add_arg_s(s21_atributes* atr, va_list* ap, char** arg_str) {
  if (atr->fl_asterisk_width == 1) {
    atr->width = va_arg(*ap, int);
  }
  if (atr->fl_asterisk_precision == 1) {
    atr->precision = va_arg(*ap, int);
  }

  if (atr->precision != -1) {
    char* arg_str1 = va_arg(*ap, char*);
    int len_arg_str = (int)s21_strlen(arg_str1);
    int excess_length = len_arg_str - atr->precision;
    int precision = (atr->precision >= 0 && excess_length > 0) ? atr->precision
                                                               : len_arg_str;
    s21_strncpy(*arg_str, arg_str1, precision);
    atr->precision = -1;
  } else {
    *arg_str = va_arg(*ap, char*);
    atr->precision = -1;
  }
}

void s21_add_fchar(char** str_out, s21_atributes atr, int* str_len, char symb) {
  int width = (atr.width > 0) ? atr.width : 1;
  if (atr.fl_zero && !atr.fl_minus) {
    s21_memset(*str_out, '0', width);
  } else {
    s21_memset(*str_out, ' ', width);
  }

  if (atr.fl_minus) {
    **str_out = symb;
    (*str_out) += width;
  } else {
    *str_out = *str_out + width - 1;
    **str_out = symb;
    (*str_out)++;
  }

  (*str_len) += width;
}

void s21_add_fstr(char** str_out, s21_atributes atr, int* str_len,
                  char* str_in) {
  int str_in_len = (int)s21_strlen(str_in);

  int width = (atr.width > str_in_len) ? atr.width : str_in_len;

  if (atr.fl_zero && !atr.fl_minus) {
    s21_memset(*str_out, '0', width);
  } else {
    s21_memset(*str_out, ' ', width);
  }

  if (atr.fl_minus) {
    s21_strncpy(*str_out, str_in, str_in_len);
    (*str_out) += width;
  } else {
    *str_out = *str_out + width - str_in_len;
    s21_strncpy(*str_out, str_in, str_in_len);
    (*str_out) += str_in_len;
  }

  (*str_len) += width;
}