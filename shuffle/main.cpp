#include <iostream>
#include <vector>
#include <random>
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

    std::random_device rd;
    std::mt19937 engine {rd()};

    cout << "Collection: ";
    PrintCollection(nativeTypeCollection);
    cout << "Shuffled: ";
    std::shuffle(nativeTypeCollection.begin(), nativeTypeCollection.end(), engine);
    PrintCollection(nativeTypeCollection);

    cout << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "Shuffled (except the first 2 elements): ";
    std::shuffle(userDefinedTypeCollection.begin() + 2, userDefinedTypeCollection.end(), engine);
    PrintCollection(userDefinedTypeCollection);

    return 0;
}