//
// Created by cheyulin on 1/5/16.
//

#include <boost/regex.hpp>
#include <iostream>

int main(){
    std::string line="cylpphaha";
    boost::regex pat( "cyl.*haha" );
    boost::smatch matches;
    if (boost::regex_match(line, matches, pat))
        std::cout << "yes";
}