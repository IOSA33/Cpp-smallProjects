#include <iostream>
#include <bits/ostream.tcc>

unsigned int LCG16() {
    static unsigned int s_state{ 0 };

    s_state = 8252393 * s_state + 2396403;
    return s_state % 32768;
}


int main() {
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << LCG16() << '\t';

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }

    return EXIT_SUCCESS;
}