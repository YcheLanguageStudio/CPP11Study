//
// Created by cheyulin on 1/5/16.
//

#include <boost/regex.hpp>
#include <iostream>

void TestStartWith() {
    using namespace boost;
    using namespace std;
    boost::regex pat("$#.*");
    boost::smatch matches;
    string line("#haha");
    string line2("dfsf#");
    if (boost::regex_match(line, matches, pat))
        cout << "Ok" << endl;
    if (!boost::regex_match(line, matches, pat))
        cout << "No" << endl;
}

int main() {
    std::string line = "cylpphaha";
    boost::regex pat("cyl.*haha");
    boost::smatch matches;
    if (boost::regex_match(line, matches, pat))
        std::cout << "yes";
    TestStartWith();
}