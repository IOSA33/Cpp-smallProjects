#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

char* tokenizeByChar(const std::string& str, char someChar) {   
    // +1 is standing for reserving memory '\n' in C
    char* newStr = (char *)malloc(str.size() + 1);

    for (size_t i = 0; i < str.size(); ++i) {
        if (!(str[i] == someChar)) {
            newStr[i] = str[i];
        } else {
            std::cout << "We found the char! " << str[i] <<'\n';
            newStr[i] = ' ';
        }
    }

    return newStr;
}

int main() {
    std::string str{"Hello, World!"};
    char* returned_str = tokenizeByChar(str, '!');

    for (size_t i = 0; i < str.size(); ++i) {
        std::cout << returned_str[i];
    }

    free(returned_str);
    return 0;
}