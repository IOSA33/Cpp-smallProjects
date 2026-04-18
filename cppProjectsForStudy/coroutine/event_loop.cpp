#include <iostream>
#include <thread>
#include <chrono>
#include <queue>
#include <array>

using namespace std::chrono_literals;

struct Task {
    std::string m_data{};

    Task(const std::string& data) : m_data(data) {};

    void download1() {
        std::cout << "Downloading 1...\n";
        std::this_thread::sleep_for(1000ms);
        std::cout << "Download 1 is ready!\n";
    }
    void download2() {
        std::cout << "Downloading 2...\n";
        std::this_thread::sleep_for(2000ms);
        std::cout << "Download 2 is ready!\n";
    }
};

// This whole try have several issues, first of all is its not concurrent of .join()
// Second this is pretty expensive to do, we creating all the time new threads .join() them 
// but overall its good attempt for the first try with basic understanding how it works

int main() {
    std::queue<Task> queue{{{"ip:123312"}, {"ip:342343"}, {"ip:12332312"}}};
    std::array<std::thread, 2> thread_array{};

    while(!queue.empty()){
        for(auto& t: thread_array) {
            if (t.joinable()) {
                t.join();
            }
            
            if (!queue.empty()) {
                Task task = queue.front();
                queue.pop();

                t = std::thread([task, &t]() mutable {
                    std::cout << "Thread " << t.get_id() << " is working on Task\n";
                    task.download2();
                });
            }
        }
    }

    std::cout << "Simulating gracuful shotdown" << std::endl;

    for (auto& t : thread_array) {
        if (t.joinable()) {
            t.join();    
        }
    }
}