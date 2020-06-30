#include <iostream>
#include <vector>
#include "StrongDataTypes.h"
#include "Utils.h"

using namespace std;
using namespace utils;

template <typename CollectionType>
void MaxHeapify(std::vector<CollectionType>& collection) {
    std::make_heap(begin(collection), end(collection));
}

int main() {
    // simple integer container
    std::vector<int> nativeTypeCollection {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

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

    cout << "Collection to create Max Heap :";
    PrintCollection(nativeTypeCollection);
    MaxHeapify(nativeTypeCollection);
    cout << "Binary Max Heap : ";
    PrintCollection(nativeTypeCollection);

    cout << "Collection to create Max Heap :";
    PrintCollection(userDefinedTypeCollection);
    MaxHeapify(userDefinedTypeCollection);
    cout << "Binary Max Heap : ";
    PrintCollection(userDefinedTypeCollection);

    std::vector<int> simpleCollection {5, 9, 3, 2, 4, 8, 3};
    cout << endl << "Collection to create Min Heap :";
    PrintCollection(simpleCollection);
    cout << "Binary Min Heap : ";
    std::make_heap(simpleCollection.begin(), simpleCollection.end(), std::greater<>{});
    PrintCollection(simpleCollection);

    return 0;
}