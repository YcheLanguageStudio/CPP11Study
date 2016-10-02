#include "stdio.h"

void increment(int *int_ptr) {
  printf("Before: %d\n", *int_ptr);
  *int_ptr += 1;
}

int main() {
  int integer = 0;
  increment(&integer);
  printf("After: %d\n", integer);
}
