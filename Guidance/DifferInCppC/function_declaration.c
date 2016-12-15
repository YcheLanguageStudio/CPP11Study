#include <stdio.h>
int main() {
  foo();
  return 0;
}

//虽然是一种不太好的编码风格
//一般好的C代码都是要求在使用之前进行函数声明
//打开 -Wall 编译器会警告我们不要这样写
void foo() { printf("Hello world"); }
