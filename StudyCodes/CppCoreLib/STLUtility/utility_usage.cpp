#include <iostream>
#include <bitset>
#include <memory>

using namespace std;

void DemoBitSet() {
    auto statistic_bitset_ptr = make_unique<bitset<1073741823>>();
    auto &statistic_bitset = *statistic_bitset_ptr;
    cout << statistic_bitset.size() << endl;

    bitset<9> my_biset;
    for (auto i = 0; i < 9; i++) { my_biset.set(i, true); }
    for (auto i = 0; i < 9; i += 2) { my_biset.set(i, false); }
    my_biset.set(1, false);

    cout << my_biset.count() << endl;
}

void DemoBitSet1() {
    auto bs1 = bitset<9>("110001111");
    cout << bs1.to_string() << '\n';


    auto bs2 = bs1 << 2;
    cout << bs2.to_string() << '\n';

    auto bs3 = bs1 >> 2;
    cout << bs3.to_string() << endl;
}

void DemoAcceptInt() {
    auto bs0 = bitset<8 * sizeof(int)>(123);
    cout << bs0 << endl;
}

int main() {
    DemoBitSet();
    DemoBitSet1();
    DemoAcceptInt();
}