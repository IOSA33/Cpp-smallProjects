#include <iostream>
#include <vector>
#include <unordered_map>
#include <print>

class FreqStack {
private:
    std::vector<int> _m_vec{};

public:
    FreqStack() {
        
    }

    void get() const {
        for (const auto& i : _m_vec) {
            std::cout << i;
        }
        std::cout << '\n';
    }
    
    void push(int val) {
        _m_vec.push_back(val);
    }
    
    int pop() {
        if (_m_vec.empty()) return 0;
        std::unordered_map<int, int> _umap {};
        for (const auto& i : _m_vec) {
            _umap[i]++;
        }

        int _max_v { 0 };
        int counts { 0 };
        for (const auto& [ key, value ] : _umap) {
            if (value > counts) {
                _max_v = key;
                counts = value;
            }
        }

        long sizze { std::ssize(_m_vec) - 1 };
        for (int i { static_cast<int>(sizze) }; i >= 0; --i) {
            if (_m_vec[static_cast<size_t>(i)] == _max_v) {
                _m_vec.erase(_m_vec.begin() + i);
                break;
            }
        }

        return _max_v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
    FreqStack* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);

    obj->get();

    obj->pop();
    obj->get();

    obj->pop();
    obj->get();

    obj->pop();
    obj->get();

    obj->pop();
    obj->get();

    delete obj;
}