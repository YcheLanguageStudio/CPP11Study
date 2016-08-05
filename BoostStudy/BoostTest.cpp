//
// Created by cheyulin on 1/5/16.
//

#include <boost/regex.hpp>
#include <iostream>
#include <boost/algorithm/string.hpp>

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

void TestMachSpace() {
    using namespace boost;
    using namespace std;
    boost::regex pat("[0-9]+.*");
    boost::smatch matches;
    string line("comm 34234 432 43 32,");
    if (boost::regex_match(line, matches, pat))
        cout << "Ok!!!" << endl;
    else
        cout << "Fail" << endl;
}

void TestSplit() {
    using namespace boost;
    using namespace std;
    string line("234 432,432, 23");
    vector<string> strVec;
//    boost::split(strVec, line, is_any_of(" ,"));

    boost::regex re(",");
    line = boost::regex_replace(line, re, " ");
    cout << line << endl;
    stringstream str_stream(line);
    int hello;
    while (true) {
        str_stream >> hello;
        cout << hello << endl;
        if (str_stream.eof()) {
            break;
        }
    }
}


int main() {
    std::string line = "cylpphaha";
    boost::regex pat("cyl.*haha");
    boost::smatch matches;
    if (boost::regex_match(line, matches, pat))
        std::cout << "yes";
    TestStartWith();
    TestMachSpace();
    TestSplit();
    getchar();
}