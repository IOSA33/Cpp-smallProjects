#include <iostream>
#include <limits> // for std::numeric_limits

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Another method to check if the last input is \n or something else, for std::cin
// has extraneous input:
bool hasUnextractedInput() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

double getDouble()
{
    while (true){
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;

        if (hasUnextractedInput()) {
            ignoreLine();
            continue;
        }

        return x;
    }
}

char getOperator()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        // Check whether the user entered meaningful input
        switch (operation)
        {
            case '+':
            case '-':
            case '*':
            case '/':
                return operation; // return it to the caller
            default: // otherwise tell the user what went wrong
                std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    } // and try again
}

void printResult(double x, char operation, double y)
{
    std::cout << x << ' ' << operation << ' ' << y << " is ";

    switch (operation)
    {
        case '+':
            std::cout << x + y << '\n';
            return;
        case '-':
            std::cout << x - y << '\n';
            return;
        case '*':
            std::cout << x * y << '\n';
            return;
        case '/':
            std::cout << x / y << '\n';
            return;

    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}