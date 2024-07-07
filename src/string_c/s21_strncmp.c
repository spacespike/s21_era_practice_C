#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const char *p1 = str1;
  const char *p2 = str2;
  s21_size_t i = 0;
  int t = 0;
  if (n > 0) {
    for (; i < n; i++) {
      if (p1[i] == '\0' || p2[i] == '\0' || p1[i] != p2[i]) {
        t = p1[i] - p2[i];
        break;
      }
    }
  }

  return t;
}