#include "functions.h"
#include <math.h>

double F23(double x) {
  return 3.0 * x - 4.0 * log(x) - 5.0;
}

double Fx23(double x) {
  return (4.0 * log(x) + 5.0) / 3.0;
}

double F24(double x) {
  return cos(2.0 / x) - 2.0 * sin(1.0 / x) + 1.0 / x;
}

double Fx24(double x) {
  return x - (cos(2.0 / x) - 2.0 * sin(1.0 / x) + 1.0 / x);
}

double F25(double x) {
  return sqrt(1.0 - 0.4 * x * x) - asin(x);
}

double Fx25(double x) {
  return sqrt(1.0 - 0.4 * x * x) - asin(x) + x;
}
