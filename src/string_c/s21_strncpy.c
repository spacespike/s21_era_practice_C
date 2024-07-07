#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;

  for (; n-- != 0;) {
    if ((*dest++ = *src++) == '\0') {
      while (n-- != 0) *dest++ = '\0';
      break;
    }
  }

  return tmp;
}