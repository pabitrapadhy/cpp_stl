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

    cout << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Partially Sorted: ";
    std::partial_sort(nativeTypeCollection.begin(), nativeTypeCollection.begin() + 3, nativeTypeCollection.end());
    PrintCollection(nativeTypeCollection);

    cout << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Partially Sorted: ";
    std::partial_sort(userDefinedTypeCollection.begin() + 2, userDefinedTypeCollection.begin() + 8, userDefinedTypeCollection.end());
    PrintCollection(userDefinedTypeCollection);

    cout << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Partially Sorted (Descending): ";
    std::partial_sort(
            userDefinedTypeCollection.begin() + 2,
            userDefinedTypeCollection.begin() + 8,
            userDefinedTypeCollection.end(), std::greater<>());
    PrintCollection(userDefinedTypeCollection);

    return 0;
}