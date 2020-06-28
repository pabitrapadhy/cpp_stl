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
    nativeTypeCollection.push_back(10);
    std::push_heap(begin(nativeTypeCollection), end(nativeTypeCollection));
    PrintCollection(nativeTypeCollection);

    // NOTE:
    // Both std::make_heap() and std::push_heap() are rearranging elements to satisfy the max heap property.
    // But, std::make_heap() is O(N), whereas std::push_heap() is O(log N), where N = std::difference(start, last)
    // so, if you already have a heap then use push_heap() instead of make_heap().
    // Also, if you don't have a heap in the first place, then don't use the push_heap() directly, it won't work.

    MaxHeapify(userDefinedTypeCollection);
    cout << "Binary Max Heap : ";
    PrintCollection(userDefinedTypeCollection);
    userDefinedTypeCollection.emplace_back(15); // why emplace_back ? : https://en.cppreference.com/w/cpp/container/vector/emplace_back
    std::push_heap(begin(userDefinedTypeCollection), end(userDefinedTypeCollection));
    PrintCollection(userDefinedTypeCollection);

    return 0;
}