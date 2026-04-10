#include <check.h>
#include <stdio.h>

#include "../../s21_string.h"

START_TEST(test_s21_isspace_1) {
  int c = ' ';
  int result = s21_isspace(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isspace_2) {
  int c = '\n';
  int result = s21_isspace(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isspace_3) {
  int c = 'a';
  int result = s21_isspace(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isspace_4) {
  char spaces[] = SPACES;
  for (char *p = spaces; *p; p++) {
    int c = (int)*p;
    int result = s21_isspace(c);
    ck_assert_int_eq(result, 1);
  }
}
END_TEST

START_TEST(test_s21_isspace_5) {
  char not_spaces[] = "abcd1234XYZ";
  for (char *p = not_spaces; *p; p++) {
    int c = (int)*p;
    int result = s21_isspace(c);
    ck_assert_int_eq(result, 0);
  }
}
END_TEST

START_TEST(test_s21_isspace_6) {
  for (int c = -127; c <= 0; c++) {
    int result = s21_isspace(c);
    ck_assert_int_eq(result, 0);
  }
}
END_TEST

START_TEST(test_s21_isdigit_1) {
  int c = '0';
  int result = s21_isdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isdigit_2) {
  int c = '5';
  int result = s21_isdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isdigit_3) {
  int c = '9';
  int result = s21_isdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isdigit_4) {
  int c = 'a';
  int result = s21_isdigit(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isdigit_5) {
  int c = 'Z';
  int result = s21_isdigit(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isdigit_6) {
  int c = '\n';
  int result = s21_isdigit(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isupper_1) {
  int c = 'A';
  int result = s21_isupper(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isupper_2) {
  int c = 'N';
  int result = s21_isupper(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isupper_3) {
  int c = 'Z';
  int result = s21_isupper(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isupper_4) {
  int c = 'a';
  int result = s21_isupper(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isupper_5) {
  int c = 'n';
  int result = s21_isupper(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isupper_6) {
  int c = '5';
  int result = s21_isupper(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_islower_1) {
  int c = 'a';
  int result = s21_islower(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_islower_2) {
  int c = 'n';
  int result = s21_islower(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_islower_3) {
  int c = 'z';
  int result = s21_islower(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_islower_4) {
  int c = 'A';
  int result = s21_islower(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_islower_5) {
  int c = 'N';
  int result = s21_islower(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_islower_6) {
  int c = '5';
  int result = s21_islower(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isalpha_1) {
  int c = 'a';
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isalpha_2) {
  int c = 'A';
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isalpha_3) {
  int c = 'z';
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isalpha_4) {
  int c = 'Z';
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isalpha_5) {
  int c = 'n';
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isalpha_6) {
  int c = 'N';
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isalpha_7) {
  int c = '5';
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isalpha_8) {
  int c = '\t';
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isalpha_9) {
  int c = -1;
  int result = s21_isalpha(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isxdigit_1) {
  int c = '0';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isxdigit_2) {
  int c = '5';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isxdigit_3) {
  int c = '9';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isxdigit_4) {
  int c = 'a';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isxdigit_5) {
  int c = 'A';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isxdigit_6) {
  int c = 'f';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isxdigit_7) {
  int c = 'F';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_isxdigit_8) {
  int c = 'j';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_isxdigit_9) {
  int c = '\n';
  int result = s21_isxdigit(c);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_toupper_1) {
  int c = 'a';
  int result = s21_toupper(c);
  ck_assert_int_eq(result, 'A');
}
END_TEST

START_TEST(test_s21_toupper_2) {
  int c = 'n';
  int result = s21_toupper(c);
  ck_assert_int_eq(result, 'N');
}
END_TEST

START_TEST(test_s21_toupper_3) {
  int c = 'z';
  int result = s21_toupper(c);
  ck_assert_int_eq(result, 'Z');
}
END_TEST

START_TEST(test_s21_toupper_4) {
  int c = 'A';
  int result = s21_toupper(c);
  ck_assert_int_eq(result, 'A');
}
END_TEST

START_TEST(test_s21_toupper_5) {
  int c = 'N';
  int result = s21_toupper(c);
  ck_assert_int_eq(result, 'N');
}
END_TEST

START_TEST(test_s21_toupper_6) {
  int c = '1';
  int result = s21_toupper(c);
  ck_assert_int_eq(result, '1');
}
END_TEST

START_TEST(test_s21_toupper_7) {
  int c = '\t';
  int result = s21_toupper(c);
  ck_assert_int_eq(result, '\t');
}
END_TEST

START_TEST(test_s21_tolower_1) {
  int c = 'A';
  int result = s21_tolower(c);
  ck_assert_int_eq(result, 'a');
}
END_TEST

START_TEST(test_s21_tolower_2) {
  int c = 'N';
  int result = s21_tolower(c);
  ck_assert_int_eq(result, 'n');
}
END_TEST

START_TEST(test_s21_tolower_3) {
  int c = 'Z';
  int result = s21_tolower(c);
  ck_assert_int_eq(result, 'z');
}
END_TEST

START_TEST(test_s21_tolower_4) {
  int c = 'a';
  int result = s21_tolower(c);
  ck_assert_int_eq(result, 'a');
}
END_TEST

START_TEST(test_s21_tolower_5) {
  int c = 'n';
  int result = s21_tolower(c);
  ck_assert_int_eq(result, 'n');
}
END_TEST

START_TEST(test_s21_tolower_6) {
  int c = '1';
  int result = s21_tolower(c);
  ck_assert_int_eq(result, '1');
}
END_TEST

START_TEST(test_s21_tolower_7) {
  int c = '\t';
  int result = s21_tolower(c);
  ck_assert_int_eq(result, '\t');
}
END_TEST

Suite *s21_ctype_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_ctype");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_isspace_1);
  tcase_add_test(tc_core, test_s21_isspace_2);
  tcase_add_test(tc_core, test_s21_isspace_3);
  tcase_add_test(tc_core, test_s21_isspace_4);
  tcase_add_test(tc_core, test_s21_isspace_5);
  tcase_add_test(tc_core, test_s21_isspace_6);

  tcase_add_test(tc_core, test_s21_isdigit_1);
  tcase_add_test(tc_core, test_s21_isdigit_2);
  tcase_add_test(tc_core, test_s21_isdigit_3);
  tcase_add_test(tc_core, test_s21_isdigit_4);
  tcase_add_test(tc_core, test_s21_isdigit_5);
  tcase_add_test(tc_core, test_s21_isdigit_6);

  tcase_add_test(tc_core, test_s21_isupper_1);
  tcase_add_test(tc_core, test_s21_isupper_2);
  tcase_add_test(tc_core, test_s21_isupper_3);
  tcase_add_test(tc_core, test_s21_isupper_4);
  tcase_add_test(tc_core, test_s21_isupper_5);
  tcase_add_test(tc_core, test_s21_isupper_6);

  tcase_add_test(tc_core, test_s21_islower_1);
  tcase_add_test(tc_core, test_s21_islower_2);
  tcase_add_test(tc_core, test_s21_islower_3);
  tcase_add_test(tc_core, test_s21_islower_4);
  tcase_add_test(tc_core, test_s21_islower_5);
  tcase_add_test(tc_core, test_s21_islower_6);

  tcase_add_test(tc_core, test_s21_isalpha_1);
  tcase_add_test(tc_core, test_s21_isalpha_2);
  tcase_add_test(tc_core, test_s21_isalpha_3);
  tcase_add_test(tc_core, test_s21_isalpha_4);
  tcase_add_test(tc_core, test_s21_isalpha_5);
  tcase_add_test(tc_core, test_s21_isalpha_6);
  tcase_add_test(tc_core, test_s21_isalpha_7);
  tcase_add_test(tc_core, test_s21_isalpha_8);
  tcase_add_test(tc_core, test_s21_isalpha_9);

  tcase_add_test(tc_core, test_s21_isxdigit_1);
  tcase_add_test(tc_core, test_s21_isxdigit_2);
  tcase_add_test(tc_core, test_s21_isxdigit_3);
  tcase_add_test(tc_core, test_s21_isxdigit_4);
  tcase_add_test(tc_core, test_s21_isxdigit_5);
  tcase_add_test(tc_core, test_s21_isxdigit_6);
  tcase_add_test(tc_core, test_s21_isxdigit_7);
  tcase_add_test(tc_core, test_s21_isxdigit_8);
  tcase_add_test(tc_core, test_s21_isxdigit_9);

  tcase_add_test(tc_core, test_s21_toupper_1);
  tcase_add_test(tc_core, test_s21_toupper_2);
  tcase_add_test(tc_core, test_s21_toupper_3);
  tcase_add_test(tc_core, test_s21_toupper_4);
  tcase_add_test(tc_core, test_s21_toupper_5);
  tcase_add_test(tc_core, test_s21_toupper_6);
  tcase_add_test(tc_core, test_s21_toupper_7);

  tcase_add_test(tc_core, test_s21_tolower_1);
  tcase_add_test(tc_core, test_s21_tolower_2);
  tcase_add_test(tc_core, test_s21_tolower_3);
  tcase_add_test(tc_core, test_s21_tolower_4);
  tcase_add_test(tc_core, test_s21_tolower_5);
  tcase_add_test(tc_core, test_s21_tolower_6);
  tcase_add_test(tc_core, test_s21_tolower_7);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_ctype_suit();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
