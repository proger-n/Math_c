#include "s21_math.h"

long double s21_fmod(double x, double y) {
  int flag = 0;
  if (x < 0) flag = 1;
  if (y == 0)
    x = S21_NAN;
  else if (x == +S21_INF || x == -S21_INF)
    x = S21_NAN;
  else if (x != x || y != y)
    x = S21_NAN;
  else {
    x = s21_fabs(x);
    y = s21_fabs(y);
    while (x >= y) {
      x -= y;
    }
  }
  if (flag == 1) x = -x;
  return x;
}