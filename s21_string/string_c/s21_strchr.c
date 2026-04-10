#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *pointer = s21_NULL;

  while (*str && *str != (char)c) str++;
  pointer = (*str == '\0') ? s21_NULL : (char *)str;
  if (c == '\0') pointer = (char *)str;

  return pointer;
}