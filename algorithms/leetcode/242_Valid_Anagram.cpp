#include <iostream>
#include <unordered_map>
#include <string>

bool checkAnagram(const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    
    std::unordered_map<char, int> umap{};

    for (const auto& i: s1) {
        if (umap.contains(i)) {
            umap[i] += 1;
        } else {
            umap.insert( {{i,1}} );
        }
    }

    for (const auto& i: s2) {
        if (!umap.contains(i)){
            return false;
        }
        if (umap[i]  == 0) {
            return false;
        } else {
            umap[i] -= 1;
        }
    }

    return true;
}

int main () {
    std::string str1 { "anagram" };
    std::string str2 { "nagaram" };

    std::cout << checkAnagram(str1, str2) << std::endl;
}