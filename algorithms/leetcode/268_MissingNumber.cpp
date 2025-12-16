#include <iostream>
#include <vector>
#include <algorithm>

int missingNumber(std::vector<int>& nums) {
    int res{};
    bool returnLastPlusOne{ false };
    std::sort(nums.begin(), nums.end());
    if (nums[0] != 0) return 0;
    int temp{};
    for (size_t i{0}; i < nums.size(); ++i) {
        if (nums[i] != temp) {
            returnLastPlusOne = true;
            res = i;
            break;
        }
        ++temp;
    }

    if (returnLastPlusOne) {
        return temp;
    }

    return res;
}

int main() {
    std::vector vec{0,2,3};
    std::cout << missingNumber(vec);
    return 0; 
}