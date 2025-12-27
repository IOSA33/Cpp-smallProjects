#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}
int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

ArithmeticFunction getArithmeticFunction(char op) {
    switch (op)
    {
    case '+': return &add;
    case '-': return &subtract;
    case '*': return &multiply;
    case '/': return &divide;

    default:
        return nullptr;
    }
} 

char getOperation()
{
    char op{};

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op!='+' && op!='-' && op!='*' && op!='/');

    return op;
}

int main()
{
    int x{ getInteger() };
    char op{ getOperation() };
    int y{ getInteger() };

    ArithmeticFunction fcn{ getArithmeticFunction(op) };
    if (fcn)
        std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';


    return 0;
}