#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

void solveFirst() {
    std::ifstream file("input5.txt");
    if(!file.is_open()) {
        std::cout << "Could not open a file!\n";
        std::exit(1);
    }

    // First part
    int fresh{};
    std::vector<long long> ranges{};

    std::string line{};
    while (std::getline(file, line)) {
        if (!line.empty()) {
            if (line.find('-') != std::string::npos) {
                std::stringstream ss(line);
                std::string t{};
                char del = '-';

                while (std::getline(ss, t, del)) {
                    ranges.push_back(std::stoll(t));
                }

            } else {
                long long int temp = std::stoll(line);
                for (size_t i{ 0 }; i < ranges.size(); i += 2) {
                    if (temp >= ranges[i] && temp <= ranges[i + 1]) {
                        ++fresh;
                        break;
                    }
                }
            }
        }
    }

    // second part
    std::vector<std::pair<long long, long long>> ranges2{};
    for (size_t i = 0; i < ranges.size(); i += 2) {
        ranges2.push_back({ranges[i], ranges[i + 1]});
    }
    std::ranges::sort(ranges2);

    std::vector<std::pair<long long, long long>> merged;
    for (const auto& range : ranges2) {
        if (merged.empty() || range.first > merged.back().second + 1) {
            merged.push_back(range);
        } else {
            merged.back().second = std::max(merged.back().second, range.second);
        }
    }

    long long total = 0;
    for (const auto& m : merged) {
        total += (m.second - m.first + 1);
    }

    file.close();
    std::cout << fresh << std::endl;
    std::cout << total << std::endl;
}



int main() {
    solveFirst();
    return 0;
}