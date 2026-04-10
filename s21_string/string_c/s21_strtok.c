#include <stdio.h>

#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  const char *d = delim;
  static char *start = s21_NULL;
  if (str != s21_NULL) {
    start = str;
  }
  char *p = start;
  s21_size_t shift = 0;

  while ((shift == 0) && (start != s21_NULL)) {
    shift = s21_strcspn(p, d);
    if ((shift == 0) && (p[shift] != '\0')) {
      p++;
    } else if ((shift != 0) && (p[shift] != '\0')) {
      p[shift] = '\0';
      start = p + shift + 1;
      break;
    } else if ((shift == 0) && (p[shift] == '\0')) {
      p = s21_NULL;
      start = s21_NULL;
      break;
    } else {
      start = s21_NULL;
      break;
    }
  }

  return p;
}
