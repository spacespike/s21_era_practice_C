#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  void *initp = str;
  for (s21_size_t i = 1; i <= n; i++, str++) {
    *(unsigned char *)str = (unsigned char)c;
  }
  return initp;
}