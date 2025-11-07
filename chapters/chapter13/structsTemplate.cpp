#include <iostream>
#include <utility>
#include "pair.h"

template <typename T, typename U>
constexpr T maxHeader(PairHeader<T> p); // forward declaration

template <typename T, typename U> // <class T> class is not preferred
struct Pair {
  T first{};
  U second{};
};

template <typename T, typename U>
constexpr T max(Pair<T, U> p)
{
  return (p.first < p.second ? p.second : p.first);
}

template <typename T, typename U>
void print(std::pair<T, U> p) {
  std::cout << p.first << ' ' << p.second << '\n';
}

int main() {
  Pair<int, double> p1 {5, 6};
  std::cout << p1.first << " " << p1.second << std::endl;

  std::pair<int, double> p11{ 1, 2.3 }; // a pair holding an int and a double
  std::pair<double, int> p22{ 4.5, 6 }; // a pair holding a double and an int
  std::pair<int, int> p33{ 7, 8 };      // a pair holding two ints

  print(p22);

  Pair<double, double> p2 {1.0, 2.3};
  PairHeader<double> p322 {1.0, 2.3};
  std::cout << p2.first << " " << p2.second <<  ": " << max(p2) << std::endl;
  std::cout << maxHeader(p322) << " is larger\n";
}