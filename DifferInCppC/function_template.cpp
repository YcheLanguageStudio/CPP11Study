#include <iostream>
using namespace std;
template <typename T> T add(T lhs, T rhs) { return lhs + rhs; }

int main() {
  cout << "1 + 2 =" << add(1, 2) << endl;
  cout << "1.0 + 2.0 = " << add(1.0, static_cast<double>(2)) << endl;
  cout << "1.0 + 2.0 = " << add<double>(1.0, 2) << endl;
}
