#include "stdio.h"

int main() {
//自己做编译器做的事情。。。
#undef ElemType
#undef FuncName
#define FuncName add_int
#define ElemType int
#include "pre_processing.h"
  printf("1 + 2 = %d\n", add_int(1, 2));

#undef ElemType
#undef FuncName
#define FuncName add_double
#define ElemType double
#include "pre_processing.h"
  printf("1 + 2 = %.2lf\n", add_double(1.0, 2));
}
