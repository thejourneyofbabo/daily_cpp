#include <iostream>
#include <iterator>
#include <vector>

template <typename T> void print_vector(std::vector<T> &vec) {
  // printout all vector
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

  std::cout << "Reverse print vector" << std::endl;
  // itr point vec[2]
  std::vector<int>::reverse_iterator r_iter = vec.rbegin();
  for (; r_iter != vec.rend(); r_iter++) {
    std::cout << *r_iter << std::endl;
  }
}
