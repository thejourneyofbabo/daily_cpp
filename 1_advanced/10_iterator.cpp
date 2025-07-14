#include <iostream>
#include <vector>

template <typename T> void print_vector(std::vector<T> &vec) {
  // print all vector
  for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
       ++itr) {
    std::cout << *itr << std::endl;
  }
}

int main() { std::vector<int> vec; }
