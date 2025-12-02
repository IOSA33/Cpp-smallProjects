#include <iostream>
#include <string>


void couple(std::string& word) {
    auto length{static_cast<std::ptrdiff_t>(word.size())};
    for (size_t i {0}; i < word.size(); ++i) {
        for (auto j { length - 2 }; j >= 0; --j) {
            if (word.data()[j] > word.data()[j + 1]){
                auto temp = word.data()[j];
                word.data()[j] = word.data()[j + 1];
                word.data()[j + 1] = temp;
            }
        }
    }
}

int main() {

    std::string word { "REKURSIO" };
    couple(word);
    std::cout << word;

    return 0;
}