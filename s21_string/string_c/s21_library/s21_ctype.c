#include "../../s21_string.h"

int s21_isspace(int c) {
  const char spaces[] = SPACES;
  int is_space = 0;

  for (char *temp_space = (char *)spaces; *temp_space && !is_space;
       temp_space++)
    if (c == *temp_space) is_space = 1;

  return is_space;
}

int s21_isdigit(int c) { return (c >= '0' && c <= '9') ? 1 : 0; }

int s21_isupper(int c) { return (c >= 'A' && c <= 'Z') ? 1 : 0; }

int s21_islower(int c) { return (c >= 'a' && c <= 'z') ? 1 : 0; }

int s21_isalpha(int c) { return (s21_isupper(c) || s21_islower(c)) ? 1 : 0; }

int s21_isxdigit(int c) {
  return (((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'f')) ||
          ((c >= 'A') && (c <= 'F')))
             ? 1
             : 0;
}

int s21_toupper(int c) { return (c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c; }

int s21_tolower(int c) { return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c; }
