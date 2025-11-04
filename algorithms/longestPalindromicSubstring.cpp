#include <iostream>
#include <unordered_set>
#include <vector>

std::string longestPalindrome(std::string& s) {
    std::string result;

    std::unordered_set<std::string> m_set;

    for (int i = 0; i <= s.length(); ++i) {
        for (int j = 1; j <= s.length() - i; ++j) {
            std::string temp = s.substr(i, j);
            if (temp.length() > 1) {
                m_set.insert(s.substr(i, j));
            }
        }
    }

    for (int i = 0; i <= s.length(); ++i) {
        for (int j = s.length() - 1; j >= 0; --j) {
            std::string temp = s.substr(i, j + 1);

            if (temp.length() > 1) {
                std::string temp1;
                // for (char & it : std::ranges::reverse_view(temp))
                for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
                    temp1 += *it;
                }

                if (m_set.find(temp1) != m_set.end()) {
                    if (temp1.length() > result.length()) {
                        result = temp1;
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    std::string s = "babas";
    std::cout << longestPalindrome(s) << std::endl;
}