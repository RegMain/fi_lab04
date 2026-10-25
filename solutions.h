#pragma once
#include <stdint.h>

double binary_search_method(double l, double r, double (*f)(double), uint32_t *cnt);

double iteration_method(double l, double r, double (*f)(double), uint32_t *cnt);

double newton_method(double l, double r, double (*F)(double), double (*f)(double), uint32_t *cnt);
