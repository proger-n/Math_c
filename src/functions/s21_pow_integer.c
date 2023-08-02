#include "s21_math.h"

long double s21_pow_integer(double base, long long int x) {
  long double result = 1.0;
  for (int i = 0; i < x; i++) {
    result *= base;
  }
  return result;
}