#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strpbrk_1) {
  char *result = s21_strpbrk("0123456789", "369");
  char *result_etalon = strpbrk("0123456789", "369");

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_2) {
  char *result = s21_strpbrk("0123456789", "654");
  char *result_etalon = strpbrk("0123456789", "654");

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_3) {
  char *result = s21_strpbrk("0123456789", "abc");
  char *result_etalon = strpbrk("0123456789", "abc");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_4) {
  char *result = s21_strpbrk("", "abc");
  char *result_etalon = strpbrk("", "abc");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_5) {
  char *result = s21_strpbrk("", "");
  char *result_etalon = strpbrk("", "");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_6) {
  char *result = s21_strpbrk("\0", "");
  char *result_etalon = strpbrk("\0", "");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_7) {
  char *result = s21_strpbrk("\0", "\0");
  char *result_etalon = strpbrk("\0", "\0");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_8) {
  char *result = s21_strpbrk("\0\0", "\0");
  char *result_etalon = strpbrk("\0\0", "\0");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_9) {
  char *result = s21_strpbrk("aaa", "\0");
  char *result_etalon = strpbrk("aaa", "\0");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_10) {
  char *result = s21_strpbrk("aaa333", "a");
  char *result_etalon = strpbrk("aaa333", "a");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_11) {
  char *result = s21_strpbrk("aaa333", "3b");
  char *result_etalon = strpbrk("aaa333", "3b");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_12) {
  char *result = s21_strpbrk("aa\0a333", "3b");
  char *result_etalon = strpbrk("aa\0a333", "3b");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_13) {
  char *result = s21_strpbrk("aaa\0333", "3b");
  char *result_etalon = strpbrk("aaa\0333", "3b");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_14) {
  char *result = s21_strpbrk("aaa3\033", "3b");
  char *result_etalon = strpbrk("aaa3\033", "3b");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_15) {
  char *result = s21_strpbrk("aaa33\03", "3b");
  char *result_etalon = strpbrk("aaa33\03", "3b");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_16) {
  char *result = s21_strpbrk("aaac33\03", "3b\0c");
  char *result_etalon = strpbrk("aaac33\03", "3b\0c");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_17) {
  char *result = s21_strpbrk("abc", "B");
  char *result_etalon = strpbrk("abc", "B");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_18) {
  char *result = s21_strpbrk("ab\nc", "b");
  char *result_etalon = strpbrk("ab\nc", "b");

  ck_assert_pstr_eq(result, result_etalon);
}

START_TEST(test_s21_strpbrk_19) {
  char *result = s21_strpbrk("ab\nc", "\n");
  char *result_etalon = strpbrk("ab\nc", "\n");

  ck_assert_pstr_eq(result, result_etalon);
}

Suite *s21_strpbrk_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strpbrk");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_1);
  tcase_add_test(tc_core, test_s21_strpbrk_2);
  tcase_add_test(tc_core, test_s21_strpbrk_3);
  tcase_add_test(tc_core, test_s21_strpbrk_4);
  tcase_add_test(tc_core, test_s21_strpbrk_5);
  tcase_add_test(tc_core, test_s21_strpbrk_6);
  tcase_add_test(tc_core, test_s21_strpbrk_7);
  tcase_add_test(tc_core, test_s21_strpbrk_8);
  tcase_add_test(tc_core, test_s21_strpbrk_9);
  tcase_add_test(tc_core, test_s21_strpbrk_10);
  tcase_add_test(tc_core, test_s21_strpbrk_11);
  tcase_add_test(tc_core, test_s21_strpbrk_12);
  tcase_add_test(tc_core, test_s21_strpbrk_13);
  tcase_add_test(tc_core, test_s21_strpbrk_14);
  tcase_add_test(tc_core, test_s21_strpbrk_15);
  tcase_add_test(tc_core, test_s21_strpbrk_16);
  tcase_add_test(tc_core, test_s21_strpbrk_17);
  tcase_add_test(tc_core, test_s21_strpbrk_18);
  tcase_add_test(tc_core, test_s21_strpbrk_19);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_strpbrk_suit();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
