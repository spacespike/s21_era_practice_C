#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_memset_1) {
  char in[] = "abcdef";
  char *result = (char *)s21_memset(in, (int)'1', 2);
  char *result_etalon = (char *)memset(in, (int)'1', 2);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_memset_2) {
  char in[] = "abcdef";
  char *result = (char *)s21_memset(in, (int)'1', sizeof(in));
  char *result_etalon = (char *)memset(in, (int)'1', sizeof(in));

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_memset_3) {
  char in[] = "abcdef";
  for (size_t n = 1; n <= sizeof(in); n++) {
    char *result = (char *)s21_memset(in, (int)'1', n);
    char *result_etalon = (char *)memset(in, (int)'1', n);

    ck_assert_str_eq(result, result_etalon);
  }
}
END_TEST

START_TEST(test_s21_memset_4) {
  char in[] = "abcdef";
  for (size_t n = 1; n <= sizeof(in); n++) {
    char *result = (char *)s21_memset(in, (int)'\0', n);
    char *result_etalon = (char *)memset(in, (int)'\0', n);

    ck_assert_str_eq(result, result_etalon);
  }
}
END_TEST

START_TEST(test_s21_memset_5) {
  char in[] = "\0\0\0\0\0";
  for (size_t n = 1; n <= sizeof(in); n++) {
    char *result = (char *)s21_memset(in, (int)'a', n);
    char *result_etalon = (char *)memset(in, (int)'a', n);

    ck_assert_str_eq(result, result_etalon);
  }
}
END_TEST

Suite *s21_memset_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memset");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memset_1);
  tcase_add_test(tc_core, test_s21_memset_2);
  tcase_add_test(tc_core, test_s21_memset_3);
  tcase_add_test(tc_core, test_s21_memset_4);
  tcase_add_test(tc_core, test_s21_memset_5);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_memset_suit();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}