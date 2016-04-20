//
// Created by cheyulin on 4/19/16.
//

#include <sys/mman.h> // for mmap(2)
#include <sys/stat.h> // for fstat64(2)
#include <algorithm>
#include <fcntl.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <zconf.h>


using namespace std;

int main() {
    string filename ="/home/cheyulin/gitrepos/CPP11Study/FileSystemTest/file.txt";
    int graphFD = open(filename.c_str(), O_RDONLY);
    cout << graphFD<<endl;
    close(graphFD);
    return 0;
//    Close(graphFD);
}
