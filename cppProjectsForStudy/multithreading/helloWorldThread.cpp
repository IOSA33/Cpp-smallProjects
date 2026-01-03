#include <thread>
#include <chrono>
#include <iostream>

static bool s_Finished = false;

void tryFunc() {
    while(!s_Finished) {
        std::cout << "Working..." << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::thread thread1(tryFunc);
    std::cout << std::fixed << std::setprecision(9) << std::left;

    const auto start = std::chrono::high_resolution_clock::now();
    const auto startsteady = std::chrono::steady_clock::now();

    std::cout << start << '\n';
    //std::cout << startsteady << '\n';


    std::cin.get();
    s_Finished = true;
    thread1.join();
    std::cout << "Finished!!\n";
}