#include <iostream>

class Animal {
 private:
  int food;
  int weight;

 public:
  int test;
  void set_animal(int _food, int _weight) {
    food = _food;
    weight = _weight;
  }
  void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
  }
  void view_status() {
    std::cout << "This animal's food is : " << food << std::endl;
    std::cout << "This animal's weight is : " << weight << std::endl;
  }
};

int main() {
  Animal animal;
  animal.set_animal(100, 50);
  animal.increase_food(30);

  animal.view_status();
  animal.test = 10;
  std::cout << animal.test << std::endl;  // Public variable
  // std::cout << animal.food << std::endl; // Wrong!! Can't use private
  // variables here.
  return 0;
}
