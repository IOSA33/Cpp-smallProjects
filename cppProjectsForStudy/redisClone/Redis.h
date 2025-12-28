#pragma once

#include <unordered_map>
#include <string>
#include "Timer.h"

class Redis {
private:
    Timer m_timer{};
    std::unordered_map<std::string, std::unordered_map<double, std::string>> m_umap{};
    double m_expireAfterSeconds{ 10.0 };
    
public:
    // TODO: textfile path constructor
    // TODO: expire AT
    // TODO: LogFile, after two events and after SAVE
    // TODO: ReadFile
    // TODO: AOF, save history of commands
    Redis() = default;
    ~Redis() {
    //    writeToLog();
    }

    void run();
    // Returns response code
    const std::string parser(const std::string& input);
    std::string setValue(const std::string& key, const std::string& value);
    std::string getValue(const std::string& key) const;
};