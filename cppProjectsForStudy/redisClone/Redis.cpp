#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "Redis.h"

// Commands:
// SET [key] [value] : returns "OK"
// GET [key] : returns "value"

void Redis::run() {
    while(true) {
        std::cout << "Write a command SET [key] [value] or GET [key]\n";
        std::string input{};
        std::getline(std::cin >> std::ws, input);

        const std::string response { parser(input) };

        std::cout << response << '\n';
        if (response == "exit") {
            return;
        }
    }
}

const std::string Redis::parser(const std::string& s) {
    std::vector<std::string> vec{};
    std::string word{};

    for (const auto& i: s) {
        if (i != ' ') {
            word.push_back(i);
            continue;
        }
        vec.emplace_back(word);
        word.clear();
    }

    if (!word.empty()) {
        vec.emplace_back(word);
    }

    if (vec[0] == "exit") {
        return "exit";
    }

    if (vec[0] == "SET") {
        if (vec.size() > 2) {
           return setValue(vec[1], vec[2]);
        } else {
            return "SET has less than 3 arguments";
        }
    } else if (vec[0] == "GET") {
        if (vec.size() >= 2) {
            auto result { getValue(vec[1]) };
            if (result.second == Err::NoError) {
                return result.first;
            } else {
                if (result.second == Err::NoSuchKey) {
                    return result.first;
                } else {
                    deleteValue(vec[1]);
                    return result.first;
                }
            }
        } else {
            return "GET has less than 2 args";
        }
    }

    return "Error in Redis::parser(): unknown Command";
}

std::string Redis::setValue(const std::string& key, const std::string& value) {
    auto it { m_umap.insert({key, {{m_timer.now() + m_expireAfterSeconds, value}}}) };
    if (it.second == true) {
        return "OK";
    } else {
        return "Error in Redis::setValue(): Key already exists";
    }
}

std::pair<std::string, Err::Type> Redis::getValue(const std::string& key) const {
    auto it { m_umap.find(key) };
    if (it != m_umap.end()) {
        for (const auto& [double_key, string_value]: it->second) {
            if (double_key > m_timer.now()) {
                return std::make_pair(string_value, Err::NoError);
            } else {
                return std::make_pair("Key is expired!", Err::Expired);
            }
        }
    }
    return std::make_pair("Error in Redis::getValue(): no such Key", Err::NoSuchKey);
}

void Redis::deleteValue(const std::string& key) {
    auto result { m_umap.erase(key) };
    if (result) {
        std::cout << "Key: \"" << key << "\" is deleted!\n";
    } else {
        std::cout << "Error in Redis::deleteValue(): Cannot delete a key!\n";
    }
}