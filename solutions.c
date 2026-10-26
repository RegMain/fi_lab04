#include "solutions.h"
#include <math.h>
#include <stdint.h>

const double EPS = 1e-10;
const int32_t MAX_ITERATIONS = 10000;

double df(double (*f)(double), double x) {
  return (f(x + EPS) - f(x - EPS)) / (2 * EPS);
}

double df2(double (*f)(double), double x) {
  return (df(f, x + EPS) - df(f, x - EPS)) / (2 * EPS);
}

double binary_search_method(double l, double r, double (*f)(double), uint32_t *cnt) {
  *cnt = 0;
  double m;
  while (fabs(r - l) > EPS) {
    (*cnt)++;
    m = (r + l) / 2;
    if (f(l)*f(m) > 0) {
      l = m;
    } else {
      r = m;
    }
  }
  if (fabs(f((l + r) / 2)) < EPS) {
    return (l + r) / 2;
  } else {
    return -INFINITY;
  }
}

double iteration_method(double l, double r, double (*f)(double), uint32_t *cnt) {
  *cnt = 0;
  double x = (l + r) / 2;
  double prev_x = 0;
  do {
    (*cnt)++;
    prev_x = x;
    x = f(x);
    if (fabs(df(f, x) - 1) < EPS || df(f, x) - 1 > EPS) {
      return -INFINITY;
    }
    if (*cnt > MAX_ITERATIONS) {
      return -INFINITY;
    }
  } while (fabs(x - prev_x) > EPS);

  if (fabs(x - f(x)) < EPS && ((x - l) > EPS || fabs(x - l) < EPS) && ((r - x) > EPS || fabs(x - r) < EPS)) {
    return x;
  } else {
    return -INFINITY;
  }
}

double newton_method(double l, double r, double (*f)(double), uint32_t *cnt) {
  *cnt = 0;
  double x = (l + r) / 2;
  double prev_x = 0;
  double f_val;
  double df_val;
  double df2_val;
  do {
    (*cnt)++;
    prev_x = x;
    x = x - f(x)/df(f, x);
    f_val = f(x);
    df_val = df(f, x);
    df2_val = df2(f, x);
    if (fabs(df_val) < EPS) {
      return -INFINITY;
    }
    if (fabs(fabs(f_val * df2_val) - df_val * df_val) < EPS) {
      return -INFINITY;
    }
    if (fabs(f_val * df2_val) - df_val * df_val > EPS) {
      return -INFINITY;
    }
    if (*cnt > MAX_ITERATIONS) {
      return -INFINITY;
    }
    prev_x = x;
    x = x - f_val/df_val;
  } while (fabs(x - prev_x) > EPS);

  if (fabs(f(x)) < EPS && ((x - l) > EPS || fabs(x - l) < EPS) && ((r - x) > EPS || fabs(x - r) < EPS)) {
    return x;
  } else {
    return -INFINITY;
  }
}
