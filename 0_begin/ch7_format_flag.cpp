#include <iostream>
#include <string>

int main() {
  int t;
  while (true) {
    /*std::cin.setf(std::ios_base::hex, std::ios_base::basefield);*/
    /*std::cin >> t;*/
    /*std::cout << "input:: " << t << std::endl;*/
    std::cin >> std::hex >> t;
    std::cout << "input:: " << t << std::endl;
    if (std::cin.fail()) {
      std::cout << "Valid input please" << std::endl;
      std::cin.clear();
    }
    if (t == 0)
      break;
  }
}
