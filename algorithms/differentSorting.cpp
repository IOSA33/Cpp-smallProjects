#include <iostream>
#include <string>


void bubble(std::string& word) {
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

void inseriton(std::string& word) {
    for (size_t i {0}; i < word.size(); ++i) {
        const char temp = word[i];
        int j = static_cast<int>(i) - 1;
        
        while (j >= 0 && word[j] > temp) {
            word[j + 1] = word[j];
            j -= 1;
        }

        word[j + 1] = temp;
    }
}

int main() {

    std::string word { "REKURSIO" };
    inseriton(word);
    std::cout << word;

    return 0;
}