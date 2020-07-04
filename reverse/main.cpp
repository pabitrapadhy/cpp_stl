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

    cout << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Reversed: ";
    std::reverse(nativeTypeCollection.begin(), nativeTypeCollection.end());
    PrintCollection(nativeTypeCollection);

    cout << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Reversed (except first 2 elements): ";
    std::reverse(userDefinedTypeCollection.begin() + 2, userDefinedTypeCollection.end());
    PrintCollection(userDefinedTypeCollection);

    return 0;
}