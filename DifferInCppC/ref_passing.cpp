#include <iostream>
using namespace std;

void increment(int &int_ptr) {
  cout << "Before: " << int_ptr << endl;
  int_ptr += 1;
}

int main() {
  int integer = 0;
  increment(integer);
  cout << "After: " << integer << endl;
}
