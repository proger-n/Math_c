#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <stdio.h>

#define S21_PI 3.14159265358979323846
#define S21_E 2.71828182845904523536028747
#define S21_PI_2 1.570796326794896619231321691639751442
#define S21_PI_4 0.785398163397448309615660845819875721
#define S21_LN2 0.693147180559945309417232
#define S21_INF __builtin_inf()
#define S21_NAN __builtin_nan("")

int s21_abs(int x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_ceil(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_floor(double x);
long double s21_sqrt(double x);
long double s21_log(double x);
long double s21_tan(double x);
long double s21_pow(double base, double exp);
long double s21_fuctorial(long long int x);
long double s21_pow_integer(double base, long long int exp);
int s21_number_of_digits(long double x);
long double s21_exceptions_for_pow(double base, double exp);

#endif  // S21_MATH_H_