#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  /*for (size_t i = 0; i < vec.size(); i++) {*/
  /*  std::cout << i + 1 << " th element in vec is " << vec[i] << std::endl;*/
  /*}*/

  // print whole vector
  /*for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
   * {*/
  for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
    std::cout << *itr << std::endl;
  }

  std::vector<int>::iterator itr = vec.begin() + 2;
  std::cout << "3rd element:: " << vec[2] << std::endl;
  std::cout << "3rd element:: " << *itr << std::endl;

  std::cout << "-----------------------------" << std::endl;
  // remove vec[3]
  vec.erase(vec.begin() + 3);
  print_vector(vec);
}
