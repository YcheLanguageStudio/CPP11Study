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

int main() {
    DemoBitSet();
}