#include <iostream>
#include <vector>
#include <string>
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

    if (vec[0] == "SET") {
        if (vec.size() > 2) {
           return setValue(vec[1], vec[2]);
        } else {
            return "SET has less than 3 arguments";
        }
    } else if (vec[0] == "GET") {
        if (vec.size() >= 2) {
            return getValue(vec[1]);
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

std::string Redis::getValue(const std::string& key) const {
    auto it { m_umap.find(key) };
    if (it != m_umap.end()) {
        for (const auto& [double_key, string_value]: it->second) {
            if (double_key > m_timer.now()) {
                return string_value;
            } else {
                return "Key is expired!";
            }
        }
    }
    return "Error in Redis::getValue(): no such Key";
}