#include <iostream>
#include <thread>
#include <chrono>

void f1(int& n) {
    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 <<" s" << std::endl;
        ++n;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void progressBar(int &n, std::string& bar) {
    for (int i = 0; i < 5; ++i) {
        bar[i] = '#';
        std::cout << bar;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    int n { 0 };
    std::string bar = {"-----"};
    std::thread t1(f1, std::ref(n));
    std::thread t2(progressBar, std::ref(n), std::ref(bar));

    t1.join();
    t2.join();
    std::cout << "Final value of n is " << n << '\n';
    return EXIT_SUCCESS;
}