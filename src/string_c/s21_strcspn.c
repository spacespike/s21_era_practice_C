#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p1 = str1;
  const char *p2 = str2;
  s21_size_t flag = 0;
  s21_size_t t = 0;
  s21_size_t n1 = s21_strlen(p1);
  s21_size_t n2 = s21_strlen(p2);
  for (s21_size_t i = 0; i < n1; i++) {
    for (s21_size_t j = 0; j < n2; j++) {
      if (p1[i] == p2[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    } else
      t++;
  }
  return t;
}
