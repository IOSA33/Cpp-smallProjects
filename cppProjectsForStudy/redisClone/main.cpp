#include <iostream>
#include "NetWork/Server.h"

// g++ main.cpp Redis.cpp Logger.cpp NetWork/Server.cpp -lws2_32 -o app
int main() {
    // TODO: Analyze file
    // TODO: Channels?
    // TODO: Multiple clients connections
    std::cout << "Glad to see you!\n";    
    
    Redis redis{"Test.txt"};
    redis.run();
    
    //TCPServer server{ 8080 };
    //server.run();
}