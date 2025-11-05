#include <iostream>
#include <string>
#include <unordered_set>

bool checkInclusion(std::string& s1, std::string& s2) {

    std::unordered_set<char> set;

    for (int i = 0; i < s2.length(); ++i) {
        if (s1[0] == s2[i]) {
            std::string subForward = s2.substr(i, s1.length());

            if (subForward == s1) {
                return true;
            }

            if (i - s1.length() >= 0) {
                std::string temp;
                std::string subBackward = s2.substr(i - s1.length() + 1, s1.length());
                for (auto it = subBackward.rbegin(); it != subBackward.rend(); ++it) {
                    temp.push_back(*it);
                    if (s1 == temp) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main () {
    std::string s1 = "adc";
    std::string s2 = "dcda";

    std::cout << checkInclusion(s1, s2) << std::endl;
}