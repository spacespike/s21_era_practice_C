#include "../../s21_string.h"

int s21_atoi(char str[]) {
  int i;
  int num;
  int sign;

  // skip spaces
  for (i = 0; s21_isspace(str[i]); i++);

  sign = (str[i] == '-') ? -1 : 1;
  // skip sign;
  if (str[i] == '+' || str[i] == '-') i++;

  for (num = 0; s21_isdigit(str[i]); i++) num = 10 * num + (str[i] - '0');

  return sign * num;
}

void s21_itoab(long long int n, char *s, int base) {
  int i;
  long long int sign;

  long long int is_int_min = (n == LLONG_MIN) ? 1 : 0;
  if (is_int_min) n += 1;

  if ((sign = n) < 0) n = -n;

  i = 0;
  do {
    int modulo = n % base;
    s[i++] = modulo + ((modulo < 10) ? '0' : ('A' - 10));
  } while ((n /= base) > 0);

  s[i] = '\0';

  if (is_int_min) s21_reverse_plus_one_base(s, base);

  if (sign < 0) {
    s[i++] = '-';
    s[i] = '\0';
  }

  s21_reverse_str(s);
}

void s21_uitoab(unsigned long long int n, char *s, int base) {
  int i;

  i = 0;
  do {
    int modulo = n % base;
    s[i++] = modulo + ((modulo < 10) ? '0' : ('A' - 10));
  } while ((n /= base) > 0);

  s[i] = '\0';

  s21_reverse_str(s);
}

// base 10
void s21_itoa(long long int n, char *s) { s21_itoab(n, s, 10); }
void s21_uitoa(unsigned long long int n, char *s) { s21_uitoab(n, s, 10); }

// unsigned only
void s21_itoa8(unsigned long long int n, char *s) { s21_uitoab(n, s, 8); }

// unsigned only
void s21_itoa16(unsigned long long int n, char *s) { s21_uitoab(n, s, 16); }

// add 1 for the first digit of number dig1_dig2_dig3_...diglast
// Examples: 1111 --> 2111, 9000 --> 0100, 9900 --> 0010
void s21_reverse_plus_one(char *s) { s21_reverse_plus_one_base(s, 10); }

void s21_reverse_plus_one_base(char *s, int base) {
  char max_base_digit_symb = base - 1 + ((base <= 10) ? '0' : ('A' - 10));
  if (*s != max_base_digit_symb) {
    *s += 1;
  } else {
    char *p = s;
    int extra = 1;
    int digit;

    for (; *p; p++) {
      digit = (s21_is_numeric(*p - '0')) ? (*p - '0') : (*p - 'A' + 10);
      digit += extra;
      if (digit == base) {
        extra = 1;
        *p = '0';
      } else {
        extra = 0;
        *p = digit + ((s21_is_numeric(digit)) ? '0' : 'A');
      }
    }
    if (extra) {
      *p = '1';
      *(++p) = '\0';
    }
  }
}

int s21_is_numeric(int digit) { return (digit >= 0 && digit < 10) ? 1 : 0; }

void s21_reverse_str(char *s) {
  int temp, i, j;

  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}