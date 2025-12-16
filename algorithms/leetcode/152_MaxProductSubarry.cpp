#include <iostream>
#include <vector>

int MaxProductSubarry(const std::vector<int>& vec) {
    int res = *std::max_element(vec.begin(), vec.end());
    int cur_max = 1, cur_min = 1;

    for (const auto& x : vec) {
        int temp = cur_max;
        cur_max = std::max(std::max(temp * x, cur_min * x), x);
        cur_min = std::min(std::min(temp * x, cur_min * x), x);

        res = std::max(res, cur_max);
    }

    return res;
}


int main() {
    std::vector vec = {-2, -3, -4};

    std::cout << MaxProductSubarry(vec);

    return 0;
}