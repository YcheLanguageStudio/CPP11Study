#include <iostream>
using namespace std;
class ResourceManager {
public:
  ResourceManager() {
    cout << "Acquire Resource, e.g, heap memory allocation/file handle "
            "operation/other resources"
         << endl;
  }

  ~ResourceManager() {
    cout << "Release Resource, e.g, heap memory allocation/file handle "
            "operation/other resources"
         << endl;
  }
};

int main() { ResourceManager my_res_man; }
