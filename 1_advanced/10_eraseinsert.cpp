#include <iostream>
#include <vector>

template <typename T> void print_vector(std::vector<T> &vec) {
  // printout whole vector
  std::cout << "[ ";
  for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
       ++itr) {
    std::cout << *itr << " ";
  }
  std::cout << "]" << std::endl;
  ;
}

int main() {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);
  vec.push_back(20);

  std::cout << "initial vector state" << std::endl;
  print_vector(vec);

  std::vector<int>::iterator itr = vec.begin();
  std::vector<int>::iterator end_itr = vec.end();

  /*for (; itr != end_itr; ++itr) {*/
  /*  if (*itr == 20) {*/
  /*    vec.erase(itr);*/
  /*  }*/
  /*}*/

  for (; itr != vec.end(); ++itr) {
    if (*itr == 20) {
      vec.erase(itr);
      itr = vec.begin();
    }
  }

  std::cout << "eliminate the element with the value 20" << std::endl;
  print_vector(vec);
}
