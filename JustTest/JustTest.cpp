//
// Created by cheyulin on 4/14/16.
//
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
    cout << "hello" << endl;
    vector <string> temp;
    temp.push_back("1");
    temp.push_back("2");
    map<int,int>::iterator it;
    queue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);

    cout << "my_queue front:" << my_queue.front() <<endl;
    my_queue.pop();
    cout << "my_queue front:" << my_queue.front() <<endl;

}

