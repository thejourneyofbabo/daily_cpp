#include <iostream>
#include <string>

// ==================================
// Core Inheritance Concepts Demo
// ==================================

// 1. Abstract Base Class with Pure Virtual Function
class Vehicle {
protected:
  std::string name;

public:
  Vehicle(std::string n) : name(n) {
    std::cout << "Vehicle " << name << " created" << std::endl;
  }

  // Virtual destructor - ESSENTIAL for inheritance!
  virtual ~Vehicle() {
    std::cout << "Vehicle " << name << " destroyed" << std::endl;
  }

  // Pure virtual function - must be implemented by derived classes
  virtual void move() = 0;

  // Regular virtual function - can be overridden
  virtual void start() { std::cout << name << " engine started" << std::endl; }

  // Non-virtual function
  void info() { std::cout << "This is " << name << std::endl; }
};

// 2. Single Inheritance with Virtual Functions
class Car : public Vehicle {
private:
  std::string *license_plate; // Dynamic memory for destructor demo

public:
  Car(std::string n, std::string plate) : Vehicle(n) {
    license_plate = new std::string(plate);
    std::cout << "Car with license " << *license_plate << " ready" << std::endl;
  }

  ~Car() {
    std::cout << "Car license " << *license_plate << " removed" << std::endl;
    delete license_plate; // Virtual destructor ensures this is called!
  }

  // Implement pure virtual function
  void move() override { std::cout << name << " drives on roads" << std::endl; }

  void start() override {
    std::cout << name << " car engine vrooom!" << std::endl;
  }

  void honk() { std::cout << name << " goes BEEP BEEP!" << std::endl; }
};

class Boat : public Vehicle {
public:
  Boat(std::string n) : Vehicle(n) {
    std::cout << "Boat is in the water" << std::endl;
  }

  // Implement pure virtual function
  void move() override { std::cout << name << " sails on water" << std::endl; }

  void start() override {
    std::cout << name << " boat engine purrs" << std::endl;
  }
};

// 3. Multiple Inheritance
class CanFly {
public:
  virtual void fly() { std::cout << "Flying through the sky!" << std::endl; }
  int max_altitude = 10000;
};

class AmphibiousPlane : public Vehicle, public CanFly {
public:
  AmphibiousPlane(std::string n) : Vehicle(n) {
    std::cout << "Amphibious plane ready for land and sky" << std::endl;
  }

  // Must implement pure virtual from Vehicle
  void move() override {
    std::cout << name << " can drive AND fly!" << std::endl;
  }

  // Override from CanFly
  void fly() override {
    std::cout << name << " takes off from water!" << std::endl;
  }

  void demonstrate() {
    start();
    move();
    fly();
    std::cout << "Max altitude: " << max_altitude << " feet" << std::endl;
  }
};

int main() {
  std::cout << "=== C++ Inheritance Core Concepts Demo ===\n" << std::endl;

  // Cannot create abstract class instance
  // Vehicle v("generic");  // ERROR! Pure virtual function exists

  std::cout << "--- Creating vehicles ---" << std::endl;
  Car car("Tesla", "ABC123");
  Boat boat("Titanic");
  AmphibiousPlane seaplane("SeaEagle");

  std::cout << "\n--- Polymorphism with virtual functions ---" << std::endl;
  Vehicle *vehicles[] = {&car, &boat, &seaplane};

  for (int i = 0; i < 3; i++) {
    vehicles[i]->info();  // Non-virtual function
    vehicles[i]->start(); // Virtual function - different implementations
    vehicles[i]->move();  // Pure virtual - must be implemented
    std::cout << std::endl;
  }

  std::cout << "--- Multiple inheritance demo ---" << std::endl;
  seaplane.demonstrate();

  // Downcasting with dynamic_cast (safe casting)
  std::cout << "\n--- Safe downcasting ---" << std::endl;
  Vehicle *mystery = &car;

  Car *car_ptr = dynamic_cast<Car *>(mystery);
  if (car_ptr) {
    std::cout << "Successfully cast to Car! ";
    car_ptr->honk(); // Car-specific function
  }

  Boat *boat_ptr = dynamic_cast<Boat *>(mystery);
  if (!boat_ptr) {
    std::cout << "Cannot cast Car to Boat (correctly failed)" << std::endl;
  }

  std::cout << "\n--- Virtual destructor demo ---" << std::endl;
  {
    Vehicle *v = new Car("TempCar", "XYZ789");
    delete v; // Virtual destructor ensures Car's destructor is called!
  }

  std::cout << "\n--- End of scope - automatic cleanup ---" << std::endl;
  return 0;
}

/*
This single example demonstrates ALL core inheritance concepts:

🏗️  VIRTUAL DESTRUCTOR:
    - Vehicle has virtual ~Vehicle()
    - Ensures proper cleanup when deleting through base pointer
    - Car's destructor properly called to free license_plate memory

🎯  PURE VIRTUAL FUNCTIONS:
    - Vehicle::move() = 0 makes Vehicle abstract
    - Cannot create Vehicle objects directly
    - All derived classes MUST implement move()

⚡  VIRTUAL FUNCTIONS & POLYMORPHISM:
    - start() behaves differently for each vehicle type
    - Same function call, different behavior based on actual object
    - Runtime decision (dynamic binding)

🔄  MULTIPLE INHERITANCE:
    - AmphibiousPlane inherits from both Vehicle and CanFly
    - Gets capabilities from both parent classes
    - Can access max_altitude from CanFly

🛡️  DYNAMIC_CAST:
    - Safe way to downcast base pointer to derived pointer
    - Returns nullptr if cast is invalid
    - Compile-time type safety

📊  INHERITANCE HIERARCHY:
    Vehicle (abstract)
    ├── Car
    ├── Boat
    └── AmphibiousPlane ──── CanFly

Key takeaways:
✅ Always use virtual destructors in base classes
✅ Pure virtual functions create abstract classes (interfaces)
✅ Virtual functions enable polymorphism
✅ Multiple inheritance gives multiple capabilities
✅ Use dynamic_cast for safe downcasting
*/
