#include "s21_math.h"

long double s21_fuctorial(long long int x) {
  long double result = 1.0;
  for (int i = 2; i <= x; i++) {
    result *= i;
  }
  return result;
}