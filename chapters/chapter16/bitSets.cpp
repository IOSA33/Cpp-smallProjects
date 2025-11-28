#include <iostream>
#include <bitset>
#include <vector>
#include <string_view>

namespace WordList
{
    
    std::vector<std::string_view> words { "mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };
    
    std::bitset<8> me{};
    std::string_view word = words[0];

    void setChar(char c){
        for (size_t i {0}; i < word.size(); ++i) {
            if (word[i] == c) {
                me[i] = true;
            } else {
                me[i] = false;
            }
        }
    }

    void printWord() {
        for (size_t i = 0; i < word.size(); ++i) {
            if (me[i] == true) {
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
    
    std::cout << WordList::me << '\n';

    return 0;
}