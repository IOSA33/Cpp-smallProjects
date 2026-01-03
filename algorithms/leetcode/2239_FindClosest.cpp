#include <iostream>
#include <vector>

int findClosest(const std::vector<int>& vec) {
    int number{vec[0]};
    int currShortestLength{vec[0]};
    if (vec[0] < 0) {
        currShortestLength = vec[0] * (-1);
    }

    for (size_t i {0}; i < vec.size(); ++i) {
        int length{};

        if (vec[i] < 0) {
            length = vec[i] * (-1);
            if (length < currShortestLength) {
                currShortestLength = length;
                number = vec[i];
            }
        } else {
            length = vec[i];
            if (length <= currShortestLength) {
                currShortestLength = length;
                if (vec[i] > number || vec[i] == 0) {
                    number = vec[i];
                }
                if (vec[i] < number && vec[i] > 0) {
                    number = vec[i];
                }
            }
        }
    }

    return number;
}

int main() {
    std::vector<int> vec {-1, -1};
    std::cout << findClosest(vec) << std::endl;
}