#pragma once
#include <stdint.h>

double df(double (*f)(double), double x);

double df2(double (*f)(double), double x);

double binary_search_method(double l, double r, double (*f)(double), uint32_t *cnt);

double iteration_method(double l, double r, double (*f)(double), uint32_t *cnt);

double newton_method(double l, double r, double (*f)(double), uint32_t *cnt);
