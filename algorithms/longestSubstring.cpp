#include <iostream>
#include <unordered_set>

class Solution {
public:
    static int lengthOfLongestSubstring(const std::string& s) {
        int result{0};
        int temp{0};

        std::unordered_set<char> hashSet;

        for (int i = 0; i < s.length(); ++i) {
            if (hashSet.find(s[i]) == hashSet.end()) {
                ++temp;
                hashSet.insert(s[i]);
            } else {
                if (temp > result) {
                    result = temp;
                }
                temp = 0;
                hashSet.erase(hashSet.begin(), hashSet.end());
                hashSet.insert(s[i]);
                ++temp;
            }
        }

        return result; 
    }
};


int main() {
    const std::string s = "pwwwkew";

    std::cout <<  Solution::lengthOfLongestSubstring(s) << std::endl;
}
