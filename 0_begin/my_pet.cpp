#include <iostream>

struct Animal {
  char name[30];  // name
  int age;        // age

  int health;  // health
  int food;    // how full?
  int clean;   // how clean?
  // Animal;
};

void create_animal(Animal *animal) {
  std::cout << "Name of the Animal? ";
  std::cin >> animal->name;

  std::cout << "Age of the Animal? ";
  std::cin >> animal->age;

  animal->health = 100;
  animal->food = 100;
  animal->clean = 100;
}

void play(Animal *animal) {
  animal->health += 10;
  animal->food -= 20;
  animal->clean -= 30;
}
void one_day_pass(Animal *animal) {
  // After one day pass
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}
void show_stat(Animal *animal) {
  std::cout << "\n" << animal->name << "'s status" << std::endl;
  std::cout << "Health:     " << animal->health << std::endl;
  std::cout << "How Full:   " << animal->food << std::endl;
  std::cout << "How Clean:  " << animal->clean << std::endl;
}

int main() {
  Animal *list[10];
  int animal_num = 0;

  for (;;) {
    std::cout << "\n1. Add Animal" << std::endl;
    std::cout << "2. Play with Animal" << std::endl;
    std::cout << "3. See the Animal Status\n" << std::endl;

    int input;
    std::cout << "Select one: ";
    std::cin >> input;
    std::cout << std::endl;

    switch (input) {
      int play_with;
      case 1:
        list[animal_num] = new Animal;
        create_animal(list[animal_num]);

        animal_num++;
        break;

      case 2:
        std::cout << "I want to play with: ";
        std::cin >> play_with;

        if (play_with < animal_num) play(list[play_with]);

        break;

      case 3:
        std::cout << "I want to check: ";
        std::cin >> play_with;

        if (play_with < animal_num) show_stat(list[play_with]);
        break;
    }

    for (int i = 0; i != animal_num; i++) {
      one_day_pass(list[i]);
    }
  }
  for (int i = 0; i != animal_num; i++) {
    delete list[i];
  }
}
