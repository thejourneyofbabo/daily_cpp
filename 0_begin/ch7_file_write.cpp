#include <fstream>
#include <iostream>
#include <string>

int main() {
  // Prepare to write file
  /*std::ofstream out("test.txt");*/
  std::ofstream out("test.txt", std::ios::app);

  std::string s;
  /*if (out.is_open()) {*/
  /*  out << "Let's write this!!";*/
  /*}*/
  if (out.is_open()) {
    out << "add this";
  }

  return 0;
}
