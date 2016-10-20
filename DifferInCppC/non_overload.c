#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int add_int(int lhs, int rhs) { return lhs + rhs; }

void add_str(const char *lhs, int lhs_size, const char *rhs, int rhs_size,
             char *res, int *res_size) {
  memcpy(res, lhs, lhs_size);
  memcpy(res + lhs_size, rhs, rhs_size);
  res[lhs_size + rhs_size] = '\0';
  *res_size = lhs_size + rhs_size;
}

int main() {
  printf("%d + %d = %d\n", 1, 2, add_int(1, 2));
  const char *lhs = "abcd";
  const char *rhs = "efgh";
  char *res = malloc(sizeof(char) * 20);
  int res_size = 0;
  add_str(lhs, 4, rhs, 4, res, &res_size);
  printf("%s + %s = %s, size:%d\n", lhs, rhs, res, res_size);
  free(res);
  return 0;
}
