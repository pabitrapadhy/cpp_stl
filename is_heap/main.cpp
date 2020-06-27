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

    // NOTE: checking std::is_heap on full range of collection.
    cout << "Full collection check for max heap" << endl;
    cout << "---------------------------------" << endl;
    cout << "Collection One: ";
    PrintCollection(nativeTypeCollection);
    cout << "Is a Max Heap ? : ";
    cout << std::boolalpha << std::is_heap(begin(nativeTypeCollection), end(nativeTypeCollection)) << endl;
    cout << "MaxHeapify collection..." << endl;
    MaxHeapify(nativeTypeCollection);
    cout << "Heap One : ";
    PrintCollection(nativeTypeCollection);
    cout << "Is a Max Heap ? : ";
    cout << std::boolalpha << std::is_heap(begin(nativeTypeCollection), end(nativeTypeCollection)) << endl << endl;

    // NOTE: checking std::is_heap on ranged collection
    cout << "Collection Two: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Is a Max Heap ? : ";
    cout << std::boolalpha << std::is_heap(begin(userDefinedTypeCollection), end(userDefinedTypeCollection)) << endl;
    cout << "MaxHeapify collection..." << endl;
    MaxHeapify(userDefinedTypeCollection);
    cout << "Heap Two : ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Is a Max Heap ? : ";
    cout << std::boolalpha << std::is_heap(begin(userDefinedTypeCollection), end(userDefinedTypeCollection)) << endl;
    cout << "---------------------------------" << endl << endl;

    cout << "Ranged check for max heap in a collection" << endl;
    cout << "---------------------------------" << endl;
    cout << "Collection One: ";
    std::vector<int> collectionOne {1, 2, 5, 3, 6, 4};
    PrintCollection(collectionOne);
    auto diffOne = collectionOne.size()/2;
    cout << "Is a Max Heap for Range - (" << 0 << " to " << collectionOne.size() - diffOne << ") : ";
    cout << std::boolalpha << std::is_heap(begin(collectionOne), end(collectionOne) - diffOne) << endl << endl;

    cout << "Collection Two: ";
    std::vector<Integer> collectionTwo {
        Integer {9},
        Integer {8},
        Integer {6},
        Integer {7},
        Integer {4},
        Integer {10},
    };
    PrintCollection(collectionTwo);
    auto diffTwo = collectionTwo.size()/2;
    cout << "Is a Max Heap for Range - (" << 0 << " to " << collectionTwo.size() - diffTwo << ") : ";
    cout << std::boolalpha << std::is_heap(begin(collectionTwo), end(collectionTwo) - diffTwo) << endl;
    cout << "---------------------------------" << endl << endl;

    cout << "Collection with no elements" << endl;
    cout << "---------------------------------" << endl;
    cout << "Collection Three: ";
    std::vector<int> collectionThree {};
    PrintCollection(collectionThree);
    cout << std::boolalpha << std::is_heap(begin(collectionThree), end(collectionThree)) << endl;

    return 0;
}