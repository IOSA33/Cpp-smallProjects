#include <iostream>
#include "Redis.h"

int main() {
    std::cout << "Glad to see you!\n";
    Redis redis{};
    redis.run();
}