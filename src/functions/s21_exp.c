#include "s21_math.h"

long double s21_exp(double x) {
  long double rez = 1, y = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(rez) > 1e-9) {
    rez *= x / i;
    i++;
    y += rez;
    if (y > 1.7976931348623157e30) {
      y = +S21_INF;
      break;
    }
  }
  y = flag == 1 ? y > 1.7976931348623157e30 ? 0 : 1. / y : y;
  return y = y > 1.7976931348623157e30 ? +S21_INF : y;
}
