#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "Redis.h"
#include "Logger.h"

// Commands:
// SET [key] [value] *[expire] : returns "OK"
// GET [key] : returns "value"
// DELETE [key] : returns "Deleted Successfully!"
// SAVE : saves explicitly logs to the file
// exit : exists the program

void Redis::run() {
    while(true) {
        std::cout << "\nWrite a command: \n";
        std::cout << "1: SET [key] [value] *[expire]\n";
        std::cout << "2: GET [key]\n";
        std::cout << "3: DELETE [key]\n";

        std::string input{};
        std::getline(std::cin >> std::ws, input);

        const std::string response { parser(input) };
        if (response == "exit") {
            std::cout << "See you and Happy life :)" << std::endl;
            return;
        }
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
        if (!word.empty()) {
            vec.emplace_back(word);
            word.clear();
        }
    }

    if (!word.empty()) {
        vec.emplace_back(word);
    }

    if (vec[0] == "exit") {
        return "exit";
    }

    if (vec[0] == "SET") {
        if (vec.size() > 2) {
            if (vec.size() == 4) {
                if (isStringDigit(vec[3])) {
                    m_logger.saveToFile(vec);
                    return setValue(vec[1], vec[2], std::stod(vec[3]));
                } else {
                    return "ExpireTime is not a digit!";
                }
                
            } else {
                m_logger.saveToFile(vec);
                return setValue(vec[1], vec[2]);
            }
        } else {
            return "SET has less than a 3 arguments";
        }
    } 
    if (vec[0] == "GET") {
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
            return "GET has less than a 2 arguments";
        }
    }
    if (vec[0] == "DELETE") {
        if (vec.size() >= 2) {
            if (deleteValue(vec[1])) {
                return "Deleted Successfully!";
            } else {
                return "Error in Redis::parser()/deleteValue(): Cannot delete a key!";
            }
        }
        return "DELETE has less than a 2 arguments";
    }

    return "Error in Redis::parser(): unknown Command";
}

bool Redis::deleteValue(const std::string& key) {
    auto result { m_umap.erase(key) };
    if (result) {
        return true;
    } else {
        return false;
    }
}

std::string Redis::setValue(const std::string& key, const std::string& value, double exprireAfter) {
    auto it { m_umap.insert({key, {{m_timer.now() + exprireAfter, value}}}) };
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

bool Redis::isStringDigit(const std::string& input) {
    for (const auto& c: input) {
        if (!std::isdigit(c)){
            return false;
        }
    }
    return true;
}


// Pretty cool :)