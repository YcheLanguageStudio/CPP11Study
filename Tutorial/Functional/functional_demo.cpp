//
// Created by cheyulin on 12/16/16.
//
// References:
// https://meetingcpp.com/tl_files/mcpp/slides/12/FunctionalProgrammingInC++11.pdf
// http://www.linux-magazin.de/Ausgaben/2011/01/C/(offset)/2

#include <algorithm>
#include <iostream>

using namespace std;

// Compiler will regard no-caputre lambda expression into function pointer, else into function object
// Thus, closure is either a function or a anonymous class with operator()
auto is_odd_lambda = [](int i) { return (i % 2) == 1; };

// Generic Lambda
auto print_lambda = [](auto printable) { cout << printable << ","; };

void DemoMap(vector<int> &my_int_list, vector<string> &my_str_list) {
    vector<int> res_int_list;
    cout << "Map Demo:" << endl;
    transform(my_int_list.begin(), my_int_list.end(), back_inserter(res_int_list), [](int i) { return i * i; });
    for_each(res_int_list.begin(), res_int_list.end(), print_lambda);
    cout << endl;

    vector<int> my_length_list;
    transform(my_str_list.begin(), my_str_list.end(), back_inserter(my_length_list),
              [](const string &s) { return s.length(); });
    for_each(my_length_list.begin(), my_length_list.end(), print_lambda);
    cout << endl << endl;
}

void DemoFilter(vector<int> &my_int_list, vector<string> &my_str_list) {
    cout << "Filter Demo:" << endl;
    auto res_int_list = my_int_list;
    auto end_iter = remove_if(res_int_list.begin(), res_int_list.end(), [](int i) { return i % 2 != 0; });
    res_int_list.resize(end_iter - res_int_list.begin());

    for_each(res_int_list.begin(), res_int_list.end(), print_lambda);
    cout << endl;

    auto res_str_list = my_str_list;
    auto end_iter2 = remove_if(res_str_list.begin(), res_str_list.end(), [](string &s) { return !isupper(s[0]); });
    res_int_list.resize(end_iter2 - res_str_list.begin());
    for_each(res_str_list.begin(), res_str_list.end(), print_lambda);
    cout << endl << endl;
}

void DemoFold(vector<int> &my_int_list, vector<string> &my_str_list) {
    cout << "Reduce/Fold Demo:" << endl;
    auto res0 = accumulate(my_int_list.begin(), my_int_list.end(), 1, [](int left, int right) { return left * right; });
    cout << res0 << endl;

    auto res1 = accumulate(my_str_list.begin(), my_str_list.end(), string("Haha"),
                           [](string &left, string &right) { return left + ":" + right; });
    cout << res1 << endl << endl;
}

void DemoPartition() {
    cout << "Partition Demo:" << endl;
    vector<int> int_list;
    for (int i = 1; i < 10; ++i) int_list.push_back(i);

    auto bound_iter = partition(int_list.begin(), int_list.end(), is_odd_lambda);

    cout << "Odd elements:";
    for_each(int_list.begin(), bound_iter, print_lambda);
    cout << endl;
    cout << "Even elements:";
    for_each(bound_iter, int_list.end(), print_lambda);
    cout << endl << endl;
}

void DemoFind() {
    cout << "Find Demo:" << endl;
    vector<int> int_list = {10, 25, 40, 55};
    auto iter = find_if(int_list.begin(), int_list.end(), is_odd_lambda);
    cout << "The first odd value is " << *iter << endl << endl;
}

int main() {
    vector<int> my_int_list;
    for (auto i = 1; i < 6; i++) my_int_list.push_back(i);
    vector<string> my_str_list{"Programming", "in", "a", "functional", "style."};

    //Map, Filter, Fold/Reduce
    DemoMap(my_int_list, my_str_list);
    DemoFilter(my_int_list, my_str_list);
    DemoFold(my_int_list, my_str_list);

    //Other Utilities
    DemoPartition();
    DemoFind();
}
