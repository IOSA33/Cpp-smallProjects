#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <random>

unsigned long hashing(const std::string& param_string) {
    unsigned long hash { 5381 };

    for (const char& i : param_string) {
        hash = ((hash << 5) + hash) + static_cast<unsigned char>(i);
    }

    return hash;
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

    std::cout << hashing(argv[1]);




    return EXIT_SUCCESS;
}