#include "s21_math.h"

long double s21_tan(double x) {
  x = s21_fmod(x, S21_PI);
  long double res_of_cos = s21_cos(x);
  return !res_of_cos ? 0.0 / 0.0 : s21_sin(x) / res_of_cos;
}