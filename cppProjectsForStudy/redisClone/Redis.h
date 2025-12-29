#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include "Timer.h"
#include "Logger.h"

namespace Err{
    enum Type{
        NoError,
        NoSuchKey,
        Expired,
        Max_Err_Type
    };
};

class Redis {
private:
    Timer m_timer{};
    Logger m_logger;
    std::unordered_map<std::string, std::unordered_map<double, std::string>> m_umap{};

public:
    // TODO: textfile path constructor
    // TODO: LogFile, after SAVE
    // TODO: ReadFile
    // TODO: AOF, save history of commands
    Redis(const std::string& pathToFile) : m_logger(pathToFile) {} 
    ~Redis() {
    //    writeToLog();
    }

    void run();
    // Returns response code
    const std::string parser(const std::string& input);
    std::string setValue(const std::string& key, const std::string& value, double exprireAfter = 10.0);
    std::pair<std::string, Err::Type> getValue(const std::string& key) const;
    bool deleteValue(const std::string& key);
    bool isStringDigit(const std::string& input);
};