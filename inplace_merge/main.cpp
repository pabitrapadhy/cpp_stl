#include <iostream>
#include <vector>
#include "StrongDataTypes.h"
#include "Utils.h"

using namespace std;
using namespace utils;

template <class Iterator>
void MergeSort(Iterator first, Iterator last) {
    if (std::distance(first, last) > 1) {
        Iterator middle = first + (last - first) / 2;
        MergeSort(first, middle);
        MergeSort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

int main() {
    // simple integer container
    std::vector<int> nativeTypeCollection {1, 4, 5, 3, 6, 8, 9, 0, 2, 7};

    // custom class type container
    std::vector<Integer> userDefinedTypeCollection {
            Integer{4},
            Integer{2},
            Integer{5},
            Integer{1},
            Integer{6},
            Integer{9},
            Integer{8},
            Integer{7},
            Integer{3},
            Integer{0}
    };

    cout << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Sorted: ";
    MergeSort(nativeTypeCollection.begin(), nativeTypeCollection.end());
    PrintCollection(nativeTypeCollection);

    cout << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Sorted: ";
    MergeSort(userDefinedTypeCollection.begin(), userDefinedTypeCollection.end());
    PrintCollection(userDefinedTypeCollection);

    return 0;
}