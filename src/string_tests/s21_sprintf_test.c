#include "../s21_sprintf.h"

#include <check.h>
#include <stdio.h>

//
// init
//

START_TEST(test_s21_sprintf_init_atributes_1) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);
}
END_TEST

START_TEST(test_s21_sprintf_init_atributes_2) {
  s21_atributes atr;

  atr.fl_minus = 1;
  atr.fl_plus = 1;
  atr.fl_space = 1;
  atr.fl_sharp = 1;
  atr.fl_zero = 10;
  atr.fl_asterisk_width = 1;
  atr.fl_asterisk_precision = 1;
  atr.width = 100;
  atr.precision = 100;
  atr.length = 'L';
  atr.length_2 = 10;
  atr.specifier = 'd';

  s21_init_atributes(&atr);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);
}
END_TEST

START_TEST(test_s21_init_1) {
  s21_atributes atr;
  char *out_str = malloc((s21_BUFSIZ + 1) * sizeof(char));

  s21_init(&out_str, &atr);

  ck_assert_int_eq(*out_str, '\0');

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  if (out_str != s21_NULL) free(out_str);
}
END_TEST

Suite *s21_sprintf_init_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf_init");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_init_atributes_1);
  tcase_add_test(tc_core, test_s21_sprintf_init_atributes_2);
  tcase_add_test(tc_core, test_s21_init_1);

  suite_add_tcase(s, tc_core);

  return s;
}

//
// parse_format
//

START_TEST(test_s21_parse_flags_1) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "+";
  char *pfirst = format;

  int is_found = s21_parse_flags(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 1);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
}
END_TEST

START_TEST(test_s21_parse_flags_2) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = SPEC_FLAGS;

  int is_found = s21_parse_flags(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 1);
  ck_assert_int_eq(atr.fl_plus, 1);
  ck_assert_int_eq(atr.fl_space, 1);
  ck_assert_int_eq(atr.fl_sharp, 1);
  ck_assert_int_eq(atr.fl_zero, 1);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);
}
END_TEST

START_TEST(test_s21_parse_flags_3) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "-+ #0aaa";
  char *pfirst = format;

  int is_found = s21_parse_flags(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 1);
  ck_assert_int_eq(atr.fl_plus, 1);
  ck_assert_int_eq(atr.fl_space, 1);
  ck_assert_int_eq(atr.fl_sharp, 1);
  ck_assert_int_eq(atr.fl_zero, 1);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 5);
  ck_assert_str_eq(format, "aaa");
}
END_TEST

START_TEST(test_s21_parse_flags_4) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "aaa-+ #0";
  char *pfirst = format;

  int is_found = s21_parse_flags(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 0);
  ck_assert_str_eq(format, "aaa-+ #0");
}
END_TEST

START_TEST(test_s21_parse_flags_5) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "++++";
  char *pfirst = format;

  int is_found = s21_parse_flags(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 1);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 4);
  ck_assert_str_eq(format, "");
}
END_TEST

START_TEST(test_s21_parse_flags_6) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "++++000";
  char *pfirst = format;

  int is_found = s21_parse_flags(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 1);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 1);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 7);
  ck_assert_str_eq(format, "");
}
END_TEST

START_TEST(test_s21_parse_flags_7) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "++++a000";
  char *pfirst = format;

  int is_found = s21_parse_flags(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 1);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 4);
  ck_assert_str_eq(format, "a000");
}
END_TEST

START_TEST(test_s21_parse_flags_8) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "";

  int is_found = s21_parse_flags(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);
}
END_TEST

START_TEST(test_s21_parse_width_1) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "3";
  char *pfirst = format;

  int is_found = s21_parse_width(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 3);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
}
END_TEST

START_TEST(test_s21_parse_width_2) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "";

  int is_found = s21_parse_width(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);
}
END_TEST

START_TEST(test_s21_parse_width_3) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "11";
  char *pfirst = format;

  int is_found = s21_parse_width(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 11);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 2);
}
END_TEST

START_TEST(test_s21_parse_width_4) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "*";
  char *pfirst = format;

  int is_found = s21_parse_width(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 1);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
}
END_TEST

START_TEST(test_s21_parse_width_5) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "*55";
  char *pfirst = format;

  int is_found = s21_parse_width(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 1);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
  ck_assert_str_eq(format, "55");
}
END_TEST

START_TEST(test_s21_parse_width_6) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "55*";
  char *pfirst = format;

  int is_found = s21_parse_width(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 55);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 2);
  ck_assert_str_eq(format, "*");
}
END_TEST

START_TEST(test_s21_parse_width_7) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "aaa55*";
  char *pfirst = format;

  int is_found = s21_parse_width(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 0);
  ck_assert_str_eq(format, "aaa55*");
}
END_TEST

START_TEST(test_s21_parse_precision_1) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = ".3";
  char *pfirst = format;

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, 3);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 2);
}
END_TEST

START_TEST(test_s21_parse_precision_2) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "";

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);
}
END_TEST

START_TEST(test_s21_parse_precision_3) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = ".11";
  char *pfirst = format;

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, 11);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 3);
}
END_TEST

START_TEST(test_s21_parse_precision_4) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = ".*";
  char *pfirst = format;

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 1);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 2);
}
END_TEST

START_TEST(test_s21_parse_precision_5) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = ".*55";
  char *pfirst = format;

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 1);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 2);
  ck_assert_str_eq(format, "55");
}
END_TEST

START_TEST(test_s21_parse_precision_6) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = ".55*";
  char *pfirst = format;

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, 55);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 3);
  ck_assert_str_eq(format, "*");
}
END_TEST

START_TEST(test_s21_parse_precision_7) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "aaa55*";
  char *pfirst = format;

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 0);
  ck_assert_str_eq(format, "aaa55*");
}
END_TEST

START_TEST(test_s21_parse_precision_8) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = ".aaa55*";
  char *pfirst = format;

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, 0);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
  ck_assert_str_eq(format, "aaa55*");
}
END_TEST

START_TEST(test_s21_parse_precision_9) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = ".";
  char *pfirst = format;

  int is_found = s21_parse_precision(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, 0);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
  ck_assert_str_eq(format, "");
}
END_TEST

START_TEST(test_s21_parse_length_1) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "hd";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'h');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
  ck_assert_str_eq(format, "d");
}
END_TEST

START_TEST(test_s21_parse_length_2) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "ld";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'l');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
  ck_assert_str_eq(format, "d");
}
END_TEST

START_TEST(test_s21_parse_length_3) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "Lf";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'L');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
  ck_assert_str_eq(format, "f");
}
END_TEST

START_TEST(test_s21_parse_length_4) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "hhd";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'h');
  ck_assert_int_eq(atr.length_2, 'h');
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 2);
  ck_assert_str_eq(format, "d");
}
END_TEST

START_TEST(test_s21_parse_length_5) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "lld";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'l');
  ck_assert_int_eq(atr.length_2, 'l');
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 2);
  ck_assert_str_eq(format, "d");
}
END_TEST

START_TEST(test_s21_parse_length_6) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "llld";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'l');
  ck_assert_int_eq(atr.length_2, 'l');
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 2);
  ck_assert_str_eq(format, "ld");
}
END_TEST

START_TEST(test_s21_parse_length_7) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "lLd";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'l');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
  ck_assert_str_eq(format, "Ld");
}
END_TEST

START_TEST(test_s21_parse_length_8) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "hld";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'h');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 1);
  ck_assert_str_eq(format, "ld");
}
END_TEST

START_TEST(test_s21_parse_length_9) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "alld";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 0);
  ck_assert_str_eq(format, "alld");
}
END_TEST

START_TEST(test_s21_parse_length_10) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "";
  char *pfirst = format;

  int is_found = s21_parse_length(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_int_eq(format - pfirst, 0);
  ck_assert_str_eq(format, "");
}
END_TEST

START_TEST(test_s21_parse_specifier_1) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "d";

  int is_found = s21_parse_specifier(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 'd');

  ck_assert_str_eq(format, "d");
}
END_TEST

START_TEST(test_s21_parse_specifier_2) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *specs = SPECIFIERS;

  for (char *p = specs; *p != '\0'; p++) {
    char copy[2];
    char *format = s21_strncpy(copy, p, 1);

    int is_found = s21_parse_specifier(&atr, &format);

    ck_assert_int_eq(is_found, 1);
    ck_assert_int_eq(atr.specifier, *p);
  }
}
END_TEST

START_TEST(test_s21_parse_specifier_3) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "123d";

  int is_found = s21_parse_specifier(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_str_eq(format, "123d");
}
END_TEST

START_TEST(test_s21_parse_specifier_4) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "";

  int is_found = s21_parse_specifier(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_str_eq(format, "");
}
END_TEST

START_TEST(test_s21_parse_specifier_5) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "\0\0\0";

  int is_found = s21_parse_specifier(&atr, &format);

  ck_assert_int_eq(is_found, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_str_eq(format, "\0\0\0");
}
END_TEST

START_TEST(test_s21_parse_specifier_6) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "E123d %s";

  int is_found = s21_parse_specifier(&atr, &format);

  ck_assert_int_eq(is_found, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 'E');

  ck_assert_str_eq(format, "E123d %s");
}
END_TEST

START_TEST(test_s21_parse_format_1) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%s";

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 's');

  ck_assert_str_eq(format, "s");
}
END_TEST

START_TEST(test_s21_parse_format_2) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "s";

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_str_eq(format, "s");
}
END_TEST

START_TEST(test_s21_parse_format_3) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%%";

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 1);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, '%');

  ck_assert_str_eq(format, "%");
}
END_TEST

START_TEST(test_s21_parse_format_4) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%-15.10s987";

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 7);

  ck_assert_int_eq(atr.fl_minus, 1);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 15);
  ck_assert_int_eq(atr.precision, 10);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 's');

  ck_assert_str_eq(format, "s987");
}
END_TEST

START_TEST(test_s21_parse_format_5) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%-15.10Ls987"; // wrong: lenth 'L' for 's'

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 8);

  ck_assert_int_eq(atr.fl_minus, 1);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 15);
  ck_assert_int_eq(atr.precision, 10);
  ck_assert_int_eq(atr.length, 'L');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 's');

  ck_assert_str_eq(format, "s987");
}
END_TEST

START_TEST(test_s21_parse_format_6) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%+15s";

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 4);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 1);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 15);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 's');

  ck_assert_str_eq(format, "s");
}
END_TEST

START_TEST(test_s21_parse_format_7) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%0.s";

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 3);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 1);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, 0);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 's');

  ck_assert_str_eq(format, "s");
}
END_TEST

START_TEST(test_s21_parse_format_8) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "% *.*lld";

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 7);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 1);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 1);
  ck_assert_int_eq(atr.fl_asterisk_precision, 1);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'l');
  ck_assert_int_eq(atr.length_2, 'l');
  ck_assert_int_eq(atr.specifier, 'd');

  ck_assert_str_eq(format, "d");
}
END_TEST

START_TEST(test_s21_parse_format_9) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "% *.*hhi";

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 7);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 1);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 1);
  ck_assert_int_eq(atr.fl_asterisk_precision, 1);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'h');
  ck_assert_int_eq(atr.length_2, 'h');
  ck_assert_int_eq(atr.specifier, 'i');

  ck_assert_str_eq(format, "i");
}
END_TEST

START_TEST(test_s21_parse_format_10) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "% *.*hli"; // wrong: 'h' & 'l' together

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 1);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 1);
  ck_assert_int_eq(atr.fl_asterisk_precision, 1);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, 'h');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_str_eq(format, "li");
}
END_TEST

START_TEST(test_s21_parse_format_11) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%#aF"; 

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 1);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_str_eq(format, "aF");
}
END_TEST

START_TEST(test_s21_parse_format_12) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%#10.aF"; 

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 1);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 10);
  ck_assert_int_eq(atr.precision, 0);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_str_eq(format, "aF");
}
END_TEST

START_TEST(test_s21_parse_format_13) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "%-10.2lf"; 

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 7);

  ck_assert_int_eq(atr.fl_minus, 1);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 10);
  ck_assert_int_eq(atr.precision, 2);
  ck_assert_int_eq(atr.length, 'l');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 'f');

  ck_assert_str_eq(format, "f");
}
END_TEST

START_TEST(test_s21_parse_format_14) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = "% 4.6hd"; 

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 6);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 1);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, 4);
  ck_assert_int_eq(atr.precision, 6);
  ck_assert_int_eq(atr.length, 'h');
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, 'd');

  ck_assert_str_eq(format, "d");
}
END_TEST

START_TEST(test_s21_parse_format_15) {
  s21_atributes atr;
  s21_init_atributes(&atr);

  char *format = " 4.6hf"; 

  int prototype_len = s21_parse_format(&format, &atr);

  ck_assert_int_eq(prototype_len, 0);

  ck_assert_int_eq(atr.fl_minus, 0);
  ck_assert_int_eq(atr.fl_plus, 0);
  ck_assert_int_eq(atr.fl_space, 0);
  ck_assert_int_eq(atr.fl_sharp, 0);
  ck_assert_int_eq(atr.fl_zero, 0);
  ck_assert_int_eq(atr.fl_asterisk_width, 0);
  ck_assert_int_eq(atr.fl_asterisk_precision, 0);
  ck_assert_int_eq(atr.width, -1);
  ck_assert_int_eq(atr.precision, -1);
  ck_assert_int_eq(atr.length, -1);
  ck_assert_int_eq(atr.length_2, -1);
  ck_assert_int_eq(atr.specifier, -1);

  ck_assert_str_eq(format, " 4.6hf");
}
END_TEST

Suite *s21_sprintf_parse_format_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf_parse_format");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_parse_flags_1);
  tcase_add_test(tc_core, test_s21_parse_flags_2);
  tcase_add_test(tc_core, test_s21_parse_flags_3);
  tcase_add_test(tc_core, test_s21_parse_flags_4);
  tcase_add_test(tc_core, test_s21_parse_flags_5);
  tcase_add_test(tc_core, test_s21_parse_flags_6);
  tcase_add_test(tc_core, test_s21_parse_flags_7);
  tcase_add_test(tc_core, test_s21_parse_flags_8);

  tcase_add_test(tc_core, test_s21_parse_width_1);
  tcase_add_test(tc_core, test_s21_parse_width_2);
  tcase_add_test(tc_core, test_s21_parse_width_3);
  tcase_add_test(tc_core, test_s21_parse_width_4);
  tcase_add_test(tc_core, test_s21_parse_width_5);
  tcase_add_test(tc_core, test_s21_parse_width_6);
  tcase_add_test(tc_core, test_s21_parse_width_7);

  tcase_add_test(tc_core, test_s21_parse_precision_1);
  tcase_add_test(tc_core, test_s21_parse_precision_2);
  tcase_add_test(tc_core, test_s21_parse_precision_3);
  tcase_add_test(tc_core, test_s21_parse_precision_4);
  tcase_add_test(tc_core, test_s21_parse_precision_5);
  tcase_add_test(tc_core, test_s21_parse_precision_6);
  tcase_add_test(tc_core, test_s21_parse_precision_7);
  tcase_add_test(tc_core, test_s21_parse_precision_8);
  tcase_add_test(tc_core, test_s21_parse_precision_9);

  tcase_add_test(tc_core, test_s21_parse_length_1);
  tcase_add_test(tc_core, test_s21_parse_length_2);
  tcase_add_test(tc_core, test_s21_parse_length_3);
  tcase_add_test(tc_core, test_s21_parse_length_4);
  tcase_add_test(tc_core, test_s21_parse_length_5);
  tcase_add_test(tc_core, test_s21_parse_length_6);
  tcase_add_test(tc_core, test_s21_parse_length_7);
  tcase_add_test(tc_core, test_s21_parse_length_8);
  tcase_add_test(tc_core, test_s21_parse_length_9);
  tcase_add_test(tc_core, test_s21_parse_length_10);

  tcase_add_test(tc_core, test_s21_parse_specifier_1);
  tcase_add_test(tc_core, test_s21_parse_specifier_2);
  tcase_add_test(tc_core, test_s21_parse_specifier_3);
  tcase_add_test(tc_core, test_s21_parse_specifier_4);
  tcase_add_test(tc_core, test_s21_parse_specifier_5);
  tcase_add_test(tc_core, test_s21_parse_specifier_6);

  tcase_add_test(tc_core, test_s21_parse_format_1);
  tcase_add_test(tc_core, test_s21_parse_format_2);
  tcase_add_test(tc_core, test_s21_parse_format_3);
  tcase_add_test(tc_core, test_s21_parse_format_4);
  tcase_add_test(tc_core, test_s21_parse_format_5);
  tcase_add_test(tc_core, test_s21_parse_format_6);
  tcase_add_test(tc_core, test_s21_parse_format_7);
  tcase_add_test(tc_core, test_s21_parse_format_8);
  tcase_add_test(tc_core, test_s21_parse_format_9);
  tcase_add_test(tc_core, test_s21_parse_format_10);
  tcase_add_test(tc_core, test_s21_parse_format_11);
  tcase_add_test(tc_core, test_s21_parse_format_12);
  tcase_add_test(tc_core, test_s21_parse_format_13);
  tcase_add_test(tc_core, test_s21_parse_format_14);
  tcase_add_test(tc_core, test_s21_parse_format_15);

  suite_add_tcase(s, tc_core);

  return s;
}

//
// add_to_string
//

START_TEST(test_s21_add_char_to_str_1) {
  char *out_str = (char *)malloc((s21_BUFSIZ + 1) * sizeof(char));

  char *run_str = out_str;
  run_str[0] = 'a';
  run_str[1] = 'b';
  run_str[2] = 'c';

  char symb = 'z';
  int str_len = 3;
  run_str += str_len;

  s21_add_char_to_str(&run_str, symb, &str_len);
  *run_str = '\0';

  ck_assert_str_eq(out_str, "abcz");
  ck_assert_str_eq(run_str, "");
  ck_assert_int_eq(str_len, 4);

  if (out_str != s21_NULL) free(out_str);
}
END_TEST

START_TEST(test_s21_add_char_to_str_2) {
  char *out_str = (char *)malloc((s21_BUFSIZ + 1) * sizeof(char));

  char *run_str = out_str;
  run_str[0] = 'a';
  run_str[1] = 'b';
  run_str[2] = 'c';

  char symb = 'z';
  int str_len = 3;
  run_str += str_len;

  s21_add_char_to_str(&run_str, symb, &str_len);
  s21_add_char_to_str(&run_str, symb, &str_len);
  s21_add_char_to_str(&run_str, symb, &str_len);
  *run_str = '\0';

  ck_assert_str_eq(out_str, "abczzz");
  ck_assert_str_eq(run_str, "");
  ck_assert_int_eq(str_len, 6);

  if (out_str != s21_NULL) free(out_str);
}
END_TEST

START_TEST(test_s21_add_char_to_str_3) {
  char *out_str = (char *)malloc((s21_BUFSIZ + 1) * sizeof(char));
  char *run_str = out_str;

  char symb = 'z';
  int str_len = 0;
  run_str += str_len;

  s21_add_char_to_str(&run_str, symb, &str_len);
  *run_str = '\0';

  ck_assert_str_eq(out_str, "z");
  ck_assert_str_eq(run_str, "");
  ck_assert_int_eq(str_len, 1);

  if (out_str != s21_NULL) free(out_str);
}
END_TEST

START_TEST(test_s21_add_char_to_str_4) {
  char *out_str = (char *)malloc((s21_BUFSIZ + 1) * sizeof(char));
  char *run_str = out_str;

  char symb = 'z';
  int str_len = 0;
  run_str += str_len;

  s21_add_char_to_str(&run_str, symb, &str_len);
  s21_add_char_to_str(&run_str, symb, &str_len);
  s21_add_char_to_str(&run_str, symb, &str_len);
  *run_str = '\0';

  ck_assert_str_eq(out_str, "zzz");
  ck_assert_str_eq(run_str, "");
  ck_assert_int_eq(str_len, 3);

  if (out_str != s21_NULL) free(out_str);
}
END_TEST

START_TEST(test_s21_add_char_to_str_5) {
  char *out_str = (char *)malloc((s21_BUFSIZ + 1) * sizeof(char));
  char *run_str = out_str;

  char symb = 'z';
  int str_len = 0;
  *run_str = '\0';

  s21_add_char_to_str(&run_str, symb, &str_len);
  *run_str = '\0';

  ck_assert_str_eq(out_str, "z");
  ck_assert_str_eq(run_str, "");
  ck_assert_int_eq(str_len, 1);

  if (out_str != s21_NULL) free(out_str);
}
END_TEST

START_TEST(test_s21_add_char_to_str_6) {
  char *out_str = (char *)malloc((s21_BUFSIZ + 1) * sizeof(char));
  char *run_str = out_str;

  for (int i = 0; i <= s21_BUFSIZ; i++, run_str++) {
    *run_str = 'a';
  }

  char *etalon = out_str;

  char symb = 'z';
  int str_len = s21_BUFSIZ;

  // over s21_BUFSIZ
  s21_add_char_to_str(&run_str, symb, &str_len);
  s21_add_char_to_str(&run_str, symb, &str_len);
  s21_add_char_to_str(&run_str, symb, &str_len);
  *run_str = '\0';

  ck_assert_str_eq(out_str, etalon);
  ck_assert_str_eq(run_str, "");
  ck_assert_int_eq(str_len, s21_BUFSIZ);

  if (out_str != s21_NULL) free(out_str);
}
END_TEST

Suite *s21_sprintf_add_to_str_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf_add_to_str");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_add_char_to_str_1);
  tcase_add_test(tc_core, test_s21_add_char_to_str_2);
  tcase_add_test(tc_core, test_s21_add_char_to_str_3);
  tcase_add_test(tc_core, test_s21_add_char_to_str_4);
  tcase_add_test(tc_core, test_s21_add_char_to_str_5);
  tcase_add_test(tc_core, test_s21_add_char_to_str_6);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_sprintf_init_suit();
  sr = srunner_create(s);

  srunner_add_suite(sr, s21_sprintf_parse_format_suit());
  srunner_add_suite(sr, s21_sprintf_add_to_str_suit());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}