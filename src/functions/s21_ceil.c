#include "s21_math.h"

long double s21_ceil(double x) {
  long double result =
      (x != x || s21_fabs(x) == S21_INF)
          ? x
          : (x - (long int)x > 0 ? (long int)++x : (long int)x);
  return result;
}