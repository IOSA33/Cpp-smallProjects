#include <iostream>
#include "Redis.h"

int main() {
    std::cout << "Welcome to the Redis analogy!\n";
    Redis redis{};
    redis.run();
}