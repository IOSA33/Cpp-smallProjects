#include <iostream>

template <typename T, typename N, typename G>
class Triad
{
private:
    T m_first{};
    N m_second{};
    G m_third{};

public:
    // When we define a member function inside the class definition,
    // the template parameter declaration belonging to the class applies
    Triad(const T& first, const N& second, const G& third)
        : m_first{ first }
        , m_second{ second }
        , m_third{ third }
    {
    }

    void print() const;

    const T& first() const {
        return m_first;
    }
};

template <typename T, typename N, typename G>
void Triad<T,N,G>::print() const {
    std::cout << m_first << " " << m_second << " " << m_third << std::endl;
}

int main()
{
    Triad<int, int, int> t1{ 1, 2, 3 };
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{ 1, 2.3, "Hello"s };
    t2.print();
    std::cout << '\n';

    return 0;
}