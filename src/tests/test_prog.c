#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../functions/s21_math.h"

double test_nans[] = {NAN, -NAN};
double test_arc[] = {0, 1, -1, -0.5, 0.1357, -0.345};
int test_ints[] = {0, 13, -8, -19, (int)NAN, (int)-INFINITY};
double test_doubles[] = {0, -1.05, 1.02, 17.32, -14.56, 12.34};
double test_doubles_sqrt_fmod[] = {0.123, 1.321, 15.15, 11.11, 16.16, 2.2222};

Suite *math_tests();

int main() {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;
  s = math_tests();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  printf("========= FAILED: %d =========\n", number_failed);

  return 0;
}

START_TEST(test_abs) {
  ck_assert_int_eq(s21_abs(test_ints[_i]), abs(test_ints[_i]));
}
END_TEST

START_TEST(test_acos) {
  ck_assert_double_eq_tol(s21_acos(test_arc[_i]), acos(test_arc[_i]), 1e-7);
}
END_TEST

START_TEST(test_asin) {
  ck_assert_double_eq_tol(s21_asin(test_arc[_i]), asin(test_arc[_i]), 1e-7);
}
END_TEST

START_TEST(test_atan) {
  ck_assert_double_eq_tol(s21_atan(test_arc[_i]), atan(test_arc[_i]), 1e-7);
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_double_eq_tol(s21_ceil(test_doubles[_i]), ceil(test_doubles[_i]),
                          1e-7);
}
END_TEST

START_TEST(test_cos) {
  ck_assert_double_eq_tol(s21_cos(test_doubles[_i]), cos(test_doubles[_i]),
                          1e-7);
}
END_TEST

START_TEST(test_exp) {
  ck_assert_double_eq_tol(s21_exp(test_doubles[_i]), exp(test_doubles[_i]),
                          1e-7);
  ck_assert_float_eq(exp(-13.54), s21_exp(-13.54));
  ck_assert_float_eq(exp(13.54), s21_exp(13.54));
  ck_assert_float_eq(exp(-0.54), s21_exp(-0.54));
  ck_assert_float_eq(exp(1000), s21_exp(1000));
  ck_assert_float_eq(exp(1), s21_exp(1));
  ck_assert_float_eq(exp(2), s21_exp(2));
  ck_assert_float_eq(exp(-1), s21_exp(-1));
  ck_assert_float_eq(exp(0), s21_exp(0));
  ck_assert_int_eq(exp(S21_NAN), s21_exp(S21_NAN));
  ck_assert_float_eq(exp(710), s21_exp(710));
  ck_assert_float_eq(exp(1.2345), s21_exp(1.2345));
  ck_assert_float_eq(exp(1.23454656768), s21_exp(1.23454656768));
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_double_eq_tol(s21_fabs(test_doubles[_i]), fabs(test_doubles[_i]),
                          1e-7);
}
END_TEST

START_TEST(test_floor) {
  ck_assert_double_eq_tol(s21_floor(test_doubles[_i]), floor(test_doubles[_i]),
                          1e-7);
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_double_eq_tol(
      s21_fmod(test_doubles[_i], test_doubles_sqrt_fmod[_i]),
      fmod(test_doubles[_i], test_doubles_sqrt_fmod[_i]), 1e-7);
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 3));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, 3));
  ck_assert_ldouble_nan(s21_fmod(+S21_INF, 3));
  ck_assert_ldouble_nan(s21_fmod(3, 0));
  ck_assert_ldouble_eq_tol(s21_fmod(3, 3), fmod(3, 3), 1e-6);
}
END_TEST

START_TEST(test_log) {
  ck_assert_double_eq_tol(s21_log(test_doubles_sqrt_fmod[_i]),
                          log(test_doubles_sqrt_fmod[_i]), 1e-7);
}
END_TEST

START_TEST(test_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 5), pow(0, 5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(-1, +S21_INF), pow(-1, +S21_INF), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(1, +S21_INF), pow(1, +S21_INF), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(3, 0), pow(3, 0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(-7, -S21_INF), pow(-7, -S21_INF), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(74, -S21_INF), pow(74, -S21_INF), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(0.63, +S21_INF), pow(0.63, +S21_INF), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, -13), pow(-S21_INF, -13), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(+S21_INF, -11.33), pow(+S21_INF, -11.33),
                           1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(11, 0.5), pow(11, 0.5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(9, 0.66667), pow(9, 0.66667), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(100, 0.5), pow(100, 0.5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(1, 5), pow(1, 5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(3, 6), pow(3, 6), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(100, 3), pow(100, 3), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(2, 10), pow(2, 10), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(9, 0.5), pow(9, 0.5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(10000, 0.5), pow(10000, 0.5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(100000000, 1), pow(100000000, 1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(-5, 4), pow(-5, 4), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(0.4, 5), pow(0.4, 5), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(3.14, 9), pow(3.14, 9), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(6, -1), pow(6, -1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(5, -2), pow(5, -2), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(100, -2), pow(100, -2), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(-S21_PI, 2), pow(-S21_PI, 2), 1e-7);
  ck_assert_int_eq(s21_pow(-100, 0.5), pow(-100, 0.5));
  ck_assert_int_eq(s21_pow(-67, 0.6667), pow(-67, 0.6667));
  ck_assert_int_eq(s21_pow(-3, -3), pow(-3, -3));
  ck_assert_int_eq(s21_pow(-9, 3.14), pow(-9, 3.14));
  ck_assert_int_eq(s21_pow(0, -6), pow(0, -6));
}
END_TEST

START_TEST(test_sin) {
  ck_assert_double_eq_tol(s21_sin(test_doubles[_i]), sin(test_doubles[_i]),
                          1e-7);
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_double_eq_tol(s21_sqrt(test_doubles_sqrt_fmod[_i]),
                          sqrt(test_doubles_sqrt_fmod[_i]), 1e-7);
}
END_TEST

START_TEST(test_tan) {
  ck_assert_double_eq_tol(s21_tan(test_doubles[_i]), tan(test_doubles[_i]),
                          1e-7);
}
END_TEST

START_TEST(test_nan) {
  ck_assert_double_nan(s21_acos(test_nans[_i]));
  ck_assert_double_nan(acos(test_nans[_i]));
  ck_assert_double_nan(s21_asin(test_nans[_i]));
  ck_assert_double_nan(asin(test_nans[_i]));
  ck_assert_double_nan(s21_atan(test_nans[_i]));
  ck_assert_double_nan(atan(test_nans[_i]));
  ck_assert_double_nan(s21_ceil(test_nans[_i]));
  ck_assert_double_nan(ceil(test_nans[_i]));
  ck_assert_double_nan(s21_cos(test_nans[_i]));
  ck_assert_double_nan(cos(test_nans[_i]));
  ck_assert_double_nan(s21_exp(test_nans[_i]));
  ck_assert_double_nan(exp(test_nans[_i]));
  ck_assert_double_nan(s21_fabs(test_nans[_i]));
  ck_assert_double_nan(fabs(test_nans[_i]));
  ck_assert_double_nan(s21_floor(test_nans[_i]));
  ck_assert_double_nan(floor(test_nans[_i]));
  ck_assert_double_nan(s21_fmod(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(fmod(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(s21_log(test_nans[_i]));
  ck_assert_double_nan(log(test_nans[_i]));
  ck_assert_double_nan(s21_pow(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(pow(test_nans[_i], test_nans[_i]));
  ck_assert_double_nan(s21_sin(test_nans[_i]));
  ck_assert_double_nan(sin(test_nans[_i]));
  ck_assert_double_nan(s21_sqrt(test_nans[_i]));
  ck_assert_double_nan(sqrt(test_nans[_i]));
  ck_assert_double_nan(s21_tan(test_nans[_i]));
  ck_assert_double_nan(tan(test_nans[_i]));
}

Suite *math_tests() {
  int test_ints_size = sizeof(test_ints) / sizeof(int),
      test_doubles_size = sizeof(test_doubles) / sizeof(double),
      test_doubles_sqrt_fmod_size =
          sizeof(test_doubles_sqrt_fmod) / sizeof(double);
  // test_nans_size = sizeof(test_nans) / sizeof(double);

  Suite *s = suite_create("\033[44m-=S21_MATH=-\033[0m");
  TCase *tc_core = tcase_create("s21_math");
  tcase_add_loop_test(tc_core, test_abs, 0, test_ints_size);
  tcase_add_loop_test(tc_core, test_acos, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_asin, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_atan, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_ceil, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_cos, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_exp, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_fabs, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_floor, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_fmod, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_log, 0, test_doubles_sqrt_fmod_size);
  tcase_add_loop_test(tc_core, test_pow, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_sin, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_sqrt, 0, test_doubles_sqrt_fmod_size);
  tcase_add_loop_test(tc_core, test_tan, 0, test_doubles_size);
  tcase_add_loop_test(tc_core, test_nan, 0, 2);
  suite_add_tcase(s, tc_core);
  return s;
}
