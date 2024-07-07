#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *pointer = s21_NULL;
  while (*haystack) {
    if (*haystack == *needle) {
      char *temp_needle = (char *)needle;
      pointer = (char *)haystack;
      while (*haystack && *temp_needle) {
        if ((*haystack == *temp_needle)) {
          haystack++;
          temp_needle++;
        } else {
          pointer = s21_NULL;
          break;
        }
      }
      if (*haystack != '\0' && *temp_needle != '\0') {
        pointer = s21_NULL;
        continue;
      } else if (*haystack == '\0' && *temp_needle != '\0') {
        pointer = s21_NULL;
        break;
      }
      // else if(*haystack == '\0' && *temp_needle == '\0') {break;}
      // else if(*haystack != '\0' && *temp_needle == '\0') {break;}
      else
        break;

    } else if (*needle == '\0') {
      pointer = (char *)haystack;
      break;
    } else {
      haystack++;
      pointer = s21_NULL;
    }
  }
  return pointer;
}