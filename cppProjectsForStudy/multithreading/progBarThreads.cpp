#include <iostream>
#include <thread>
#include <chrono>

void progressBar(std::string& bar);
std::string bar = {"-----"};

void f1(int& n) {
    std::thread t2(progressBar, std::ref(bar));
    t2.detach();
    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 <<" s" << std::endl;
        ++n;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void progressBar(std::string& bar) {
    for (int i = 0; i < 5; ++i) {
        bar[i] = '#';
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << bar << '\n';
    }
}

int main() {
    int n { 0 };
    std::thread t1(f1, std::ref(n));

    t1.join();
    std::cout << "Final value of n is " << n << '\n';
    return EXIT_SUCCESS;
}