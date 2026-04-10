#include <check.h>
#include <stdarg.h>

#include "../../s21_sprintf.h"

START_TEST(s21_add_arg_c_test_1) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  char ch = 'a';
  // int width = 10;
  char *format1 = "'%10c fd#$gh '%-10c' | '%+10c'";
  int len1 = s21_sprintf(buffer1, format1, ch, ch, ch);
  int len2 = sprintf(buffer2, format1, ch, ch, ch);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_c_test_2) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  char ch = 'd';
  // int width = 10;
  char *format1 = "' erwtgw %03c fd#$gh %-04c qerqt'";
  int len1 = s21_sprintf(buffer1, format1, ch, ch);
  int len2 = sprintf(buffer2, format1, ch, ch);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_c_test_3) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  char ch = 'e';
  int width = 10;
  char *format1 = "' erwtgw %*c'";
  int len1 = s21_sprintf(buffer1, format1, width, ch);
  int len2 = sprintf(buffer2, format1, width, ch);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_c_test_4) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  char ch = 'e';
  int width = 10;
  char *format1 = "' erwtgw %*c rwtgw %-*c'";
  int len1 = s21_sprintf(buffer1, format1, width, ch, width, ch);
  int len2 = sprintf(buffer2, format1, width, ch, width, ch);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_c_test_5) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  char ch = 'e';
  int width = 10;
  char *format1 = "' erwtgw %0*c rwtgw %-0*c'";
  int len1 = s21_sprintf(buffer1, format1, width, ch, width, ch);
  int len2 = sprintf(buffer2, format1, width, ch, width, ch);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

Suite *s21_add_arg_c_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_add_argument_c");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_add_arg_c_test_1);
  tcase_add_test(tc_core, s21_add_arg_c_test_2);
  tcase_add_test(tc_core, s21_add_arg_c_test_3);
  tcase_add_test(tc_core, s21_add_arg_c_test_4);
  tcase_add_test(tc_core, s21_add_arg_c_test_5);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(s21_add_fchar_test_1)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 'c';
  atr.fl_minus = 1;
  atr.width = 1;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;
  char symb = 'A';

  s21_add_fchar(&buffer, atr, &str_len, symb);
  sprintf(buffer_etallon, "%-1c", symb); 

  ck_assert_str_eq(&buffer[-1], buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fchar_test_2)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 'c';
  atr.fl_minus = 0;
  atr.width = 1;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;
  char symb = 'b';

  s21_add_fchar(&buffer, atr, &str_len, symb);
  sprintf(buffer_etallon, "%c", symb); 
  
  ck_assert_str_eq(buffer - 1, buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fchar_test_3)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 'c';
  atr.fl_minus = 1;
  atr.width = 10;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;
  char symb = 'b';

  s21_add_fchar(&buffer, atr, &str_len, symb);
  sprintf(buffer_etallon, "%-10c", symb); 
  
  ck_assert_str_eq(buffer - atr.width, buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fchar_test_4)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 'c';
  atr.fl_minus = 0;
  atr.width = 10;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;
  char symb = 'b';

  s21_add_fchar(&buffer, atr, &str_len, symb);
  sprintf(buffer_etallon, "%10c", symb); 
  
  ck_assert_str_eq(buffer - atr.width, buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fchar_test_5)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = '%';

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fchar(&buffer, atr, &str_len, '%');
  sprintf(buffer_etallon, "%%"); 
  
  ck_assert_str_eq(buffer - 1, buffer_etallon);
  ck_assert_int_eq(str_len, 1);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fchar_test_6)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = '%';
  atr.width = 10;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fchar(&buffer, atr, &str_len, '%');
  sprintf(buffer_etallon, "%10%"); 
  
  ck_assert_str_eq(buffer - atr.width, buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fchar_test_7)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = '%';
  atr.fl_zero = 1;
  atr.width = 10;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fchar(&buffer, atr, &str_len, '%');
  sprintf(buffer_etallon, "%010%"); 
  
  ck_assert_str_eq(buffer - atr.width, buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fchar_test_8)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = '%';
  atr.fl_zero = 1;
  atr.width = 3;
  atr.precision = 5;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fchar(&buffer, atr, &str_len, '%');
  sprintf(buffer_etallon, "%03.5%"); 
  
  ck_assert_str_eq(buffer - atr.width, buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fchar_test_9)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = '%';
  atr.fl_zero = 1;
  atr.width = 5;
  atr.precision = 3;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fchar(&buffer, atr, &str_len, '%');
  sprintf(buffer_etallon, "%05.3%"); 
  
  ck_assert_str_eq(buffer - atr.width, buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

Suite *s21_add_fchar_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_add_fchar");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_add_fchar_test_1);
  tcase_add_test(tc_core, s21_add_fchar_test_2);
  tcase_add_test(tc_core, s21_add_fchar_test_3);
  tcase_add_test(tc_core, s21_add_fchar_test_4);
  tcase_add_test(tc_core, s21_add_fchar_test_5);
  tcase_add_test(tc_core, s21_add_fchar_test_6);
  tcase_add_test(tc_core, s21_add_fchar_test_7);
  tcase_add_test(tc_core, s21_add_fchar_test_8);
  tcase_add_test(tc_core, s21_add_fchar_test_9);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(s21_add_fstr_test_1)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 'd';
  atr.fl_zero = 0;
  atr.width = 5;
  atr.precision = -1;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "123");
  sprintf(buffer_etallon, "%5d", 123); 
  
  ck_assert_str_eq(buffer - atr.width, buffer_etallon);
  ck_assert_int_eq(str_len, atr.width);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fstr_test_2)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 's';
  atr.fl_zero = 0;
  atr.width = -1;
  atr.precision = -1;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "12345678");
  sprintf(buffer_etallon, "%s", "12345678"); 
  
  ck_assert_str_eq(buffer - 8, buffer_etallon);
  ck_assert_int_eq(str_len, 8);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fstr_test_3)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 's';
  atr.fl_zero = 0;
  atr.width = 5;
  atr.precision = -1;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "12345678");
  sprintf(buffer_etallon, "%5s", "12345678"); 
  
  ck_assert_str_eq(buffer - 8, buffer_etallon);
  ck_assert_int_eq(str_len, 8);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fstr_test_4)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 's';
  atr.fl_zero = 0;
  atr.width = -1;
  atr.precision = 5;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "12345678");
  sprintf(buffer_etallon, "%.5s", "12345678"); 
  
  ck_assert_str_eq(buffer - atr.precision, buffer_etallon);
  ck_assert_int_eq(str_len, 5);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fstr_test_5)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 's';
  atr.fl_minus = 1;
  atr.width = 5;
  atr.precision = -1;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "12345678");
  sprintf(buffer_etallon, "%-5s", "12345678"); 
  
  ck_assert_str_eq(buffer - 8, buffer_etallon);
  ck_assert_int_eq(str_len, 8);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fstr_test_6)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 's';
  atr.fl_zero = 0;
  atr.width = 0;
  atr.precision = 15;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "12345678");
  sprintf(buffer_etallon, "%.10s", "12345678"); 
  
  ck_assert_str_eq(buffer - 8, buffer_etallon);
  ck_assert_int_eq(str_len, 8);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fstr_test_7)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 's';
  atr.fl_minus = 1;
  atr.width = 10;
  atr.precision = -1;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "12345678");
  sprintf(buffer_etallon, "%-10s", "12345678"); 
  
  ck_assert_str_eq(buffer - atr.width, buffer_etallon);
  ck_assert_int_eq(str_len, 10);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fstr_test_8)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 's';
  atr.fl_zero = 0;
  atr.width = 10;
  atr.precision = 5;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "12345678");
  sprintf(buffer_etallon, "%10.5s", "12345678"); 
  
  ck_assert_str_eq(buffer - 10, buffer_etallon);
  ck_assert_int_eq(str_len, 10);
  // free(buffer);
}
END_TEST

START_TEST(s21_add_fstr_test_9)
{
  s21_atributes atr;
  s21_init_atributes(&atr);
  atr.specifier = 's';
  atr.fl_minus = 1;
  atr.width = 10;
  atr.precision = 5;

  char *buffer = malloc(100);
  char buffer_etallon[100];
  int str_len = 0;

  s21_add_fstr(&buffer, atr, &str_len, "12345678");
  sprintf(buffer_etallon, "%-10.5s", "12345678"); 
  
  ck_assert_str_eq(buffer- 10, buffer_etallon);
  ck_assert_int_eq(str_len, 10);
  // free(buffer);
}
END_TEST

Suite *s21_add_fstr_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_add_fstr");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_add_fstr_test_1);
  tcase_add_test(tc_core, s21_add_fstr_test_2);
  tcase_add_test(tc_core, s21_add_fstr_test_3);
  tcase_add_test(tc_core, s21_add_fstr_test_4);
  tcase_add_test(tc_core, s21_add_fstr_test_5);
  tcase_add_test(tc_core, s21_add_fstr_test_6);
  tcase_add_test(tc_core, s21_add_fstr_test_7);
  tcase_add_test(tc_core, s21_add_fstr_test_8);
  tcase_add_test(tc_core, s21_add_fstr_test_9);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(s21_add_arg_s_test_1) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%10s fd#$gh %-10s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_2) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%20.5s fd#$gh %-20.5s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_3) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%20.20s fd#$gh %-20.15s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_4) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%3.3s fd#$gh %-3.3s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_5) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%0.10s fd#$gh %-0.20s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_6) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%00.10s fd#$gh %-00.20s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_7) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%10.0s fd#$gh %-20.0s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_8) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%10.00s fd#$gh %-20.00s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}

END_TEST
START_TEST(s21_add_arg_s_test_9) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%017.10s fd#$gh %-03.07s'";
  int len1 = s21_sprintf(buffer1, format1, str, str);
  int len2 = sprintf(buffer2, format1, str, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_10) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  int width = 10;
  int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%*.*s fd#$gh %-*.*s'";
  int len1 = s21_sprintf(buffer1, format1, width, precision, str, width,
                         precision, str);
  int len2 =
      sprintf(buffer2, format1, width, precision, str, width, precision, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_11) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  int width = 10;
  int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%0*.*s fd#$gh %-*.*s'";
  int len1 = s21_sprintf(buffer1, format1, width, precision, str, width,
                         precision, str);
  int len2 =
      sprintf(buffer2, format1, width, precision, str, width, precision, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_12) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  int width = 10;
  int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%20.*s fd#$gh %*s aqergaqh'";
  int len1 = s21_sprintf(buffer1, format1, precision, str, width, str);
  int len2 = sprintf(buffer2, format1, precision, str, width, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_s_test_13) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  int width = 10;
  int precision = 4;
  char *str = "Hello WORLD!";
  char *format1 = "'%7.25s fd#$gh f EGT %*.*s'";
  int len1 = s21_sprintf(buffer1, format1, str, width, precision, str);
  int len2 = sprintf(buffer2, format1, str, width, precision, str);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

Suite *s21_add_arg_s_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_add_arg_s");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_add_arg_s_test_1);
  tcase_add_test(tc_core, s21_add_arg_s_test_2);
  tcase_add_test(tc_core, s21_add_arg_s_test_3);
  tcase_add_test(tc_core, s21_add_arg_s_test_4);
  tcase_add_test(tc_core, s21_add_arg_s_test_5);
  tcase_add_test(tc_core, s21_add_arg_s_test_6);
  tcase_add_test(tc_core, s21_add_arg_s_test_7);
  tcase_add_test(tc_core, s21_add_arg_s_test_8);
  tcase_add_test(tc_core, s21_add_arg_s_test_9);
  tcase_add_test(tc_core, s21_add_arg_s_test_10);
  tcase_add_test(tc_core, s21_add_arg_s_test_11);
  tcase_add_test(tc_core, s21_add_arg_s_test_12);
  tcase_add_test(tc_core, s21_add_arg_s_test_13);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(s21_add_arg_d_test_1) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  int num = 34;
  char *format = "'%10d TEXT  text 1234567890 !@#$^&*()_+ %-10d'";
  int len1 = s21_sprintf(buffer1, format, num, num);
  int len2 = sprintf(buffer2, format, num, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_d_test_2) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  int num = 34;
  char *format = "'%+5d' |'%+ 4d' | '% +7d' | '%++7d' | '% + 7d'";
  int len1 = s21_sprintf(buffer1, format, num, num, num, num, num);
  int len2 = sprintf(buffer2, format, num, num, num, num, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_d_test_3) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  int num = 34;
  char *format = "''%-5d' |'%- 5d' | '% -5d' | '% - 5d' | '%---.5d''";
  int len1 = s21_sprintf(buffer1, format, num, num, num, num, num);
  int len2 = sprintf(buffer2, format, num, num, num, num, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_d_test_4) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  int num = 34;
  char *format = "'% 10d' |'%  10d' | '%+ -d' | '% - 7d' | '% -+d'";
  int len1 = s21_sprintf(buffer1, format, num, num, num, num, num);
  int len2 = sprintf(buffer2, format, num, num, num, num, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST
START_TEST(s21_add_arg_d_test_5) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  int num = 347;
  char *format = "'%010d' |'%-010d' | '% +-10d' | '% - 07d' | '% -+0d'";
  int len1 = s21_sprintf(buffer1, format, num, num, num, num, num);
  int len2 = sprintf(buffer2, format, num, num, num, num, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_d_test_6) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  // int precision = 4;
  int num = 347;
  char *format = "'%.4d' |'%-7.5d' | '%+10.4d' | '% -+10.5d' | '% -+05.10d'";
  int len1 = s21_sprintf(buffer1, format, num, num, num, num, num);
  int len2 = sprintf(buffer2, format, num, num, num, num, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_d_test_7) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  int width = 10;
  // int precision = 4;
  int num = 347;
  char *format = "'%*d' |'%-*d' | '%+*d' | '% -+10.5d' | '% -+*d'";
  int len1 = s21_sprintf(buffer1, format, width, num, width, num, width, num,
                         num, width, num);
  int len2 = sprintf(buffer2, format, width, num, width, num, width, num, num,
                     width, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_d_test_8) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  // int width = 10;
  int precision = 4;
  int num = 347;
  char *format = "'%.*d' |'%-5.*d' | '%+0.*d' | '% -+10.5d' | '% -+05.*d'";
  int len1 = s21_sprintf(buffer1, format, precision, num, precision, num,
                         precision, num, num, precision, num);
  int len2 = sprintf(buffer2, format, precision, num, precision, num, precision,
                     num, num, precision, num);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_d_test_9) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  int width = 10;
  int precision = 4;
  int num = 347;
  char *format = "'%*.*d' |'%-5.*d' | '%+*.0d' | '% -+10.5d' | '% -+05.*d'";
  int len1 = s21_sprintf(buffer1, format, width, precision, num, precision, num,
                         width, num, num, precision, num);
  int len2 = sprintf(buffer2, format, width, precision, num, precision, num,
                     width, num, num, precision, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

START_TEST(s21_add_arg_d_test_10) {
  char *buffer1 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));
  char *buffer2 = (char *)malloc(s21_BUFSIZ * sizeof(char) + sizeof('\0'));

  int width = 10;
  int precision = 4;
  int num = 347;
  char *format = "'%*.*d TeXT_t3yqhafgbe556357476!@#$^() %-*.*d'";
  int len1 = s21_sprintf(buffer1, format, width, precision, num, width,
                         precision, num);
  int len2 =
      sprintf(buffer2, format, width, precision, num, width, precision, num);

  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(len1, len2);

  free(buffer1);
  free(buffer2);
}
END_TEST

Suite *s21_add_arg_d_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_add_fstr");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_add_arg_d_test_1);
  tcase_add_test(tc_core, s21_add_arg_d_test_2);
  tcase_add_test(tc_core, s21_add_arg_d_test_3);
  tcase_add_test(tc_core, s21_add_arg_d_test_4);
  tcase_add_test(tc_core, s21_add_arg_d_test_5);
  tcase_add_test(tc_core, s21_add_arg_d_test_6);
  tcase_add_test(tc_core, s21_add_arg_d_test_7);
  tcase_add_test(tc_core, s21_add_arg_d_test_8);
  tcase_add_test(tc_core, s21_add_arg_d_test_9);
  tcase_add_test(tc_core, s21_add_arg_d_test_10);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_add_arg_c_suit();
  sr = srunner_create(s);

  srunner_add_suite(sr, s21_add_fchar_suit());
  srunner_add_suite(sr, s21_add_fstr_suit());
  srunner_add_suite(sr, s21_add_arg_s_suit());
  srunner_add_suite(sr, s21_add_arg_d_suit());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
