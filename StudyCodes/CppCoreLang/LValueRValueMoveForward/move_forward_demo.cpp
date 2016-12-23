//
// Created by cheyulin on 4/14/16.
//
#include <iostream>
#include <algorithm>

#include "../../Utilities/pretty_print.h"
#include "../big_object.h"

using namespace std;

void DemoForwardRef(auto &&input) {
    cout << input << endl;
}

void DemoSTLForward() {
    vector<President> elections;
    cout << "emplace_back:\n";
    elections.emplace_back("Nelson Mandela", "South Africa", 1994);

    vector<President> reElections;
    cout << "\npush_back:\n";
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));

    cout << "\nContents:\n";
    for (President const &president: elections) {
        cout << president.name << " was elected president of "
             << president.country << " in " << president.year << ".\n";
    }
    for (President const &president: reElections) {
        cout << president.name << " was re-elected president of "
             << president.country << " in " << president.year << ".\n";
    }
}

int main() {
    auto integer_ptr = make_unique<int>(1);
    auto integer = 2;
    auto my_str = string("haha");

    DemoSTLForward();

    DemoForwardRef(integer);
    DemoForwardRef(my_str);
    DemoForwardRef(move(my_str));
    DemoForwardRef(*integer_ptr);
}