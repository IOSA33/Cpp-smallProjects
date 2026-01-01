#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Logger.h"
#include "Timer.h"
#include "Redis.h"

void Logger::saveToFile(const std::vector<std::string>& vecLine, Timer& timer) {
    std::ofstream path{ m_filePath, std::ios::app};

    if(!path.is_open()) {
        std::cout << "Error in Logger::saveToFile(): Cannot open a file!\n";
        return;
    }
    for (size_t i = 0; i < vecLine.size(); ++i) {
        if (i == 3) {
            std::string expireTime = vecLine[i];
            path << timer.now() + std::stod(expireTime) << ' ';
        } else {
            path << vecLine[i] << ' ';
        }
    }

    if (vecLine.size() < 4 && vecLine[0] == "SET") {
        path << timer.now() + DefaultValues::expireAfter << ' ';
    }

    path << '\n';

    path.close();
}

void Logger::analyzeFile() {
    std::ifstream file { m_filePath };

    if (!file.is_open()) {
        std::cout << "Error in Logger::analyzeFile(): Cannot open a file!\n";
        return;
    }

    std::string inputLine{};
    

    while(std::getline(file, inputLine)) {
        
    }
}