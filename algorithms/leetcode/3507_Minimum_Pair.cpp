#include <vector>
#include <iostream>

int minimumPairRemoval(std::vector<int>& nums) {
    int result{};
    
    if (nums.size() < 3) {
        return result;
    }

    int min_sum{ nums[1] + nums[0] };
    bool inc{ false };

    while (true) {
        if (inc) {
            break;
        }
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                int l_sum = nums[i] + nums[i-1];
                if (l_sum < min_sum) {
                    min_sum = l_sum; 
                }
            } else {
                inc = true;
            }
        }
    }


    return result;
}

int main() {
    std::vector<int> vec{5, 2, 3, 1};
    std::cout << minimumPairRemoval(vec);
}