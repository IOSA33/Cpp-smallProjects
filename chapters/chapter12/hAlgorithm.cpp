#include <iostream>
#include <stdlib.h>
#include <list>
#include <bits/ostream.tcc>


int findMaxH(const std::list<int>& number) {
    int temp = 0;
    int index = 1;
    int result = 0;
    int loop = 0;

    while (loop <= number.size()) {
        for (const int value : number) {
            if (value >= index) {
                ++temp;
                if (temp == index) {
                    ++result;
                    ++index;
                    break;
                }
            }
        }
        temp = 0;
        ++loop;
    }
    return result;
}
int main() {
    const std::list<int> list = {3,0,6,1,6, 6, 7, 2, 0, 10};

    std::cout << findMaxH(list) << std::endl;

    return EXIT_SUCCESS;
}
