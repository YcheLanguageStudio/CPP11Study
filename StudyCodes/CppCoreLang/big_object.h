//
// Created by cheyulin on 12/22/16.
//

#ifndef CPP11FEATURESSTUDY_BIG_OBJECT_H
#define CPP11FEATURESSTUDY_BIG_OBJECT_H

#include <vector>

using namespace std;


struct IntWrapper {
    int integer;

    IntWrapper() = delete;

    IntWrapper(int i) : integer(i) { cout << "Construct" << i << endl; }

    IntWrapper(const IntWrapper &other) { cout << "Copy Construct IntWrapper" << endl; };

    IntWrapper(IntWrapper &&other) { cout << "Move Construct IntWrapper" << endl; };

    IntWrapper &operator=(const IntWrapper &other) {
        cout << "Copy Assign IntWrapper" << endl;
        integer = other.integer;
        return *this;
    }

    IntWrapper &operator=(IntWrapper &&other) {
        cout << "Move Assign IntWrapper" << endl;
        integer = other.integer;
        return *this;
    }
};

namespace std {
    ostream &operator<<(ostream &my_ostream, const IntWrapper &int_wrapper) {
        return my_ostream << to_string(int_wrapper.integer);
    }
}

struct BigObject {
    vector<IntWrapper> wrapper_vec;

    BigObject(int i) : wrapper_vec(10, i) { cout << "Construct with " << i << endl; }

    BigObject(const BigObject &other) { cout << "Copy Construct" << endl; };

    BigObject(BigObject &&other) { cout << "Move Construct" << endl; }

    BigObject &operator=(const BigObject &other) {
        cout << "Copy Assign" << endl;
        this->wrapper_vec = other.wrapper_vec;
        return *this;
    }

    BigObject &operator=(BigObject &&other) {
        cout << "Move Assign" << endl;
        this->wrapper_vec = move(other.wrapper_vec);
        return *this;
    }
};

struct President {
    std::string name;
    std::string country;
    int year;

    President(std::string p_name, std::string p_country, int p_year)
            : name(std::move(p_name)), country(std::move(p_country)), year(p_year) {
        std::cout << "I am being constructed.\n";
    }

    President(President &&other)
            : name(std::move(other.name)), country(std::move(other.country)), year(other.year) {
        std::cout << "I am being moved.\n";
    }

    President &operator=(const President &other) = default;
};

#endif //CPP11FEATURESSTUDY_BIG_OBJECT_H
