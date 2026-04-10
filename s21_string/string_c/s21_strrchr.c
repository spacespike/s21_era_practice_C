#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  s21_size_t n = s21_strlen(str);
  char ch = c;
  char *p = (char *)str + n;
  char *t = s21_NULL;
  for (; p - str >= 0; p--) {
    if (ch == *p) {
      t = p;
      break;
    }
  }
  return t;
  ;
}
