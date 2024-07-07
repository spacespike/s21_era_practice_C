#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *rtn = s21_NULL;
  unsigned char *string = (unsigned char *)str;
  s21_size_t i = 0;
  while (i < n && !rtn) {
    if (string[i] == c) {
      rtn = &string[i];
    }
    i++;
  }
  return rtn;
}