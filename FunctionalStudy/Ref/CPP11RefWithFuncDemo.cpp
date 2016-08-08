//
// Created by cheyulin on 8/8/16.
//

#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct square {
    using result_type=void;

    void operator()(int &x) {
        x = x * x;
    }
};

int main() {
    //*pfunc  double(double)
    typedef double (*pfunc)(double);
    pfunc pf = sqrt;
    cout << std::ref(pf)(5.0)<<endl;

    square sq;
    int x = 5;
    std::ref(sq)(x);
    cout << x << endl;

    std::vector<int> v = {1, 2, 3, 4, 5};
    for_each(v.begin(), v.end(), std::ref(sq));
}
