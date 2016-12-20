#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<1073741823>& statistic_bitset=*(new bitset<1073741823>());
    bitset<9> my_biset;
    cout << my_biset.count()<<endl;
    for (auto i = 0; i < 9; i++)
        my_biset.set(i, true);
    for (auto i = 0; i < 9; i += 2)
        my_biset.set(i, false);
    my_biset.set(1, false);
    cout << my_biset.count() << endl;
    cout << sizeof(long long) << endl;
    long long number = 10240;
    number >>= 3;
    cout << number << endl;
}