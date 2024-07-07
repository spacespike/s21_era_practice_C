#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strerror_0) {
  char *result = s21_strerror(0);
  char *result_etalon = strerror(0);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_1) {
  char *result = s21_strerror(1);
  char *result_etalon = strerror(1);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_2) {
  char *result = s21_strerror(2);
  char *result_etalon = strerror(2);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_21) {
  char *result = s21_strerror(21);
  char *result_etalon = strerror(21);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_106) {
  char *result = s21_strerror(106);
  char *result_etalon = strerror(106);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_107) {
  char *result = s21_strerror(107);
  char *result_etalon = strerror(107);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_134) {
  char *result = s21_strerror(134);
  char *result_etalon = strerror(134);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_135) {
  char *result = s21_strerror(135);
  char *result_etalon = strerror(135);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_300) {
  char *result = s21_strerror(300);
  char *result_etalon = strerror(300);

  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_strerror_3_106) {
  for (int n = 3; n < 107; n++) {
    char *result = s21_strerror(n);
    char *result_etalon = strerror(n);

    ck_assert_str_eq(result, result_etalon);
  }
}
END_TEST

START_TEST(test_s21_strerror_107_134) {
  for (int n = 107; n < 134; n++) {
    char *result = s21_strerror(n);
    char *result_etalon = strerror(n);

    ck_assert_str_eq(result, result_etalon);
  }
}
END_TEST

Suite *s21_strerror_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strerror");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strerror_0);
  tcase_add_test(tc_core, test_s21_strerror_1);
  tcase_add_test(tc_core, test_s21_strerror_2);
  tcase_add_test(tc_core, test_s21_strerror_21);
  tcase_add_test(tc_core, test_s21_strerror_106);
  tcase_add_test(tc_core, test_s21_strerror_107);
  tcase_add_test(tc_core, test_s21_strerror_134);
  tcase_add_test(tc_core, test_s21_strerror_135);
  tcase_add_test(tc_core, test_s21_strerror_300);
  tcase_add_test(tc_core, test_s21_strerror_3_106);
  tcase_add_test(tc_core, test_s21_strerror_107_134);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_strerror_suit();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}