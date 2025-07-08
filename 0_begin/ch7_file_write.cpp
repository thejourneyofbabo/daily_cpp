#include <fstream>
#include <iostream>
#include <string>

int main() {
  // Prepare to write file
  std::ofstream out("test.txt");

  std::string s;
  if (out.is_open()) {
    out << "Let's write this!!";
  }

  return 0;
}
