#include <iostream>

class Parent {
 public:
  Parent() { std::cout << "Called Parrent constructor" << std::endl; }
  virtual ~Parent() {
    std::cout << "Called Parrent deconstructor" << std::endl;
  }
};
class Child : public Parent {
 public:
  Child() : Parent() { std::cout << "Called Child constructor" << std::endl; }
  ~Child() { std::cout << "Called Child deconstructor" << std::endl; }
};

int main() {
  std::cout << "--- Make normal child ---" << std::endl;
  /*Child c;*/
  {
    Child c;
  }
  std::cout << "--- Point Child with Parent's pointer ---" << std::endl;
  {
    Parent *p = new Child();
    delete p;
  }
}
