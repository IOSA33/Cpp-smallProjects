#include <iostream>

int main() {
    std::cout << "Enter digit over 0\n"; 
    int digit{};
    std::cin >> digit;

    try
    {
        if (digit < 0.0) 
            throw "It's not over 0";

        std::cout << "You entered a " << digit;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    

    return 0;
}