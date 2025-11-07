#ifndef PAIR_H
#define PAIR_H

template <typename T> // <class T> class is not preferred
struct PairHeader {
    T first{};
    T second{};
};

template <typename T>
constexpr T maxHeader(PairHeader<T> p)
{
    return (p.first < p.second ? p.second : p.first);
}

#endif //PAIR_H
