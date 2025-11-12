#include <iostream>

class Ball {
  std::string m_color{};
  double m_radius{};

public:
  Ball(const std::string& color, const double radius) : m_color{color}, m_radius{radius} {
    std::cout << "Blue class constructor" << std::endl;
  }

  const std::string& getColor() const {
    return m_color;
  }

  double getRadius() const {
    return m_radius;
  }
};

void print(const Ball& obj) {
    std::cout << obj.getColor() << ", " << obj.getRadius() << "\n";
}

int main() {
  Ball blue { "blue", 10.0 };
  print(blue);

  Ball red { "red", 12.0 };
  print(red);

  return 0;
}