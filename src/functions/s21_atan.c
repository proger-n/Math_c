#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0.0;
  if (x == 0.0) {
    result = 0.0;
  } else if (x == 1.0) {
    result = S21_PI_4;
  } else if (x == -1.0) {
    result = -S21_PI_4;
  } else if (x == S21_INF || x == -S21_INF) {
    result = x < 0.0 ? -S21_PI_2 : S21_PI_2;
  } else if (x > -1.0 && x < 1.0) {
    for (int i = 0; i < 50; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else if (x == S21_NAN) {
    result = S21_NAN;
  } else {
    for (int i = 0; i < 50; i++) {
      result += s21_pow(-1, i) * s21_pow(x, -(1 + (2 * i))) / (1 + (2 * i));
    }
    result = S21_PI * s21_sqrt(x * x) / (2 * x) - result;
  }
  return result;
}