//
// Created by cheyulin on 9/11/16.
//
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

class my_string {
private:
    char *data_{nullptr};
    size_t len_{0};

    void alloc_and_construct(const char *s) {
        cout << "Expensive Operation" << endl;
        data_ = new char[len_ + 1];
        memcpy(data_, s, len_);
        data_[len_] = '\0';
    }

    void go_deallocate(char *data) {
        if (data_)
            free(data);
    }

public:
    my_string() = default;

    virtual ~my_string() {
        cout << "Destructor" << endl;
        go_deallocate(data_);
    }

    my_string(const char *p) : len_(strlen(p)) {
        alloc_and_construct(p);
    }

    my_string(const my_string &str) {
        go_deallocate(data_);
        len_ = str.len_;
        alloc_and_construct(str.data_);
        cout << "Copy Constructor is called! source: " << str.data_ << endl;
    }

    my_string &operator=(const my_string &str) {
        go_deallocate(data_);
        if (this != &str) {
            len_ = str.len_;
            alloc_and_construct(str.data_);
        }
        cout << "Copy Assignment is called! source: " << str.data_ << endl;
        return *this;
    }

#ifdef ENABLE_MOVE

    my_string(my_string &&str) {
        go_deallocate(data_);
        cout << "Move Constructor is called! source: " << str.data_ << endl;
        len_ = str.len_;
        data_ = str.data_;
        str.len_ = 0;
        str.data_ = nullptr;
    }

    my_string &operator=(my_string &&str) {
        go_deallocate(data_);
        cout << "Move Assignment is called! source: " << str.data_ << endl;
        if (this != &str) {
            len_ = str.len_;
            data_ = str.data_;
            str.len_ = 0;
            str.data_ = nullptr;
        }
        return *this;
    }

#endif
};

int main() {
    //Assignment, transfer the ownership from temporary to a
    my_string a;
    a = my_string("Hello");

    //Constructor0, transfer the ownership from a to b
    my_string b = move(a);

    //Constructor1, transfer the ownership from temporary to the specific my_string object in vec
    vector<my_string> vec;
    vec.push_back(my_string("World"));
}




