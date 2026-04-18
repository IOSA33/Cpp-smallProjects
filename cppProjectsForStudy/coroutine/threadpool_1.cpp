#include <vector>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <functional>
#include <queue>
#include <chrono>

using namespace std::chrono_literals;

class ThreadPool {
private:
    void ThreadLoop();

    bool m_stop{ false };
    std::mutex m_queue_mutex{};
    std::condition_variable m_mutex_condition{};
    std::vector<std::thread> m_vector_threads{};
    std::queue<std::function<void()>> m_jobs{};
public:

    void Start();
    void QueueJob(const std::function<void()>& job);
    void Stop();
    bool taskInQueue();
};

void ThreadPool::Start() {
    const uint32_t num_threads { std::thread::hardware_concurrency() };
    for (uint32_t i { 0 }; i < num_threads; ++i) {
        m_vector_threads.emplace_back(std::thread(&ThreadPool::ThreadLoop, this));
    }  
}

void ThreadPool::ThreadLoop() {
    while(true) {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(m_queue_mutex);
            m_mutex_condition.wait(lock, [this] {
                return !m_jobs.empty() || m_stop;
            });
            if (m_stop && m_jobs.empty()) {
                return;
            }
            job = m_jobs.front();
            m_jobs.pop();
        }
        job();
    }
}

void ThreadPool::QueueJob(const std::function<void()>& job) {
    {
        std::unique_lock<std::mutex> lock(m_queue_mutex);
        m_jobs.emplace(job);
    }
    m_mutex_condition.notify_one();
}

bool ThreadPool::taskInQueue() {
    bool poolbusy{};
    {
        std::unique_lock<std::mutex> lock(m_queue_mutex);
        poolbusy = !m_jobs.empty();
    }
    return poolbusy;
}

void ThreadPool::Stop() {
    {
        std::unique_lock<std::mutex> lock(m_queue_mutex);
        m_stop = true;
    }
    m_mutex_condition.notify_all();
    for (std::thread& active_thread : m_vector_threads) {
        active_thread.join();
    }
    m_vector_threads.clear();
}


// This is try to do a threadpool, that I will use in my
// HTTPS library. 

int main() {
    ThreadPool my_threadPool{};
    
    my_threadPool.Start();

    my_threadPool.QueueJob([] {
        std::cout << "First Task 2000ms\n";
        std::this_thread::sleep_for(2000ms);
        std::cout << "Complete 2000ms\n";
    });
    my_threadPool.QueueJob([] {
        std::cout << "First Task 3000ms\n";
        std::this_thread::sleep_for(3000ms);
        std::cout << "Complete 3000ms\n";
    });
    my_threadPool.QueueJob([] {
        std::cout << "First Task 1000ms\n";
        std::this_thread::sleep_for(1000ms);
        std::cout << "Complete 1000ms\n";
    });

    my_threadPool.QueueJob([] {
        std::cout << "First Task 23000ms\n";
        std::this_thread::sleep_for(1000ms);
        std::cout << "Complete 23000ms\n";
    });

    for(int i = 0; i < 10; ++i) {
        my_threadPool.QueueJob([i] {
            std::cout << "First Task forloop "<< i << "\n";
            std::this_thread::sleep_for(1000ms);
            std::cout << "Complete forloop "<< i << "\n";
        });
    }

    // Only execute if in queue is some task
    while (my_threadPool.taskInQueue()) {
        std::cout << "Waiting...\n";
        std::this_thread::sleep_for(1000ms);
    }

    my_threadPool.Stop();
}