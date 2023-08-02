#include "s21_math.h"

long double s21_sqrt(double x) {
  long double eps = 0.000001;
  long double n = 1.0;
  long double err;
  do {
    double xtmp = (n + x / n) / 2;
    err = s21_fabs(n - xtmp);
    n = xtmp;
  } while (err > eps);
  if (x == +S21_INF || x == 0) n = (long double)x;
  if (x != x || x == -S21_INF || x < 0) n = S21_NAN;
  return n;
}