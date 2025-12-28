#include <iostream>
#include <string>
#include "Redis.h"

void Redis::run() {
    while(true) {
        int input {};
        std::cin >> input;

        if (input == 1) {
            std::cout << 1;
            return;
        }
    }
}