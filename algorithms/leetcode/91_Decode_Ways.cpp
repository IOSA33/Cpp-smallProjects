#include <iostream>
#include <string>


int solution(const std::string& s) {
    int result{};
    
    if (s[0] > 0) {
        result = 1;  
    }
    
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] > 0)
            ++result;

        int temp = s[i] - '0';
        int temp1 = s[i - 1] - '0';
        if (temp * 10 + temp1 <= 26 || temp * 10 + temp1 > 0 && temp1 > 0)
            ++result;
    }

    return result;
}

int main() {
    // 2
    std::string s1{"12"};
    // 3
    std::string s2{"226"};
    // 0
    std::string s3{"06"};

    std::cout << solution(s1) << std::endl;
    std::cout << solution(s2) << std::endl;
    std::cout << solution(s3) << std::endl;
}