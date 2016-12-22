//
// Created by cheyulin on 12/22/16.
//

#include <iostream>
#include <algorithm>

using namespace std;

void DemoNoCaptureLambdas() {
    auto my_vec = vector<int>{1, 2, 3};
    auto iter = max_element(my_vec.begin(), my_vec.end(),
                            [](const auto &left, const auto &right) { return left > right; });
    cout << "max ele:" << *iter << endl;
}

int main() {
    DemoNoCaptureLambdas();
}