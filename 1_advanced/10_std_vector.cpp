#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << i + 1 << " th element in vec is " << vec[i] << std::endl;
  }
}
