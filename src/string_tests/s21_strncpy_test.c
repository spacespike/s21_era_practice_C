#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strncpy_1) {
  char dest1[10] = "abcde";
  char dest2[10] = "abcde";
  char src[10] = "55555";
  char *result = s21_strncpy(dest1, src, 2);
  char *result_etalon = strncpy(dest2, src, 2);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_2) {
  char dest1[10] = "abcde";
  char dest2[10] = "abcde";
  char src[10] = "55555";
  char *result = s21_strncpy(dest1, src, 0);
  char *result_etalon = strncpy(dest2, src, 0);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_3) {
  char dest1[10] = "abcde";
  char dest2[10] = "abcde";
  char src[10] = "55555";
  char *result = s21_strncpy(dest1, src, strlen(dest1));
  char *result_etalon = strncpy(dest2, src, strlen(dest2));

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_4) {
  char dest1[10] = "abcde";
  char dest2[10] = "abcde";
  char src[10] = "55555";
  for (size_t n = 0; n <= strlen(dest1); n++) {
    char *result = s21_strncpy(dest2, src, n);
    char *result_etalon = strncpy(dest2, src, n);

    ck_assert_str_eq(result, result_etalon);
  }
}

START_TEST(test_s21_strncpy_5) {
  char dest1[10] = "abcde";
  char dest2[10] = "abcde";
  char src[10] = "333";
  char *result = s21_strncpy(dest1, src, 2);
  char *result_etalon = strncpy(dest2, src, 2);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_6) {
  char dest1[10] = "abcde";
  char dest2[10] = "abcde";
  char src[10] = "333";
  char *result = s21_strncpy(dest1, src, 5);
  char *result_etalon = strncpy(dest2, src, 5);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_7) {
  char dest1[10] = "abcde";
  char dest2[10] = "abcde";
  char src[10] = "333";
  char *result = s21_strncpy(dest1, src, strlen(dest1));
  char *result_etalon = strncpy(dest2, src, strlen(dest2));

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_8) {
  char dest1[10] = "abc";
  char dest2[10] = "abc";
  char src[10] = "55555";
  char *result = s21_strncpy(dest1, src, 2);
  char *result_etalon = strncpy(dest2, src, 2);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_9) {
  char dest1[10] = "abc";
  char dest2[10] = "abc";
  char src[10] = "55555";
  char *result = s21_strncpy(dest1, src, 10);
  char *result_etalon = strncpy(dest2, src, 10);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_10) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[10] = "55555";
  char *result = s21_strncpy(dest1, src, 10);
  char *result_etalon = strncpy(dest2, src, 10);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_11) {
  char dest1[10] = "abc";
  char dest2[10] = "abc";
  char src[10] = "";
  char *result = s21_strncpy(dest1, src, 10);
  char *result_etalon = strncpy(dest2, src, 10);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_12) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[10] = "";
  char *result = s21_strncpy(dest1, src, 10);
  char *result_etalon = strncpy(dest2, src, 10);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_13) {
  char dest1[10] = "\0\0\0";
  char dest2[10] = "\0\0\0";
  char src[10] = "4444";
  char *result = s21_strncpy(dest1, src, 10);
  char *result_etalon = strncpy(dest2, src, 10);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_14) {
  char dest1[10] = "\0\0\0";
  char dest2[10] = "\0\0\0";
  char src[10] = "4444";
  char *result = s21_strncpy(dest1, src, 2);
  char *result_etalon = strncpy(dest2, src, 2);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_15) {
  char dest1[10] = "123";
  char dest2[10] = "123";
  char src[10] = "\0\0\0\0";
  char *result = s21_strncpy(dest1, src, 2);
  char *result_etalon = strncpy(dest2, src, 2);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_16) {
  char dest1[10] = "123";
  char dest2[10] = "123";
  char src[10] = "\0\0\0\0";
  char *result = s21_strncpy(dest1, src, 5);
  char *result_etalon = strncpy(dest2, src, 5);

  ck_assert_str_eq(result, result_etalon);
}

START_TEST(test_s21_strncpy_17) {
  char dest1[10] = "12\045";
  char dest2[10] = "12\045";
  char src[10] = "a\0b\0";

  for (int n = 0; n <= 10; n++) {
    char *result = s21_strncpy(dest1, src, n);
    char *result_etalon = strncpy(dest2, src, n);

    ck_assert_str_eq(result, result_etalon);
  }
}

Suite *s21_strncpy_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncpy");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncpy_1);
  tcase_add_test(tc_core, test_s21_strncpy_2);
  tcase_add_test(tc_core, test_s21_strncpy_3);
  tcase_add_test(tc_core, test_s21_strncpy_4);
  tcase_add_test(tc_core, test_s21_strncpy_5);
  tcase_add_test(tc_core, test_s21_strncpy_6);
  tcase_add_test(tc_core, test_s21_strncpy_7);
  tcase_add_test(tc_core, test_s21_strncpy_8);
  tcase_add_test(tc_core, test_s21_strncpy_9);
  tcase_add_test(tc_core, test_s21_strncpy_10);
  tcase_add_test(tc_core, test_s21_strncpy_11);
  tcase_add_test(tc_core, test_s21_strncpy_12);
  tcase_add_test(tc_core, test_s21_strncpy_13);
  tcase_add_test(tc_core, test_s21_strncpy_14);
  tcase_add_test(tc_core, test_s21_strncpy_15);
  tcase_add_test(tc_core, test_s21_strncpy_16);
  tcase_add_test(tc_core, test_s21_strncpy_17);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_strncpy_suit();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}