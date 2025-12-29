#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Logger.h"

void Logger::saveToFile(const std::vector<std::string>& vecLine) {
    std::ofstream path{ m_filePath, std::ios::app};

    if(!path.is_open()) {
        std::cout << "Cannot open a file!\n";
        return;
    }
    for (const auto& i: vecLine) {
        path << i << ' ';
    }

    path << '\n';

    path.close();
}