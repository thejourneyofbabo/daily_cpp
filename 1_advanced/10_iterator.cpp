#include <iostream>
#include <vector>

template <typename T> void print_vector(std::vector<T> &vec) {
  // print all vector
  for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
       ++itr) {
    std::cout << *itr << std::endl;
  }
}

int main() {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  std::cout << "Initial vector state" << std::endl;
  print_vector(vec);
  std::cout << "-----------------------------" << std::endl;

  // add 15 infront of vec[2]
  vec.insert(vec.begin() + 2, 15);
  print_vector(vec);

  std::cout << "-----------------------------" << std::endl;
  // remove vec[3]
  vec.erase(vec.begin() + 3);
  print_vector(vec);
}
