#include <iostream>
#include <string>

int main() {
  // standard so string inside std
  std::string s = "abc";
  std::string t = "def";
  std::string s2 = s;

  /*std::cout << s << std::endl;*/
  std::cout << "Legnth of 's' is: " << s.length() << std::endl;
  std::cout << "If we add 't' behind 's': " << s + t << std::endl;

  if (s == s2) {
    std::cout << s << " and " << s2 << " they are same " << std::endl;
  }
  if (s != t) {
    std::cout << s << " and " << t << " they are different " << std::endl;
  }

  return 0;
}
