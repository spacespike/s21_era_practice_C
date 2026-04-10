#ifndef S21_STRING_H
#define S21_STRING_H
#define s21_NULL ((void *)0)

#include <limits.h>

typedef unsigned long long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dst, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sscanf(const char *str, const char *format, ...);
int s21_sprintf(char *str, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

//
// extra
//

// like ctype
#define SPACES " \f\n\r\t\v"
int s21_isspace(int c);
int s21_isdigit(int c);
int s21_isupper(int c);
int s21_islower(int c);
int s21_isalpha(int c);
int s21_isxdigit(int c);
int s21_toupper(int c);
int s21_tolower(int c);

// like stdlib
int s21_atoi(char str[]);

void s21_itoab(long long int n, char *s, int base);
void s21_uitoab(unsigned long long int n, char *s, int base);
void s21_itoa(long long int n, char *s);
void s21_uitoa(unsigned long long int n, char *s);
void s21_itoa8(unsigned long long int n, char *s);
void s21_itoa16(unsigned long long int n, char *s);
void s21_reverse_plus_one(char *s);
void s21_reverse_plus_one_base(char *s, int base);
int s21_is_numeric(int digit);
void s21_reverse_str(char *s);

#endif
