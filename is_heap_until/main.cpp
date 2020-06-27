#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;
using namespace utils;

template <class Iterator, typename CollectionType>
void IsHeap(Iterator last, std::vector<CollectionType> const& collection) {
    if (last == end(collection)) {
        cout << "This collection is a heap" << endl << endl;
    } else {
        cout << "Failed at item = " << *last << endl << endl;
    };
}

int main() {
    cout << "--------------------------------------------------" << endl;
    cout << "Collection One: (Collection is not a heap) : ";
    std::vector<int> collectionOne {1, 2, 3, 4, 5};
    PrintCollection(collectionOne);
    auto lastOne = std::is_heap_until(begin(collectionOne), end(collectionOne));
    IsHeap(lastOne, collectionOne);

    cout << "--------------------------------------------------" << endl;
    cout << "Collection Two: (Collection is a heap) : ";
    std::vector<int> collectionTwo {9, 8, 7, 6, 4};
    PrintCollection(collectionTwo);
    auto lastTwo = std::is_heap_until(begin(collectionTwo), end(collectionTwo));
    IsHeap(lastTwo, collectionTwo);

    cout << "--------------------------------------------------" << endl;
    cout << "Collection Three: (Collection with only 1 element) : ";
    std::vector<int> collectionThree {1};
    PrintCollection(collectionThree);
    auto lastThree = std::is_heap_until(begin(collectionThree), end(collectionThree));
    IsHeap(lastThree, collectionThree);

    cout << "--------------------------------------------------" << endl;
    cout << "Collection Four: (Collection with no elements) : ";
    std::vector<int> collectionFour {};
    PrintCollection(collectionFour);
    auto lastFour = std::is_heap_until(begin(collectionFour), end(collectionFour));
    IsHeap(lastFour, collectionFour);

    return 0;
}