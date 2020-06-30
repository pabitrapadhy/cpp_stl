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

    MaxHeapify(nativeTypeCollection);
    cout << "Binary Max Heap : ";
    PrintCollection(nativeTypeCollection);
    std::pop_heap(begin(nativeTypeCollection), end(nativeTypeCollection));
    nativeTypeCollection.pop_back();
    PrintCollection(nativeTypeCollection);

    MaxHeapify(userDefinedTypeCollection);
    cout << "Binary Max Heap : ";
    PrintCollection(userDefinedTypeCollection);
    auto heapSize = std::distance(begin(userDefinedTypeCollection), end(userDefinedTypeCollection));
    cout << "If we don't do collection.pop_back() after std::pop_heap() "
            "and decrease the end iterator by 1 everytime, we get a sorted list." << endl;
    for (auto i = 0; i < heapSize; ++i) {
        std::pop_heap(userDefinedTypeCollection.begin(), userDefinedTypeCollection.end() - i);
    }
    PrintCollection(userDefinedTypeCollection);

    return 0;
}