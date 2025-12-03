#include <iostream>
#include <string>
#include <ranges>



void bubble(std::string& word) {
    auto length{std::ranges::ssize(word)};
    for (int i { 0 }; i < length; ++i) {
        for (auto j { length - 2 }; j >= i - 1; --j) {
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


void selection(std::string& word) {
    for (size_t i = 0; i < word.size(); ++i) {
        char temp = word[i];
        size_t k = i;
        for(size_t j = i + 1; j < word.size(); ++j) {
            if (word[j] < temp) {
                temp = word[j];
                k = j;
            }
        }
        if (k != i) {
            word[k] = word[i];
            word[i] = temp;
        }
    }
}


int main() {

    std::string word { "REKURSIO" };
    selection(word);
    std::cout << word << "\n";
    std::cout << word;

    return 0;
}