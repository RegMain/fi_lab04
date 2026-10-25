#include "functions.h"
#include <math.h>

double F23(double x) {
  return 3 * x - 4 * log(x) - 5;
}

double Fx23(double x) {
  return (4 * log(x) + 5) / 3;
}

double f23(double x) {
  return 3 - 4 / x;
}

double F24(double x) {
  return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}

double Fx24(double x) {
  return 1 / (2 * sin(1 / x) - cos(2 / x));
}

double f24(double x) {
  return (1 / (x * x)) * (2 * sin(2 / x) + cos(1 / x) - 1);
}

double F25(double x) {
  return sqrt(1 - 0.4 * x * x) - asin(x);
}

double Fx25(double x) {
  return sqrt(1 - 0.4 * x * x) - asin(x) + x;
}

double f25(double x) {
  return (-0.8 * x) / (2 * sqrt(1 - 0.4 * x * x)) - 1 / sqrt(1 - x * x);
}
