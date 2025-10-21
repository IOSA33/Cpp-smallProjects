#include <iostream>

int main()
{
    int x{ 1 };
    int& ref{ x };
    const int& ref1{ ref };

    std::cout << x << ref << ref1 << '\n';

    int y{ 2 };
    ref = y;
    y = 3;

    std::cout << x << ref << '\n';

    x = 4;

    std::cout << x << ref << '\n';

    return 0;
}