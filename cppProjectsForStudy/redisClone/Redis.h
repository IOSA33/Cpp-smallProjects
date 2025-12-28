#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include "Timer.h"

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
    std::unordered_map<std::string, std::unordered_map<double, std::string>> m_umap{};
    double m_expireAfterSeconds{ 5.0 };

public:
    // TODO: textfile path constructor
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
    std::pair<std::string, Err::Type> getValue(const std::string& key) const;
    void deleteValue(const std::string& key);
};