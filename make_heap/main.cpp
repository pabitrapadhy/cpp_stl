#include <iostream>
#include <vector>
#include "StrongDataTypes.h"

using namespace std;

template <typename CollectionType>
void PrintCollection(std::vector<CollectionType> const& collection) {
    for (auto item : collection) {
        cout << item << " ";
    }
    cout << endl;
}

template <typename CollectionType>
void CreateBinaryMaxHeap(std::vector<CollectionType>& collection) {
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

    CreateBinaryMaxHeap(nativeTypeCollection);
    PrintCollection(nativeTypeCollection);

    CreateBinaryMaxHeap(userDefinedTypeCollection);
    PrintCollection(userDefinedTypeCollection);


    // TODO: move this to another director, as a part of different STL type
    cout << std::boolalpha << std::is_heap(begin(nativeTypeCollection), end(nativeTypeCollection)) << endl;
    cout << std::boolalpha << std::is_heap(begin(userDefinedTypeCollection), end(userDefinedTypeCollection)) << endl;

    cout << std::boolalpha << std::is_heap(begin(nativeTypeCollection), begin(nativeTypeCollection) + 5) << endl;
    cout << std::boolalpha << std::is_heap(begin(userDefinedTypeCollection), begin(userDefinedTypeCollection)) << endl;

    std::vector<int> testContainerOne {1,9,8,6,10,5};
    auto isHeapBasic = std::is_heap_until(begin(testContainerOne), begin(testContainerOne) + 2);
    auto isHeapCustom = std::is_heap_until(begin(testContainerOne), end(testContainerOne));

    std::vector<int> testContainerTwo {9,8,6,7,5};
    testContainerTwo.push_back(10);
    std::push_heap(begin(testContainerTwo), end(testContainerTwo));

    cout << "Binary Max Heap is :" << endl;
    for (auto item : testContainerTwo) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}