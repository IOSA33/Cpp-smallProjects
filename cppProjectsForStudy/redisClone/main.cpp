#include <iostream>
#include "NetWork/Server.h"

int main(int argc, int arcv[]) {
    std::cout << "Glad to see you!\n";    
    TCPServer server{ 8080 };
    server.run();
}