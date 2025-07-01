// #include <iostream>
//
// int& function() {
//   // int a = 2;
//   int* a = new int(2);
//   // delete a;
//   return *a;
// }
//
// int main() {
//   int b = function();
//   std::cout << b << std::endl;
//   // delete *a;
//
//   return 0;
// }

// #include <iostream>
//
// int* function() {  // 포인터 반환
//   int* a = new int(2);
//   return a;  // 포인터 자체를 반환
// }
//
// int main() {
//   int* b = function();
//   std::cout << *b << std::endl;
//   delete b;  // 반드시 해제!
//   return 0;
// }

#include <iostream>
#include <memory>

std::unique_ptr<int> function() {
  auto a = std::make_unique<int>(2);
  return a;
}

int main() {
  auto b = function();
  std::cout << *b << std::endl;
  // 자동으로 메모리 해제됨!
  return 0;
}
