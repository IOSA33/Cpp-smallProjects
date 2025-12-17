#include <iostream>
#include <array>
#include <string>

using namespace std::string_view_literals;

namespace Animal {
    enum Type {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };

    struct Data
    {
        std::string_view name{};
        int legs{};
        std::string_view sound{};
    };

    constexpr std::array types { chicken, dog, cat, elephant, duck, snake };
    constexpr std::array data {
        Data{ "chicken",    2, "cluck" },
        Data{ "dog",        4, "woof" },
        Data{ "cat",        4, "meow" },
        Data{ "elephant",   4, "pawoo" },
        Data{ "duck",       2, "quack" },
        Data{ "snake",      0, "hissss" },
    };

    static_assert(std::size(types) == max_animals);
    static_assert(std::size(data) == max_animals);
}

constexpr Animal::Data getData(Animal::Type x) {
    return Animal::data[x];
}

std::ostream& operator<<(std::ostream& out, const Animal::Data& data) {
    std::cout << "A " << data.name << " has " << data.legs << " legs and says " << data.sound;
    return out;
}

std::istream& operator>>(std::istream& in, Animal::Type& animal) {
    std::string input{};
    std::getline(in >> std::ws, input);

    for (std::size_t i = 0; i < Animal::data.size(); ++i) {
        if (input == Animal::data[i].name) {
            animal = static_cast<Animal::Type>(i);
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);
    return in;
}

int main() {
    std::cout << "Enter an animal: ";
    Animal::Type type{};
    std::cin >> type;

    if (!std::cin) {
        std::cin.clear();
        std::cout << "That animal couldn't be found.\n";
        type = Animal::max_animals;
    } else {
        std::cout << getData(type);
    }

    std::cout << std::endl;
    std::cout << "\nRest of the animals:\n";

    for (auto a: Animal::types) {
        if (a != type)
            std::cout << getData(a) << '\n';
    }
}


// Enter an animal: dog
// A dog has 4 legs and says woof.
//
// Here is the data for the rest of the animals:
// A chicken has 2 legs and says cluck.
// A cat has 4 legs and says meow.
// A elephant has 4 legs and says pawoo.
// A duck has 2 legs and says quack.
// A snake has 0 legs and says hissss.