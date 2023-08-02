#include "s21_math.h"

long double s21_exceptions_for_pow(double base, double exp) {
  long double result = 0;
  if (base == 0) {
    if (exp > 0) {
      result = 0;
    } else if (exp < 0) {
      result = +S21_INF;
    } else {
      result = 1.0;
    }
  } else if ((base == -1 && exp == +S21_INF) || base == 1) {
    result = 1.0;
  } else if (exp == 0) {
    result = 1;
  } else if (base < 0 && (long)exp != exp && base != -S21_INF &&
             exp != -S21_INF) {
    result = S21_NAN;
  } else if (exp == -S21_INF) {
    if (s21_fabs(base) < 1) {
      result = +S21_INF;
    } else {
      result = 0;
    }
  } else if (exp == +S21_INF) {
    if (s21_fabs(base) < 1) {
      result = 0;
    } else {
      result = +S21_INF;
    }
  } else if (base == +S21_INF) {
    if (exp < 0) {
      result = 0;
    }
    if (exp > 0) {
      if ((long)exp == exp && (long)exp % 2 == 1) {
        result = -S21_INF;
      } else {
        result = +S21_INF;
      }
    }
  } else if (base == +S21_INF) {
    if (exp > 0) {
      result = +S21_INF;
    }
    if (exp < 0) {
      result = 0;
    }
  } else {
    result = -1;
  }
  return result;
}
long double s21_pow(double base, double exp) {
  long double result = 1;
  int sign = 0;
  if (exp < 0) sign = 1;
  if (s21_exceptions_for_pow(base, exp) != -1) {
    result = s21_exceptions_for_pow(base, exp);
  } else if (exp == (long)exp) {
    exp = s21_fabs(exp);
    for (int i = 1; i <= exp; i++) {
      result *= base;
    }
    if (sign) result = 1 / result;
  } else {
    exp = s21_fabs(exp);
    result = (long double)s21_exp(exp * s21_log(base));
    if (sign) result = 1 / result;
  }
  return result;
}