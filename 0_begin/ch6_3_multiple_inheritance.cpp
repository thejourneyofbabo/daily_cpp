// Multiple Inheritance

#include <iostream>

class A {
public:
  int a;

  A() { std::cout << "Call A constructor" << std::endl; }
};

class B {
public:
  int b;

  B() { std::cout << "Call B constructor" << std::endl; }
};

class C : public A, public B {
public:
  int c;

  C() : A(), B() { std::cout << "Call C constructor" << std::endl; }
};

int main() {
  C c;
  c.a = 3;
  std::cout << c.a << std::endl;
}
