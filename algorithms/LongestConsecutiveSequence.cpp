#include <set>
#include <vector>
#include <iostream>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::set<int> s1;

        for (int i = 0; i<nums.size(); i++) {
            s1.insert(nums[i]);
        }

        int result{0};

        for (auto x : s1) {
            if (s1.find(x-1) == s1.end()){
                int counting{1};
                int temp{0};
                ++temp;
                while (s1.count(x+counting)){
                    ++temp;
                    ++counting;
                }
                if (result < temp) {
                    result = temp;
                }
                temp = 0;
            }
        }

        return result;
    }
};

int main() {
    std::vector<int> cars = {100,4,200,1,3,2};
    Solution newClass;

    int result = newClass.longestConsecutive(cars);

    std::cout << result << std::endl;
}