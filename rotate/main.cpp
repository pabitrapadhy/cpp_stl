#include <iostream>
#include <vector>
#include "StrongDataTypes.h"
#include "Utils.h"

using namespace std;
using namespace utils;

int main() {
    // simple integer container
    std::vector<int> nativeTypeCollection {1, 4, 5, 3, 6, 8, 9, 0, 2, 7};

    // custom class type container
    std::vector<Integer> userDefinedTypeCollection {
            Integer{0},
            Integer{1},
            Integer{2},
            Integer{3},
            Integer{4},
            Integer{5},
            Integer{6},
            Integer{7},
            Integer{8},
            Integer{9}
    };

    cout << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Simple rotation to left (start=begin, middle= begin+2): ";
    std::rotate(nativeTypeCollection.begin(), nativeTypeCollection.begin() + 2, nativeTypeCollection.end());
    PrintCollection(nativeTypeCollection);

    cout << endl << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Simple rotation to right (start=rbegin, middle= rbegin+1): ";
    std::rotate(userDefinedTypeCollection.rbegin(), userDefinedTypeCollection.rbegin() + 1, userDefinedTypeCollection.rend());
    PrintCollection(userDefinedTypeCollection);

    cout << endl << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Simple rotation to left (start = begin+2, middle= begin+3): ";
    std::rotate(userDefinedTypeCollection.begin() + 2, userDefinedTypeCollection.begin() + 3, userDefinedTypeCollection.end());
    PrintCollection(userDefinedTypeCollection);

    cout << endl << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Simple rotation to left (start=begin, middle= begin (no change): ";
    std::rotate(nativeTypeCollection.begin(), nativeTypeCollection.begin(), nativeTypeCollection.end());
    PrintCollection(nativeTypeCollection);

    cout << endl << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Simple rotation to left (start=begin, middle= end (full rotation, no change): ";
    std::rotate(nativeTypeCollection.begin(), nativeTypeCollection.end(), nativeTypeCollection.end());
    PrintCollection(nativeTypeCollection);

    cout << endl << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Simple rotation to left (start=begin, middle= begin+2, end = end-2): ";
    std::rotate(nativeTypeCollection.begin(), nativeTypeCollection.begin() + 2, nativeTypeCollection.end() - 2);
    PrintCollection(nativeTypeCollection);

    return 0;
}