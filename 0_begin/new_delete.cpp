// New Delete Example
#include <iostream>

int main() {
  int* p = new int;
  *p = 10;

  std::cout << *p << std::endl;

  delete p;

  ////////
  // int a = 5;
  // delete &a;
  // //////

  // make array with new
  int arr_size;
  std::cout << "aray size: ";
  std::cin >> arr_size;

  int* list = new int[arr_size];
  for (int i = 0; i < arr_size; i++) {
    std::cout << i << " th component: ";
    std::cin >> list[i];
  }
  for (int i = 0; i < arr_size; i++) {
    std::cout << i << "th element of list : " << list[i] << std::endl;
  }

  delete[] list;

  return 0;
}
