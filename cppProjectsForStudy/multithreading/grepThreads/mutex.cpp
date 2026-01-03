#include <thread>
#include <iostream>
#include <vector>
#include <atomic>
#include <chrono>

void print(int x) {
    std::cout << "Hello " << x << ": ID: " << std::this_thread::get_id() << '\n';
}

static long long s_sum{};
std::mutex g_lock{};

void calculateSum(const std::vector<long long>& vec, size_t start, size_t end) {
    long long local {};
    for (size_t i = start; i < end; ++i) {
        local += vec[i];
    }

    g_lock.lock();
        s_sum += local;
    g_lock.unlock();
}

int main() {
    auto* vec = new std::vector<long long>(1000000);
    std::cout << std::thread::hardware_concurrency() << '\n';
    auto startClock = std::chrono::steady_clock::now();
    size_t num_threads { 16 };
    size_t blockSize = vec->size() / num_threads;
    size_t start { 0 };

    std::vector<std::thread> threads{};
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(calculateSum, std::ref(*vec), start, start + blockSize);
        start += blockSize;
    }

    for (auto& i: threads) {
        i.join();
    }

    std::cout << s_sum << '\n';
    auto end = std::chrono::steady_clock::now();
    auto result = std::chrono::duration<float>(end - startClock);
    std::cout << result << '\n'; 

    s_sum = 0;

    startClock = std::chrono::steady_clock::now(); 
    for (const auto& i: *vec){
        s_sum += i;
    }
    std::cout << s_sum << '\n';
    end = std::chrono::steady_clock::now();
    result = std::chrono::duration<float>(end - startClock);
    std::cout << result << '\n'; 
}