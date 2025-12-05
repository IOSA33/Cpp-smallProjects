#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

void solveFirst() {
    std::ifstream file("input5.txt");
    if(!file.is_open()) {
        std::cout << "Could not open a file!\n";
        std::exit(1);
    }

    int result{};
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
                        ++result;
                        break;
                    }
                }
            }
        }
    }

    file.close();
    std::cout << result;
}



int main() {
    solveFirst();
    return 0;
}