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
    cout << "Partitioned Collection: ";
    std::partition(nativeTypeCollection.begin(), nativeTypeCollection.end(), [] (int i) {
        return i % 2 == 0;
    });
    PrintCollection(nativeTypeCollection);

    cout << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Partitioned Collection: ";
    std::partition(userDefinedTypeCollection.begin(), userDefinedTypeCollection.end(), [] (Integer i) {
        return i.get() % 2 == 0;
    });
    PrintCollection(userDefinedTypeCollection);

    return 0;
}