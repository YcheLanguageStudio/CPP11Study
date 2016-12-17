//
// Created by cheyulin on 7/22/16.
//
//
#include <iostream>
#include <assert.h>
#include <memory>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> my_map;
    my_map.insert(make_pair(1, "one"));
    my_map.insert(make_pair(1, "two"));
    my_map.insert(make_pair(2, "two"));
    for (auto iter = my_map.begin(); iter != my_map.end(); ++iter) {
        cout << iter->first << "," << iter->second<<endl;
    }
    my_map[2]="three";
    cout <<endl;
    for (auto iter = my_map.begin(); iter != my_map.end(); ++iter) {
        cout << iter->first << "," << iter->second<<endl;
    }
    for(auto& pair:my_map){
        cout << pair.first<<","<<pair.second<<endl;
    }
}
