#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <random>

constexpr int g_pass_legth { 4 };
constexpr int g_chain_length { 1000 };

uint32_t hashing(const std::string& str) {
    uint32_t hash = 2166136261U; 
    const uint32_t fnv_prime = 16777619U; 

    for (const char& i : str) {
        hash ^= static_cast<unsigned char>(i);
        hash *= fnv_prime;
    }

    std::cout << hash << "\n";    

    return hash;
}

std::string reduction(uint32_t hash_value) {

}

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cout << "usage: ./app.exe <hash_5_digits>" << std::endl;
        return 1;
    }
    if (std::strlen(argv[1]) > 4) {
        std::cout << "hash should be less than a 5 digit!" << std::endl;
        return 1;
    }

    std::map<std::string, int32_t> rainbow_table{};

    hashing(argv[1]);


    return EXIT_SUCCESS;
}