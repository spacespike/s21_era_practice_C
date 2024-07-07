#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strchr_1) {
  char *result = s21_strchr("Hello, world!", 'l');
  char *result_etalon = strchr("Hello, world!", 'l');

  ck_assert(result == result_etalon);
  ck_assert_pstr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char *result = s21_strchr("", 'l');
  char *result_etalon = strchr("", 'l');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char *result = s21_strchr("\0", 'l');
  char *result_etalon = strchr("\0", 'l');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_4) {
  char *result = s21_strchr("abc", '\0');
  char *result_etalon = strchr("abc", '\0');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_5) {
  char *result = s21_strchr("abc", 'x');
  char *result_etalon = strchr("abc", 'x');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_6) {
  char *result = s21_strchr("", '\0');
  char *result_etalon = strchr("", '\0');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_7) {
  char *result = s21_strchr("abc", 'a');
  char *result_etalon = strchr("abc", 'a');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_8) {
  char *result = s21_strchr("abc", 'b');
  char *result_etalon = strchr("abc", 'b');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_9) {
  char *result = s21_strchr("abc", 'c');
  char *result_etalon = strchr("abc", 'c');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_10) {
  char *result = s21_strchr("abc", -1);
  char *result_etalon = strchr("abc", -1);

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_11) {
  char *result = s21_strchr("abbbbc", 'b');
  char *result_etalon = strchr("abbbbc", 'b');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_12) {
  char *result = s21_strchr("\0\0\0", 'b');
  char *result_etalon = strchr("\0\0\0", 'b');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_13) {
  char *result = s21_strchr("\0\0\0", '\0');
  char *result_etalon = strchr("\0\0\0", '\0');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_14) {
  char *result = s21_strchr("b\0\0\0", 'b');
  char *result_etalon = strchr("b\0\0\0", 'b');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_15) {
  char *result = s21_strchr("\0bb\0\0", 'b');
  char *result_etalon = strchr("\0bb\0\0", 'b');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_16) {
  char *result = s21_strchr("\0\0\0bb", 'b');
  char *result_etalon = strchr("\0\0\0bb", 'b');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_17) {
  char *result = s21_strchr("\0\0\0bb", '\0');
  char *result_etalon = strchr("\0\0\0bb", '\0');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_18) {
  char *result = s21_strchr("\0\0bb\0", '\0');
  char *result_etalon = strchr("\0\0bb\0", '\0');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_19) {
  char *result = s21_strchr("bb\0\0\0", '\0');
  char *result_etalon = strchr("bb\0\0\0", '\0');

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strchr_20) {
  char *result = s21_strchr("\0\0\0", -2);
  char *result_etalon = strchr("\0\0\0", -2);

  ck_assert_ptr_eq(result, result_etalon);
}
END_TEST

Suite *s21_string_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strchr");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strchr_1);
  tcase_add_test(tc_core, test_s21_strchr_2);
  tcase_add_test(tc_core, test_s21_strchr_3);
  tcase_add_test(tc_core, test_s21_strchr_4);
  tcase_add_test(tc_core, test_s21_strchr_5);
  tcase_add_test(tc_core, test_s21_strchr_6);
  tcase_add_test(tc_core, test_s21_strchr_7);
  tcase_add_test(tc_core, test_s21_strchr_8);
  tcase_add_test(tc_core, test_s21_strchr_9);
  tcase_add_test(tc_core, test_s21_strchr_10);
  tcase_add_test(tc_core, test_s21_strchr_11);
  tcase_add_test(tc_core, test_s21_strchr_12);
  tcase_add_test(tc_core, test_s21_strchr_13);
  tcase_add_test(tc_core, test_s21_strchr_14);
  tcase_add_test(tc_core, test_s21_strchr_15);
  tcase_add_test(tc_core, test_s21_strchr_16);
  tcase_add_test(tc_core, test_s21_strchr_17);
  tcase_add_test(tc_core, test_s21_strchr_18);
  tcase_add_test(tc_core, test_s21_strchr_19);
  tcase_add_test(tc_core, test_s21_strchr_20);
  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_string_suit();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}