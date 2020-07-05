#include <iostream>
#include <vector>
#include "StrongDataTypes.h"
#include "Utils.h"

using namespace std;
using namespace utils;

int main() {
    // simple integer container
    std::vector<int> nativeTypeCollection {1, 4, 5};
    std::vector<float> floatTypeCollection {1.3f, 1.5f, 1.8f};
    std::string name {"Ben"};

    // custom class type container
    std::vector<Integer> userDefinedTypeCollection {
            Integer{4},
            Integer{5},
            Integer{6}
    };

    cout << "NOTE:\n"
            "Collection goes lexicographically increasing, \n"
            "therefore first we sorted, then the next_permutation gives all possible outputs until \n"
            "it's all sorted in descending order" << endl;

    cout << endl << "Collection: ";
    PrintCollection(nativeTypeCollection);
    std::sort(nativeTypeCollection.begin(), nativeTypeCollection.end());
    cout << "All permutations of the collection are: " << endl;
    do {
        PrintCollection(nativeTypeCollection);
    } while (std::next_permutation(nativeTypeCollection.begin(), nativeTypeCollection.end()));

    cout << endl << "Collection: ";
    PrintCollection(floatTypeCollection);
    std::sort(floatTypeCollection.begin(), floatTypeCollection.end());
    cout << "All permutations of the collection are: " << endl;
    do {
        PrintCollection(floatTypeCollection);
    } while (std::next_permutation(floatTypeCollection.begin(), floatTypeCollection.end()));

    cout << endl << "Collection: ";
    cout << name << endl;
    std::sort(name.begin(), name.end());
    cout << "All permutations of the collection are: " << endl;
    do {
        cout << name << endl;
    } while (std::next_permutation(name.begin(), name.end()));

    cout << endl << "Collection: ";
    PrintCollection(userDefinedTypeCollection);
    cout << "NOTE: \n"
            "Collection is already sorted in decreasing order\n"
            "Therefore it has no next_permutation" << endl << endl;

    std::sort(userDefinedTypeCollection.begin(), userDefinedTypeCollection.end(), std::greater<>());
    cout << "All permutations of the collection are: " << endl;
    do {
        PrintCollection(userDefinedTypeCollection);
    } while (std::next_permutation(userDefinedTypeCollection.begin(), userDefinedTypeCollection.end()));

    return 0;
}