#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strstr_1) {
  char *result = s21_strstr("aaabbbccc", "aa");
  char *result_etalon = strstr("aaabbbccc", "aa");

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_2) {
  char *result = s21_strstr("aaabbbccc", "bb");
  char *result_etalon = strstr("aaabbbccc", "bb");

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_3) {
  char *result = s21_strstr("aaabbbccc", "cc");
  char *result_etalon = strstr("aaabbbccc", "cc");

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_4) {
  char *result = s21_strstr("aaabbbccc", "dd");
  char *result_etalon = strstr("aaabbbccc", "dd");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_5) {
  char *result = s21_strstr("aaabbbccc", "");
  char *result_etalon = strstr("aaabbbccc", "");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_6) {
  char *result = s21_strstr("aaabbbccc", "\0");
  char *result_etalon = strstr("aaabbbccc", "\0");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_7) {
  char *result = s21_strstr("aaabcd", "abc");
  char *result_etalon = strstr("aaabcd", "abc");

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_8) {
  char *result = s21_strstr("aaabc", "abc");
  char *result_etalon = strstr("aaabc", "abc");

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_9) {
  char *result = s21_strstr("abc", "abcd");
  char *result_etalon = strstr("abc", "abcd");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_10) {
  char *result = s21_strstr("aaabcad", "abcd");
  char *result_etalon = strstr("aaabcad", "abcd");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_11) {
  char *result = s21_strstr("aaabaaabcdaaa", "abc");
  char *result_etalon = strstr("aaabaaabcdaaa", "abc");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_12) {
  char *result = s21_strstr("", "abc");
  char *result_etalon = strstr("", "abc");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_13) {
  char *result = s21_strstr("\0", "abc");
  char *result_etalon = strstr("\0", "abc");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_14) {
  char *result = s21_strstr("aaa\0bbb", "aa");
  char *result_etalon = strstr("aaa\0bbb", "aa");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_15) {
  char *result = s21_strstr("aaa\0bbb", "bb");
  char *result_etalon = strstr("aaa\0bbb", "bb");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strstr_16) {
  char *result = s21_strstr("aaabbb", "b\0");
  char *result_etalon = strstr("aaabbb", "b\0");

  ck_assert_pstr_eq(result, result_etalon);
}

Suite *s21_strstr_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strstr");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strstr_1);
  tcase_add_test(tc_core, test_s21_strstr_2);
  tcase_add_test(tc_core, test_s21_strstr_3);
  tcase_add_test(tc_core, test_s21_strstr_4);
  tcase_add_test(tc_core, test_s21_strstr_5);
  tcase_add_test(tc_core, test_s21_strstr_6);
  tcase_add_test(tc_core, test_s21_strstr_7);
  tcase_add_test(tc_core, test_s21_strstr_8);
  tcase_add_test(tc_core, test_s21_strstr_9);
  tcase_add_test(tc_core, test_s21_strstr_10);
  tcase_add_test(tc_core, test_s21_strstr_11);
  tcase_add_test(tc_core, test_s21_strstr_12);
  tcase_add_test(tc_core, test_s21_strstr_13);
  tcase_add_test(tc_core, test_s21_strstr_14);
  tcase_add_test(tc_core, test_s21_strstr_15);
  tcase_add_test(tc_core, test_s21_strstr_16);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_strstr_suit();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}