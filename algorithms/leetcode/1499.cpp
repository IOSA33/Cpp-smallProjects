#include <vector>
#include <iostream>
#include <algorithm>

int findMaxValueOfEquation(std::vector<std::vector<int>>& points, int k) {
    std::vector<int> _result_vec {};
    
    for (size_t i{ 0 }; i < points.size() - 1; ++i) {
        for (size_t j { i + 1}; j < points.size(); ++j) {
            std::cout << "___New ForLoop___\n";
            int _r { points[i][0] - points[j][0]};
            
            std::cout << "Old _r: " << _r << '\n';

            if (_r < 0) _r = _r * (-1); 
            std::cout << "New _r: " << _r << '\n';

            if (_r <= k) {
                int _result_value { points[i][1] + points[j][1] + _r };
                
                std::cout << "_result_value: " << _result_value << '\n';

                _result_vec.emplace_back(_result_value);
            }
        }
    }

    for(const auto& i : _result_vec) {
        std::cout << i << '\n';
    }

    int _return_result  { std::ranges::max(_result_vec) };
        
    return _return_result;
}

int main() {
    int k = 6;
    std::vector<std::vector<int>> _test_vec {
        {-19, -12}, {-13, -18}, {-12, 18}, {-11, -8}, {-8, 2},
        {-7, 12},   {-5, 16},   {-3, 9},   {1, -7},   {5, -4},
        {6, -20},   {10, 4},    {16, 4},   {19, -9},  {20, 19}
    };
    int res = findMaxValueOfEquation(_test_vec, k);
    std::cout << "Answer: " << res << '\n';

    return 0;
}