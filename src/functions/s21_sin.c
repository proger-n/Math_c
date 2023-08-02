#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  x = s21_fmod(x, 2 * S21_PI);
  for (int i = 0; i < 16; i++) {
    long double step = s21_pow_integer(-1, i) * s21_pow_integer(x, 2 * i + 1) /
                       s21_fuctorial(2 * i + 1);
    result += step;
  }
  return result;
}