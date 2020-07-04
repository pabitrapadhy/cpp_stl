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
            Integer{9},
            Integer{3},
            Integer{2},
            Integer{4},
            Integer{1},
            Integer{5},
            Integer{6},
            Integer{7},
            Integer{8},
            Integer{0}
    };

    auto predicateOne = [] (int i) {
        return i == 100;
    };

    auto predicateTwo = [] (Integer i) {
        return i.get() % 2 == 0;
    };

    cout << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Partitioned Collection: ";
    std::partition(nativeTypeCollection.begin(), nativeTypeCollection.end(), predicateOne);
    PrintCollection(nativeTypeCollection);

    auto partitionPointOne = std::partition_point(nativeTypeCollection.begin(), nativeTypeCollection.end(), predicateOne);
    if (partitionPointOne != nativeTypeCollection.end()) {
        cout << "First mismatch at index "
        << std::distance(nativeTypeCollection.begin(), partitionPointOne)
        << " with element "
        << *partitionPointOne << endl;
    }


    cout << endl << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Partitioned Collection: ";
    std::partition(userDefinedTypeCollection.begin(), userDefinedTypeCollection.end(), predicateTwo);
    PrintCollection(userDefinedTypeCollection);

    auto partitionPointTwo = std::partition_point(userDefinedTypeCollection.begin(), userDefinedTypeCollection.end(), predicateTwo);
    if (partitionPointTwo != userDefinedTypeCollection.end()) {
        cout << "First mismatch at index "
             << std::distance(userDefinedTypeCollection.begin(), partitionPointTwo)
             << " with element "
             << *partitionPointTwo << endl;
    }

    return 0;
}