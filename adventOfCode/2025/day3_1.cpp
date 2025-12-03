#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int getValue1(const std::vector<int>& arr) {
    int best = 0;

    for (size_t i = 0; i + 1 < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            int val = arr[i] * 10 + arr[j];
            if (val > best) {
                best = val;
            }
        }
    }
    std::cout << "WE GOT: " << best;
    return best;
}

int getValue(const std::vector<int>& arr) {
    auto max { static_cast<std::ptrdiff_t>(arr[0]) };
    size_t secondMax {};
    std::string str{};
    size_t index{};
    bool first{ true };

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }

    if (index + 1 == arr.size()) {
        first = false;
        index = 0;
    }

    if (first) ++index;

    for (size_t i = index; i < arr.size(); ++i) {
        if (arr[i] > secondMax && arr[i] <= max) {
            if (i+1 == arr.size() && !first) {
                std::cout << "Called ";
                break;
            }
            secondMax = arr[i];
        }
    }

    if (first) {
        str.push_back('0' + max);
        str.push_back('0' + secondMax);
    } else {
        str.push_back('0' + secondMax);
        str.push_back('0' + max);
    }

    std::cout << "WE GOT: " << str;
    return std::stoi(str);
}

int result() {
    std::fstream MyFile("input3.txt");
    int sum{};
    int sum1{};
    std::vector<int> vec{};
    char c;
    int line{0};

    while (MyFile.get(c)) {
        if (c >= '0' && c <= '9') {
            vec.push_back(c - '0');
        }

        if (c == '\n' || MyFile.peek() == EOF) {
            std::cout << "New Line: " << ++line << " ";
            sum += getValue(vec);
            sum1 += getValue1(vec);

            if (sum1 != sum) {
                std::cout << std::endl;
                std::cout << "Line:" << line;
                std::cout << std::endl;
                break;
            }

            std::cout << std::endl;
            vec.clear();
        }
    }

    MyFile.close();
    return sum;
}

int main() {
    int sum = result();
    std::cout << "Result: " << sum;

    return 0;
}