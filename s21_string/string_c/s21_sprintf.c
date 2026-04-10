// gcc s21_sprintf.c s21_strerror.c s21_string.c && ./a.out

#include "../s21_sprintf.h"

// %[флаги][ширина][.точность][длина]спецификатор
int s21_sprintf(char *str, const char *format, ...) {
  va_list ap;
  s21_atributes atr;
  char *pstr = str;  // run over out str
  int str_len = 0;

  s21_init(&pstr, &atr);

  va_start(ap, format);

  // loop over format string
  for (char *pfrmt = (char *)format; *pfrmt; pfrmt++) {
    if (*pfrmt != '%') {
      s21_add_char_to_str(&pstr, *pfrmt, &str_len);
      continue;
    }

    // write atributes in structures
    int parsed_len = s21_parse_format(&pfrmt, &atr);

    if (parsed_len < 1) {
      // s21_strerror();
      printf("No specifier\n");
      break;
    }

    // int is_atr_ok = s21_check_atributes(atr);
    // if (!is_atr_ok) {
    //   // s21_strerror();
    //   printf("Nonconsistent atributes\n");
    //   break;
    // }

    s21_add_arg(&pstr, &ap, atr, &str_len);

    s21_init_atributes(&atr);

    // pfrmt += atr.prototype_len;
  }

  // finalize
  *pstr = '\0';

  va_end(ap);

  return str_len;
}

void s21_init(char **out_str, s21_atributes *atr) {
  (*out_str)[0] = '\0';

  s21_init_atributes(atr);
}

void s21_init_atributes(s21_atributes *atr) {
  atr->fl_minus = 0;
  atr->fl_plus = 0;
  atr->fl_space = 0;
  atr->fl_sharp = 0;
  atr->fl_zero = 0;
  atr->fl_asterisk_width = 0;
  atr->fl_asterisk_precision = 0;
  atr->width = -1;
  atr->precision = -1;
  atr->length = -1;
  atr->length_2 = -1;
  atr->specifier = -1;
}

void s21_print_atributes(s21_atributes atr) {
  printf("fl_minus=%d\t", atr.fl_minus);
  printf("fl_plus=%d\t", atr.fl_plus);
  printf("fl_space=%d\t", atr.fl_space);
  printf("fl_sharp=%d\t", atr.fl_sharp);
  printf("fl_zero=%d\t", atr.fl_zero);
  printf("fl_asterisk_width=%d\t", atr.fl_asterisk_width);
  printf("fl_asterisk_precision=%d\t", atr.fl_asterisk_precision);

  printf("width=%d\t", atr.width);
  printf("precision=%d\t", atr.precision);
  (atr.length < 1) ? printf("length=%d\t", atr.length)
                   : printf("length=%c\t", atr.length);
  (atr.length_2 < 1) ? printf("length_2=%d\t", atr.length_2)
                     : printf("length_2=%c\t", atr.length_2);
  (atr.specifier < 1) ? printf("specifier=%d\n", atr.specifier)
                      : printf("specifier=%c\n", atr.specifier);
}

int s21_check_atributes(s21_atributes atr) {
  int is_consistent = 0;

  switch (atr.specifier) {
    case 'c':
      is_consistent = (atr.length == -1 && atr.length_2 == -1) ? 1 : 0;
      break;
    case 's':
      is_consistent = (atr.length == -1 && atr.length_2 == -1 &&
                       atr.fl_space == 0 && atr.fl_zero == 0)
                          ? 1
                          : 0;
      break;
    case '%':
      is_consistent = (atr.length == -1 && atr.length_2 == -1) ? 1 : 0;
      break;

    default:
      break;
  }
  return is_consistent;
}

void s21_add_char_to_str(char **out_str, char symb, int *str_len) {
  if (*str_len < s21_BUFSIZ) {
    (**out_str) = symb;
    (*out_str)++;
    (*str_len)++;
  }
}

int s21_parse_format(char **format, s21_atributes *atr) {
  int is_consistent = 0;
  int prototype_len;

  char *first = *format;
  if (**format == '%') {
    (*format)++;

    s21_parse_flags(atr, format);
    s21_parse_width(atr, format);
    s21_parse_precision(atr, format);
    s21_parse_length(atr, format);
    is_consistent = s21_parse_specifier(atr, format);
  }
  prototype_len = (is_consistent) ? (int)(*format - first) : 0;

  return prototype_len;
}

int s21_parse_flags(s21_atributes *atr, char **format) {
  char first = **format;
  int is_found = (first == '-' || first == '+' || first == ' ' ||
                  first == '#' || first == '0')
                     ? 1
                     : 0;
  int stop = (is_found) ? 0 : 1;

  while (!stop) {
    switch (**format) {
      case '-':
        atr->fl_minus = 1;
        break;
      case '+':
        atr->fl_plus = 1;
        break;
      case ' ':
        atr->fl_space = 1;
        break;
      case '#':
        atr->fl_sharp = 1;
        break;
      case '0':
        atr->fl_zero = 1;
        break;
      default:
        stop = 1;
        (*format)--;
        break;
    }
    (*format)++;
  }
  return is_found;
}

int s21_parse_width(s21_atributes *atr, char **format) {
  int is_found = (s21_isdigit(**format) || **format == '*') ? 1 : 0;

  if (is_found) {
    if (**format == '*') {
      atr->fl_asterisk_width = 1;
      (*format)++;
    } else {
      atr->width = s21_atoi(*format);
      while (s21_isdigit(**format)) (*format)++;
    }
  }

  return is_found;
}

int s21_parse_precision(s21_atributes *atr, char **format) {
  int is_found = 0;
  int is_point = (**format == '.') ? 1 : 0;

  if (is_point) {
    atr->precision = 0;
    is_found = 1;
    (*format)++;

    if (**format == '*') {
      atr->precision = -1;
      atr->fl_asterisk_precision = 1;
      (*format)++;
    } else {
      atr->precision = s21_atoi(*format);
      while (s21_isdigit(**format)) (*format)++;
    }
  }

  return is_found;
}

int s21_parse_length(s21_atributes *atr, char **format) {
  int is_found =
      (**format == 'h' || **format == 'l' || **format == 'L') ? 1 : 0;
  int try_next = (**format == 'h' || **format == 'l') ? 1 : 0;  // for hh, ll

  if (is_found) {
    atr->length = **format;
    (*format)++;
  }

  if (is_found && try_next) {
    if (atr->length == 'h' && **format == 'h') {
      atr->length_2 = 'h';
      (*format)++;
    }
    if (atr->length == 'l' && **format == 'l') {
      atr->length_2 = 'l';
      (*format)++;
    }
  }

  return is_found;
}

int s21_parse_specifier(s21_atributes *atr, char **format) {
  int is_found = (s21_strchr(SPECIFIERS, **format) != s21_NULL &&
                  *s21_strchr(SPECIFIERS, **format) != '\0')
                     ? 1
                     : 0;

  if (is_found) {
    atr->specifier = **format;
    // don't move pointer: it's last operation in parser
  }

  return is_found;
}
