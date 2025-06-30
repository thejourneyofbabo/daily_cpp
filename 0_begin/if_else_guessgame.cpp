// Lucky Number
#include <iostream>

int main() {
  int lucky_number = 3;
  std::cout << "Guess what is my number~ " << std::endl;

  int user_input;  // User input

  while (1) {
    std::cout << "input: ";
    std::cin >> user_input;
    if (lucky_number == user_input) {
      std::cout << "Correct!!~~" << std::endl;
      break;
    } else {
      std::cout << "Guess again" << std::endl;
    }
  }
  return 0;
}
