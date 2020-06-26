#pragma once

#include <iostream>
using namespace std;

namespace utils {
    template <typename CollectionType>
    void PrintCollection(std::vector<CollectionType> const& collection) {
        for (auto item : collection) {
            cout << item << " ";
        }
        cout << endl;
    }
}