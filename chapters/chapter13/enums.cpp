#include <iostream>

namespace ColorNameSpace {
    enum Color {
        red,
        yellow,
        blue,
    };
}

namespace FeelingNameSpace {
    enum Feeling {
        happy,
        tired,
        blue, // No longer same name problem, with namaspace
    };
}

enum SortOrder {
    alphabetical,
    alphabeticalReverse,
    numerical,
};

void sortData(int data[3], const SortOrder order) {
    switch (order) {
        case alphabetical:
            for (int i = 0; i < 4; i++) {
                std::cout << data[i] << '\n';
            }
            break;
        case alphabeticalReverse:
            break;
        case numerical:
            break;
    }
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    sortData(arr, alphabetical);

    ColorNameSpace::Color paint{ ColorNameSpace::blue };
    FeelingNameSpace::Feeling me { FeelingNameSpace::blue };

    return EXIT_SUCCESS;
}