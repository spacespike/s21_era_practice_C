#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *s1 = (char *)str1;
  int flag_stop = 0;
  while (*s1) {
    char *s2 = (char *)str2;
    while (*s2) {
      if (*s1 == *s2) {
        flag_stop = 1;
        break;
      }
      s2++;
    }
    if (flag_stop) break;
    s1++;
  }
  return (*s1) ? s1 : s21_NULL;
}