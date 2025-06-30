// Simple c++ porgram
#include <iostream>
#include <ostream>

int main() {
  std::cout << "Hello, world" << std::endl;
  std::cout << "I am Jisang" << std::endl;

  std::cout << "hi" << std::endl
            << "my name is "
            << "Psi" << std::endl;

  // int i;

  // for (i = 0; i < 10; i++) {
  //   std::cout << i << std::endl;
  // }

  int sum = 0;

  for (int i = 1; i <= 10; i++) {
    sum += i;
  }

  std::cout << "total sum: " << sum << std::endl;

  return 0;
}
