#include "s21_math.h"

int s21_number_of_digits(long double x) {
  int count = 1;
  while (x > 1) {
    x /= 10;
    count++;
  }
  return count;
}
long double s21_log(double x) {
  long double result = 0;
  if (x < 0) {
    result = S21_NAN;
  } else if (x == 0) {
    result = -S21_INF;
  } else if (x == 1) {
    result = 0;
  } else {
    long double firstValue = s21_number_of_digits(x) + 2.3;
    long double prevValue = 0.0;
    long double epsilon = 0.000001;
    while (s21_fabs((double)(firstValue - prevValue)) > epsilon) {
      prevValue = firstValue;
      firstValue -= (s21_exp(firstValue) - x) / s21_exp(firstValue);
    }
    result = firstValue;
  }
  return result;
}
