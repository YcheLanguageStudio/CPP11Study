#include <cstring>
#include <iostream>
using namespace std;

int add(int lhs, int rhs) { return lhs + rhs; }

void add(const char *lhs, int lhs_size, const char *rhs, int rhs_size,
         char *res, int &res_size) {
  memcpy(res, lhs, lhs_size);
  memcpy(res + lhs_size, rhs, rhs_size);
  res[lhs_size + rhs_size] = '\0';
  res_size = lhs_size + rhs_size;
}

int main() {
  cout << "1 + 2 = " << add(1, 2) << endl;
  const char *lhs = "abcd";
  const char *rhs = "efgh";
  char *res = new char[20];
  int res_size = 0;
  add(lhs, 4, rhs, 4, res, res_size);
  cout << lhs << " + " << rhs << " = " << res << ", size:" << res_size;
  delete[] res;
  return 0;
}
