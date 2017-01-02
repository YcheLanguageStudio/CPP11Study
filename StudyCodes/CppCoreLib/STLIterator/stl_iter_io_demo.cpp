//
// Created by cheyulin on 1/2/17.
//

#include <iostream>
#include <fstream>
#include <set>
#include <iterator>

using namespace std;

int main() {
    string from, to;
    cin >> from >> to;

    ifstream ifs{from};
    ofstream ofs{to};

    auto iter_begin = istream_iterator<string>{ifs};
    auto iter_end = istream_iterator<string>{};
    set<string> b{iter_begin, iter_end};
    copy(b.begin(), b.end(), ostream_iterator<string>(ofs, "\n"));
}
