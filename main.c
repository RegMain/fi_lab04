#include <stdio.h>
#include <stdint.h>
#include "solutions.h"
#include "functions.h"

int main(void) {
  // 23, 24, 25
  uint32_t cnt = 0;
  printf("3 * x - 4 * ln x - 5 = 0 on [2, 4]\n");
  printf("Binary search method: %f", binary_search_method(2, 4, F23, &cnt));
  printf(" (%d iteration(s).)\n", cnt);
  printf("Iteration method: %f", iteration_method(2, 4, Fx23, &cnt));
  printf(" (%d iteration(s).)\n", cnt);
  printf("Newton method: %f", newton_method(2, 4, F23, &cnt));
  printf(" (%d iteration(s).)\n", cnt);

  printf("\n");
  printf("cos(2 / x) - 2 * sin(1 / x) + 1 / x = 0 on [1, 2]\n");
  printf("Binary search method: %f", binary_search_method(1, 2, F24, &cnt));
  printf(" (%d iteration(s).)\n", cnt);  
  printf("Iteration method: %f", iteration_method(1, 2, Fx24, &cnt));
  printf(" (%d iteration(s).)\n", cnt);
  printf("Newton method: %f", newton_method(1, 2, F24, &cnt));
  printf(" (%d iteration(s).)\n", cnt);

  printf("\n");
  printf("sqrt(1 - 0.4 * x^2) - arcsin x = 0 on [0, 1]\n");
  printf("Binary search method: %f", binary_search_method(0, 1, F25, &cnt));
  printf(" (%d iteration(s).)\n", cnt);
  printf("Iteration method: %f", iteration_method(0, 1, Fx25, &cnt));
  printf(" (%d iteration(s).)\n", cnt);
  printf("Newton method: %f", newton_method(0, 1, F25, &cnt));
  printf(" (%d iteration(s).)\n", cnt);
  return 0;
}
