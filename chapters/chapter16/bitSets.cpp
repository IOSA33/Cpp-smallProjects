#include <iostream>
#include <bitset>
#include <cstdint>
#include <vector>
#include <string_view>

namespace WordList
{
    
    std::vector<std::string_view> words { "mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };
    
    std::uint8_t bits{0b0000'0000}; // 1 byte
    std::string_view word = words[0];

    void setChar(char c){
        for (size_t i {0}; i < word.size(); ++i) {
            if (word[i] == c) {
                bits |= (1u << i);
            }
        }
    }

    void printWord() {
        for (size_t i = 0; i < word.size(); ++i) {
            if (bits & (1u << i)) {
                std::cout << word[i];
                continue;
            }
            std::cout << "_";
        }
    }
}

int main() {

    std::cout << WordList::word << '\n';
    WordList::setChar('y');
    WordList::printWord();

    std::cout << std::endl;
    
    std::cout << sizeof(WordList::bits) << '\n';
    std::cout << static_cast<std::bitset<8>>(WordList::bits) << '\n';

    return 0;
}