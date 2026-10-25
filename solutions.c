#include "solutions.h"
#include <math.h>
#include <stdint.h>

const double EPS = 1e-10;

double df(double (*f)(double), double x) {
  return (f(x + EPS) - f(x - EPS)) / (2 * EPS);
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
    if (*cnt > 10000) {
      break;
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
  do {
    (*cnt)++;
    prev_x = x;
    x = x - f(x)/df(f, x);
  } while (fabs(x - prev_x) > EPS);
  
  if (fabs(f(x)) < EPS && ((x - l) > EPS || fabs(x - l) < EPS) && ((r - x) > EPS || fabs(x - r) < EPS)) {
    return x;
  } else {
    return -INFINITY;
  }
}
