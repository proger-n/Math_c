#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 0.0 / 0.0;
  if (x != +1.0 / 0.0 || x != -1.0 / 0.0) result = s21_sin(S21_PI / 2 - x);
  return result;
}