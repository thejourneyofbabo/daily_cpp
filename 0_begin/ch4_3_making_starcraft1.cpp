#include <iostream>
#include <string>

class Marine {
  int hp;
  int coord_x, coord_y;
  int damage;
  bool is_dead;
  // char* name;
  std::string name;

 public:
  Marine();
  // Marine(int x, int y, const char* marine_name);
  Marine(int x, int y, const std::string& marine_name);
  Marine(int x, int y);
  ~Marine();

  int attack();  // return the damage
  void be_attacked(int damage_earn);
  void move(int x, int y);

  void show_status();
};
Marine::Marine() {
  coord_x = coord_y = 0;
  hp = 50;
  damage = 5;
  is_dead = false;
  name = "";
}
// Marine::Marine(int x, int y) {
//   coord_x = x;
//   coord_y = y;
//   hp = 50;
//   damage = 5;
//   is_dead = false;
//   name = "";
// }
Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false), name("") {}
Marine::Marine(int x, int y, const std::string& marine_name)
    : coord_x(x),
      coord_y(y),
      name(marine_name),
      hp(50),
      damage(5),
      is_dead(false) {}
// Marine::Marine(int x, int y, const char* marine_name) {
// Marine::Marine(int x, int y, const std::string marine_name) {
//   // name = new char[strlen(marine_name) + 1];
//   // strcpy(name, marine_name);
//   name = marine_name;
//
//   coord_x = x;
//   coord_y = y;
//   hp = 50;
//   damage = 5;
//   is_dead = false;
// }
void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << "*** Marine : " << name << " ***" << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << "HP : " << hp << std::endl;
}
Marine::~Marine() {
  std::cout << name << "'s destructor called!" << std::endl;
  // if (name != "") {
  //   delete[] name;
  // }
  // No need for std::string
}

// Marines with array
int main() {
  Marine* marines[100];

  marines[0] = new Marine(2, 3, "Marine 1");
  marines[1] = new Marine(3, 5, "Marine 2");

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << std::endl << "Marine1 attacked Marine2!" << std::endl;

  marines[1]->be_attacked(marines[0]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}

// Basic version main
// int main() {
//   Marine marine1(2, 3);
//   Marine marine2(3, 5);
//
//   marine1.show_status();
//   marine2.show_status();
//
//   std::cout << std::endl << "Marine1 attacked Marine2!" << std::endl;
//   marine2.be_attacked(marine1.attack());
//
//   marine1.show_status();
//   marine2.show_status();
// }
