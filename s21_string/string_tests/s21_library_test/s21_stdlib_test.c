#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../s21_string.h"

START_TEST(test_s21_atoi_1) {
  char s[] = "123";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_2) {
  char s[] = "-123";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_3) {
  char s[] = "+123";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_4) {
  char s[] = "0";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_5) {
  char s[] = "   -123";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_6) {
  char s[] = "-000123";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_7) {
  char s[] = "123.45";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_8) {
  char s[] = "ab123";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_9) {
  char s[] = "2147483647";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_10) {
  char s[] = "2147483648";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_11) {
  char s[] = "-2147483648";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_atoi_12) {
  char s[] = "-2147483649";
  int result = s21_atoi(s);
  int result_etalon = atoi(s);
  ck_assert_int_eq(result, result_etalon);
}
END_TEST

Suite *s21_atoi_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_atoi");

  /* Core test case */
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_atoi_1);
  tcase_add_test(tc_core, test_s21_atoi_2);
  tcase_add_test(tc_core, test_s21_atoi_3);
  tcase_add_test(tc_core, test_s21_atoi_4);
  tcase_add_test(tc_core, test_s21_atoi_5);
  tcase_add_test(tc_core, test_s21_atoi_6);
  tcase_add_test(tc_core, test_s21_atoi_7);
  tcase_add_test(tc_core, test_s21_atoi_8);
  tcase_add_test(tc_core, test_s21_atoi_9);
  tcase_add_test(tc_core, test_s21_atoi_10);
  tcase_add_test(tc_core, test_s21_atoi_11);
  tcase_add_test(tc_core, test_s21_atoi_12);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_reverse_str_1) {
  char s[] = "123";
  s21_reverse_str(s);
  char result_etalon[] = "321";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_str_2) {
  char s[] = "abc";
  s21_reverse_str(s);
  char result_etalon[] = "cba";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_str_3) {
  char s[] = "";
  s21_reverse_str(s);
  char result_etalon[] = "";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_str_4) {
  char s[] = "xxx";
  s21_reverse_str(s);
  char result_etalon[] = "xxx";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_str_5) {
  char s[] = "y\nx";
  s21_reverse_str(s);
  char result_etalon[] = "x\ny";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_str_6) {
  char s[] = "12\0";
  s21_reverse_str(s);
  char result_etalon[] = "21\0";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

Suite *s21_reverse_str_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_reverse_str");

  /* Core test case */
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_reverse_str_1);
  tcase_add_test(tc_core, test_s21_reverse_str_2);
  tcase_add_test(tc_core, test_s21_reverse_str_3);
  tcase_add_test(tc_core, test_s21_reverse_str_4);
  tcase_add_test(tc_core, test_s21_reverse_str_5);
  tcase_add_test(tc_core, test_s21_reverse_str_6);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_is_numeric_1) {
  for (int i = 0; i < 10; i++) ck_assert_int_eq(s21_is_numeric(0), 1);
}
END_TEST

START_TEST(test_s21_is_numeric_2) {
  ck_assert_int_eq(s21_is_numeric(10), 0);
  ck_assert_int_eq(s21_is_numeric(11), 0);
  ck_assert_int_eq(s21_is_numeric(-1), 0);
}
END_TEST

Suite *s21_is_muneric_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_is_muneric");

  /* Core test case */
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_is_numeric_1);
  tcase_add_test(tc_core, test_s21_is_numeric_2);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_reverse_plus_one_base_1) {
  char s[] = "111";

  s21_reverse_plus_one_base(s, 10);
  char result_etalon[] = "211";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_base_2) {
  char s[] = "99200";

  s21_reverse_plus_one_base(s, 10);
  char result_etalon[] = "00300";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_base_3) {
  char s[] = "111";

  s21_reverse_plus_one_base(s, 8);
  char result_etalon[] = "211";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_base_4) {
  char s[] = "77200";

  s21_reverse_plus_one_base(s, 8);
  char result_etalon[] = "00300";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_base_5) {
  char s[] = "111";

  s21_reverse_plus_one_base(s, 16);
  char result_etalon[] = "211";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_base_6) {
  char s[] = "BBB";

  s21_reverse_plus_one_base(s, 16);
  char result_etalon[] = "CBB";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_base_7) {
  char s[] = "FF200";

  s21_reverse_plus_one_base(s, 16);
  char result_etalon[] = "00300";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_base_8) {
  char s[] = "001";

  s21_reverse_plus_one_base(s, 2);
  char result_etalon[] = "101";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_base_9) {
  char s[] = "111";

  s21_reverse_plus_one_base(s, 2);
  char result_etalon[] = "0001";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_1) {
  char s[] = "111";

  s21_reverse_plus_one(s);
  char result_etalon[] = "211";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_2) {
  char s[] = "900";

  s21_reverse_plus_one(s);
  char result_etalon[] = "010";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_3) {
  char s[] = "99000";

  s21_reverse_plus_one(s);
  char result_etalon[] = "00100";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_4) {
  char s[] = "22\033";

  s21_reverse_plus_one(s);
  char result_etalon[] = "32\033";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_reverse_plus_one_5) {
  char s[] = "99";

  s21_reverse_plus_one(s);
  char result_etalon[] = "001";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_1) {
  char s[] = "";
  int n = 123;

  s21_itoab(n, s, 10);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_2) {
  char s[] = "";
  int n = 0123;

  s21_itoab(n, s, 8);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_3) {
  char s[] = "";
  int n = 0x123;

  s21_itoab(n, s, 16);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_4) {
  char result[100];
  char result_etalon[100];
  long long n = LLONG_MIN;

  s21_itoab(n, result, 10);
  sprintf(result_etalon, "%lld", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_5) {
  char result[100];
  char result_etalon[100];
  long long n = LLONG_MAX;

  s21_itoab(n, result, 8);
  sprintf(result_etalon, "%llo", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_6) {
  char result[100];
  char result_etalon[100];
  int n = INT_MAX;

  s21_itoab(n, result, 16);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_7) {
  char result[100];
  char result_etalon[100];
  int n = 10;

  s21_itoab(n, result, 8);
  sprintf(result_etalon, "%o", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_8) {
  char result[100];
  char result_etalon[100];
  int n = 10;

  s21_itoab(n, result, 16);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_9) {
  char result[100];
  char result_etalon[100];
  int n = 17;

  s21_itoab(n, result, 8);
  sprintf(result_etalon, "%o", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoab_10) {
  char result[100];
  char result_etalon[100];
  int n = 17;

  s21_itoab(n, result, 16);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_1) {
  char s[] = "";
  int n = 123;

  s21_uitoab(n, s, 10);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_2) {
  char s[] = "";
  int n = 0123;

  s21_uitoab(n, s, 8);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_3) {
  char s[] = "";
  int n = 0x123;

  s21_uitoab(n, s, 16);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_4) {
  char result[100];
  char result_etalon[100];
  unsigned long long n = 0LL;

  s21_uitoab(n, result, 10);
  sprintf(result_etalon, "%llu", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_5) {
  char result[100];
  char result_etalon[100];
  unsigned long long n = ULLONG_MAX;

  s21_uitoab(n, result, 8);
  sprintf(result_etalon, "%llo", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_6) {
  char result[100];
  char result_etalon[100];
  int n = INT_MAX;

  s21_uitoab(n, result, 16);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_7) {
  char result[100];
  char result_etalon[100];
  int n = 10;

  s21_uitoab(n, result, 8);
  sprintf(result_etalon, "%o", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_8) {
  char result[100];
  char result_etalon[100];
  int n = 10;

  s21_uitoab(n, result, 16);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_9) {
  char result[100];
  char result_etalon[100];
  int n = 17;

  s21_uitoab(n, result, 8);
  sprintf(result_etalon, "%o", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoab_10) {
  char result[100];
  char result_etalon[100];
  int n = 17;

  s21_uitoab(n, result, 16);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa_1) {
  char s[] = "";
  int n = 123;

  s21_itoa(n, s);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa_2) {
  char s[] = "";
  int n = -123;

  s21_itoa(n, s);
  char result_etalon[] = "-123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa_3) {
  char s[] = "";
  int n = +123;

  s21_itoa(n, s);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa_4) {
  char result[100];
  char result_etalon[100];
  int n = INT_MAX;

  s21_itoa(n, result);
  sprintf(result_etalon, "%d", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa_5) {
  char result[100];
  char result_etalon[100];
  long long n = -LLONG_MAX;

  s21_itoa(n, result);
  sprintf(result_etalon, "%lld", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa_6) {
  char result[100];
  char result_etalon[100];
  long long n = LLONG_MIN;

  s21_itoa(n, result);
  sprintf(result_etalon, "%lld", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa_7) {
  char result[100];
  char result_etalon[100];
  long long n = -LLONG_MIN;

  s21_itoa(n, result);
  sprintf(result_etalon, "%lld", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoa_1) {
  char s[] = "";
  int n = 123;

  s21_uitoa(n, s);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoa_3) {
  char s[] = "";
  int n = +123;

  s21_uitoa(n, s);
  char result_etalon[] = "123";
  ck_assert_str_eq(s, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoa_4) {
  char result[100];
  char result_etalon[100];
  int n = INT_MAX;

  s21_uitoa(n, result);
  sprintf(result_etalon, "%u", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_uitoa_7) {
  char result[100];
  char result_etalon[100];
  long long n = -LLONG_MIN;

  s21_uitoa(n, result);
  sprintf(result_etalon, "%llu", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa8_1) {
  char result[100];
  char result_etalon[100];
  int n = 077;

  s21_itoa8(n, result);
  sprintf(result_etalon, "%o", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa8_2) {
  char result[100];
  char result_etalon[100];
  int n = 5;

  s21_itoa8(n, result);
  sprintf(result_etalon, "%o", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa8_3) {
  char result[100];
  char result_etalon[100];
  int n = INT_MAX;

  s21_itoa8(n, result);
  sprintf(result_etalon, "%o", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa16_1) {
  char result[100];
  char result_etalon[100];
  int n = 0x5;

  s21_itoa16(n, result);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa16_2) {
  char result[100];
  char result_etalon[100];
  int n = 0xF;

  s21_itoa16(n, result);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa16_3) {
  char result[100];
  char result_etalon[100];
  int n = 0xF2C;

  s21_itoa16(n, result);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

START_TEST(test_s21_itoa16_4) {
  char result[100];
  char result_etalon[100];
  int n = INT_MAX;

  s21_itoa16(n, result);
  sprintf(result_etalon, "%X", n);
  ck_assert_str_eq(result, result_etalon);
}
END_TEST

Suite *s21_itoa_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_itoa");

  /* Core test case */
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_1);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_2);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_3);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_4);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_5);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_6);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_7);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_8);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_base_9);

  tcase_add_test(tc_core, test_s21_reverse_plus_one_1);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_2);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_3);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_4);
  tcase_add_test(tc_core, test_s21_reverse_plus_one_5);

  tcase_add_test(tc_core, test_s21_itoab_1);
  tcase_add_test(tc_core, test_s21_itoab_2);
  tcase_add_test(tc_core, test_s21_itoab_3);
  tcase_add_test(tc_core, test_s21_itoab_4);
  tcase_add_test(tc_core, test_s21_itoab_5);
  tcase_add_test(tc_core, test_s21_itoab_6);
  tcase_add_test(tc_core, test_s21_itoab_7);
  tcase_add_test(tc_core, test_s21_itoab_8);
  tcase_add_test(tc_core, test_s21_itoab_9);
  tcase_add_test(tc_core, test_s21_itoab_10);

  tcase_add_test(tc_core, test_s21_uitoab_1);
  tcase_add_test(tc_core, test_s21_uitoab_2);
  tcase_add_test(tc_core, test_s21_uitoab_3);
  tcase_add_test(tc_core, test_s21_uitoab_4);
  tcase_add_test(tc_core, test_s21_uitoab_5);
  tcase_add_test(tc_core, test_s21_uitoab_6);
  tcase_add_test(tc_core, test_s21_uitoab_7);
  tcase_add_test(tc_core, test_s21_uitoab_8);
  tcase_add_test(tc_core, test_s21_uitoab_9);
  tcase_add_test(tc_core, test_s21_uitoab_10);

  tcase_add_test(tc_core, test_s21_itoa_1);
  tcase_add_test(tc_core, test_s21_itoa_2);
  tcase_add_test(tc_core, test_s21_itoa_3);
  tcase_add_test(tc_core, test_s21_itoa_4);
  tcase_add_test(tc_core, test_s21_itoa_5);
  tcase_add_test(tc_core, test_s21_itoa_6);
  tcase_add_test(tc_core, test_s21_itoa_7);

  tcase_add_test(tc_core, test_s21_uitoa_1);
  tcase_add_test(tc_core, test_s21_uitoa_3);
  tcase_add_test(tc_core, test_s21_uitoa_4);
  tcase_add_test(tc_core, test_s21_uitoa_7);

  tcase_add_test(tc_core, test_s21_itoa8_1);
  tcase_add_test(tc_core, test_s21_itoa8_2);
  tcase_add_test(tc_core, test_s21_itoa8_3);

  tcase_add_test(tc_core, test_s21_itoa16_1);
  tcase_add_test(tc_core, test_s21_itoa16_2);
  tcase_add_test(tc_core, test_s21_itoa16_3);
  tcase_add_test(tc_core, test_s21_itoa16_4);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_atoi_suit();
  sr = srunner_create(s);

  srunner_add_suite(sr, s21_reverse_str_suit());
  srunner_add_suite(sr, s21_is_muneric_suit());
  srunner_add_suite(sr, s21_itoa_suit());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}