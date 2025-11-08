#include <random>
#include <iostream>
#include <array>
#include <limits>
#include "guessPassword.h"

void getPasswordStruct(GuessPass::Pass& pass);

void getRandomPass(std::array<int, 4>& pass) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 4);

    int validCount{};
    int count{};

    while (validCount != 4) {
        bool passed = true;
        const int value = dis(gen);
        for (int j = 0; j < 4; j++) {
            if (value == pass[j]) {
                passed = false;
                break;
            }
        }

        if (passed) {
            pass[count] = value;
            ++count;
            ++validCount;
        }
    }
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function for a detection EOF end of file, aka "No more data available"
// e.g. user presses "Windows (via ctrl-Z + ENTER)"
bool clearFailedExtraction() {
    // If user writes input that cant be converted to a right type, std::cin goes into 'failure' mode.
    // Or you can write !std::cin, because it is a boolean conversion
    if (!std::cin) {
        if (std::cin.eof()) { // If the user entered an EOF
            std::exit(0);
        }
        std::cin.clear(); // Put us back in 'normal' operation mode, from failure mode
        ignoreLine(); // Removing the bad input

        return true;
    }

    return false;
}

void gettingStart() {
    int input{};

    while (input != 1) {
        std::cout << "Press 1 to start the game, :)" << '\n';
        std::cin >> input;

        if (clearFailedExtraction()) {
            std::cout << "Oops, that input is invalid. Please try again.\n";
            continue;
        }

        ignoreLine(); // Remove any extraneous input
    }
}

void gettingPassFromUser(std::array<int, 4>& userInput) {
    std::string input{};
    int validCount{0};

    while (validCount != 4 || input.size() != 4) {
        validCount = 0;

        std::cout << "Enter a pass, like Example: 1234" << '\n';
        std::cin >> input;

        if (clearFailedExtraction()) {
            std::cout << "Oops, that input is invalid. Please try again.\n";
            continue;
        }
        ignoreLine();

        for (int i = 0; i < 4; i++) {
            const int n = input[i] - '0';

            if (n > 0 && n < 5 ) {
                userInput[i] = n;
                ++validCount;
            } else {
                std::cout << "Invalid input: " << input[i] <<  '\n';
                break;
            }
        }
    }

    std::cout << input;
    std::cout << '\n';
}

bool checkForResutl(const std::array<int, 4>& randomPass, std::array<int, 4>& userPass) {
    for (int i = 0; i < randomPass.size(); i++) {
        if (userPass[i] != randomPass[i]) {
            std::cout << "This number " << userPass[i] << " is in incorrect position " << i << '\n';
            return false;
        }
    }

    return true;
}

int main() {
    gettingStart();

    // Just an example of struct
    GuessPass::Pass pass{};
    getPasswordStruct(pass);
    std::cout << pass.pass1 << pass.pass2 << pass.pass3 <<pass.pass4 << std::endl;

    std::array<int, 4> randomPass{};
    getRandomPass(randomPass);

    for (int i = 0; i < 4; i++) {
        std::cout << randomPass[i];
    }
    std::cout << '\n';

    std::cout << "Try to guess the password, :) \n";
    std::array<int, 4> passFromUser{};

    while (true) {
        gettingPassFromUser(passFromUser);

        if (checkForResutl(randomPass, passFromUser)) {
            break;
        }
    }

    std::cout << "Congrats, you won the Game, :)" << '\n';

    return EXIT_SUCCESS;
}