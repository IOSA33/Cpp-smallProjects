#include <iostream>

template <typename T> // <class T> is not preferred
struct Pair {
  T first{};
  T second{};
};

int main() {
  Pair<int> p1 {5, 6};
  std::cout << p1.first << " " << p1.second << std::endl;

  Pair<double> p2 {1.2, 2.3};
  std::cout << p2.first << " " << p2.second << std::endl;


}