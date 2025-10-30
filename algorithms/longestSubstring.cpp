#include <iostream>
#include <unordered_set>

class Solution {
public:
    static int lengthOfLongestSubstring(const std::string& s) {
        if (s.empty()) {
            return 0;
        }

        if (s == " ") {
            return 1;
        }

        int result{0};
        int temp{0};

        std::unordered_set<char> hashSet;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                if (hashSet.find(s[j]) == hashSet.end()) {
                    ++temp;
                    hashSet.insert(s[j]);
                } else {
                    temp = 0;
                    hashSet.erase(hashSet.begin(), hashSet.end());
                    break;
                }
                if (temp > result) {
                    result = temp;
                }
            }
        }

        return result; 
    }
};


int main() {
    const std::string s = "dvdf";

    std::cout <<  Solution::lengthOfLongestSubstring(s) << std::endl;
}
