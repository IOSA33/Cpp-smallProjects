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

        // This is also works, but it is better to not ignore the invalid input
        /*
        if (hasUnextractedInput()) {
            ignoreLine();
            continue;
        }
        */

        // Now we check if cin is failure ofr example input for example 'a', because cin cant convert the
        // A to a decimal that's why cin enters the infinite loop in the buffer for trying everytime the convert the 'a'
        // We are telling "if the cin is failure enter the if statement". This will work also "if (std::cin.fail())"
        if (!std::cin) {
            // "clear the error state" of cin
            std::cin.clear(); // Put us back in 'normal' operation mode
            ignoreLine();     // And remove the bad input
            continue;
        }

        ignoreLine();
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