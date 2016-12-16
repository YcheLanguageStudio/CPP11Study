//
// Created by cheyulin on 12/16/16.
//
// Reference: https://meetingcpp.com/tl_files/mcpp/slides/12/FunctionalProgrammingInC++11.pdf
// http://www.linux-magazin.de/Ausgaben/2011/01/C/(offset)/2

#include <algorithm>
#include <iostream>

using namespace std;

void demoMap(vector<int> my_int_list, vector<string> my_str_list) {
    cout << "Map Demo:" << endl;
    auto print_lambda = [](int num) { cout << num << ","; };
    transform(my_int_list.begin(), my_int_list.end(), my_int_list.begin(), [](int i) { return i * i; });
    for_each(my_int_list.begin(), my_int_list.end(), print_lambda);
    cout << endl;

    vector<int> my_length_list;
    transform(my_str_list.begin(), my_str_list.end(), back_inserter(my_length_list),
              [](const string &s) { return s.length(); });
    for_each(my_length_list.begin(), my_length_list.end(), print_lambda);
    cout << endl;
    cout << endl;
}

void demoFilter(vector<int> my_int_list, vector<string> my_str_list) {
    cout << "Filter Demo:" << endl;
    auto end_iter = remove_if(my_int_list.begin(), my_int_list.end(), [](int i) { return i % 2 != 0; });
    auto print_lambda = [](auto ele) { cout << ele << ","; };
    for_each(my_int_list.begin(), end_iter, print_lambda);
    cout << endl;

    auto end_iter2 = remove_if(my_str_list.begin(), my_str_list.end(), [](string &s) { return !isupper(s[0]); });
    for_each(my_str_list.begin(), end_iter2, print_lambda);
    cout << endl;
    cout << endl;
}

void demoFold(vector<int> my_int_list, vector<string> my_str_list) {
    cout << "Fold Demo:" << endl;
    auto res0 = accumulate(my_int_list.begin(), my_int_list.end(), 1, [](int left, int right) { return left * right; });
    cout << res0 << endl;

    auto res1 = accumulate(my_str_list.begin(), my_str_list.end(), string(""),
                           [](string &left, string &right) { return left + ":" + right; });
    cout << res1 << endl;
    cout <<endl;
}

int main() {
    vector<int> my_int_list = {1, 2, 3, 4, 5};
    vector<string> my_str_list{"Programming", "in", "a", "functional", "style."};

    //All Parameters Passed in Copy Manner
    demoMap(my_int_list, my_str_list);
    demoFilter(my_int_list, my_str_list);
    demoFold(my_int_list, my_str_list);
}
