//
// Created by cheyulin on 8/15/16.
//

#include <iostream>

using namespace std;
enum class KeyAlignment {
    small = 70,
    medium = 300,
    large = 3000
};

enum class ValueAlignment {
    small = 160,
    medium = 3000,
    large = 30000
};

enum class Hello{
    hello=1000000
};

constexpr int extra_alignment = 1;
constexpr char *extra_split_string = "\n";
constexpr char *small_file_name = "small.db";
constexpr char *middle_file_name = "middle.db";
constexpr char *big_file_name = "big.db";

struct DataSetInfo {
    int key_alignment;
    int value_alignment;
    int whole_alignment;
    string file_name;

    DataSetInfo(int key_alignment, int value_alignment,
                string &&file_name) : key_alignment(key_alignment), value_alignment(value_alignment),
                                      file_name(std::move(file_name)) {
        whole_alignment = key_alignment + value_alignment + extra_alignment;
    }
};

int main() {
    cout << static_cast<int>(Hello::hello)<<endl;
    cout << static_cast<int>(KeyAlignment::small) << extra_split_string;
    cout << static_cast<int>(ValueAlignment::small) << extra_split_string;
    cout << static_cast<int>(KeyAlignment::medium) << extra_split_string;
    cout << endl << endl;
    cout << static_cast<int>(ValueAlignment::medium) << extra_split_string;
    cout << static_cast<int>(KeyAlignment::large) << extra_split_string;
    cout << static_cast<int>(ValueAlignment::large) << extra_split_string;
    cout << string(small_file_name) << endl;
    cout << string(middle_file_name) << endl;
    cout << string(big_file_name) << endl;


    DataSetInfo my_data_set(static_cast<int>(KeyAlignment::small), static_cast<int>(ValueAlignment::small),
                            string(small_file_name));
    cout << my_data_set.key_alignment << "," << my_data_set.value_alignment << "," << my_data_set.whole_alignment << ","
         << my_data_set.file_name << endl;
}
