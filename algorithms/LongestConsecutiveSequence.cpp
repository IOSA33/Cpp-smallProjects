#include <set>
#include <vector>
#include <iostream>

class Solution {
public:
    static int longestConsecutive(const std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::set<int> s1;

        for (int x : nums) {
            s1.insert(x);
        }

        int result{0};

        for (const int x : s1) {
            if (s1.find(x-1) == s1.end()){
                int counting{1};
                int temp{1};
                while (s1.count(x+counting)){
                    ++temp;
                    ++counting;
                }
                if (result < temp) {
                    result = temp;
                }
            }
        }

        return result;
    }
};

int main() {
    const std::vector cars = {100,4,200,1,3,2,202,101,102};

    const int result = Solution::longestConsecutive(cars);

    std::cout << result << std::endl;
}