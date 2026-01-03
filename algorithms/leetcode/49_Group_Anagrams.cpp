#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <unordered_map>

std::vector<std::vector<std::string>> solution(const std::vector<std::string>& vec) {
    std::vector<std::size_t> usedIdx{};
    std::vector<int> v(26, 0);
    std::vector<std::vector<std::string>> vReturn;

    size_t index = 0;
    for (std::size_t i = 0; i < vec.size(); ++i) {
        if (std::find(usedIdx.begin(), usedIdx.end(), i) != usedIdx.end()) continue;
        
        std::vector<std::string> group;
        group.push_back(vec[i]);
        usedIdx.push_back(i);

        for (char ch: vec[i]) v[ch-'a']++;

        for (std::size_t j = 0; j < vec.size(); ++j) {
            if (std::find(usedIdx.begin(), usedIdx.end(), j) != usedIdx.end()) continue;
            for (char ch: vec[j]) v[ch-'a']--;
            bool check{ true };
            for (int i=0; i<26; i++) if(v[i]!=0) {
                check = false;
                break;
            }
            if (check) {
                group.push_back(vec[j]);
                usedIdx.push_back(j);
            }
            std::ranges::fill(v, 0);
            for (char ch: vec[i]) v[ch-'a']++;
        }
        
        vReturn.push_back(group);
        std::ranges::fill(v, 0);
    }

    return vReturn;
}

std::vector<std::vector<std::string>> solutionYeah(const std::vector<std::string>& vec) {
    std::unordered_map<std::string, std::vector<std::string>> um;

    for (auto& i: vec) {
        std::string copy = i;
        std::sort(copy.begin(), copy.end());
        um[copy].push_back(std::move(i));
    }

    std::vector<std::vector<std::string>> vReturn{};
    vReturn.reserve(um.size());
    for (const auto& i: um) {
        vReturn.push_back(std::move(i.second));
    }

    return vReturn;
}


int main() {
    // [["bat"],["nat","tan"],["ate","eat","tea"]]
    std::vector<std::string> s1 {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> solution1{solutionYeah(s1)};
    for (size_t i = 0; i < solution1.size(); ++i) {
        for (size_t j = 0; j < solution1[i].size(); ++j) {
            std::cout << solution1[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // [[""]]
    std::vector<std::string> s2 {""};
    std::vector<std::vector<std::string>> solution2{solutionYeah(s2)};
    for (size_t i = 0; i < solution2.size(); ++i) {
        for (size_t j = 0; j < solution2[i].size(); ++j) {
            std::cout << solution2[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // [["a"]]
    std::vector<std::string> s3 {"a"};
    std::vector<std::vector<std::string>> solution3{solutionYeah(s3)};
    for (size_t i = 0; i < solution3.size(); ++i) {
        for (size_t j = 0; j < solution3[i].size(); ++j) {
            std::cout << solution3[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}