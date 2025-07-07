#include <iostream>
#include <string>

// Base class: Animal
class Animal {
protected:
  std::string name;
  int age;
  std::string species;

public:
  // Parameterized constructor
  Animal(std::string name, int age, std::string species)
      : name(name), age(age), species(species) {
    std::cout << "Animal constructor: " << name << std::endl;
  }

  // Copy constructor
  Animal(const Animal &other) {
    name = other.name;
    age = other.age;
    species = other.species;
    std::cout << "Animal copy constructor: " << name << std::endl;
  }

  // Default constructor
  Animal() : name("Unknown"), age(0), species("Unknown") {
    std::cout << "Animal default constructor" << std::endl;
  }

  // Virtual functions for polymorphism
  virtual void make_sound() {
    std::cout << name << " makes an animal sound" << std::endl;
  }

  virtual void print_info() {
    std::cout << name << " (" << species << ", " << age
              << " years old) - Cost: $" << get_care_cost() << std::endl;
  }

  virtual int get_care_cost() {
    return 50 + age * 5; // Base care cost
  }

  // Virtual destructor (important for proper cleanup)
  virtual ~Animal() { std::cout << "Animal destructor: " << name << std::endl; }
};

// Derived class: Dog
class Dog : public Animal {
private:
  std::string breed;
  bool is_trained;

public:
  // Parameterized constructor
  Dog(std::string name, int age, std::string breed, bool is_trained)
      : Animal(name, age, "Dog"), breed(breed), is_trained(is_trained) {
    std::cout << "Dog constructor: " << name << std::endl;
  }

  // Copy constructor
  Dog(const Dog &other)
      : Animal(other), breed(other.breed), is_trained(other.is_trained) {
    std::cout << "Dog copy constructor: " << name << std::endl;
  }

  // Default constructor
  Dog() : Animal(), breed("Mixed"), is_trained(false) {
    std::cout << "Dog default constructor" << std::endl;
  }

  // Override virtual functions
  void make_sound() override {
    std::cout << name << " barks: Woof! Woof!" << std::endl;
  }

  void print_info() override {
    std::cout << name << " (Dog/" << breed << ", " << age << " years old, "
              << (is_trained ? "Trained" : "Not trained") << ") - Cost: $"
              << get_care_cost() << std::endl;
  }

  int get_care_cost() override {
    int base_cost = Animal::get_care_cost();
    int training_cost = is_trained ? 20 : 0;
    return base_cost + training_cost + 30; // Dog-specific costs
  }

  // Dog-specific functions
  void fetch() { std::cout << name << " fetches the ball!" << std::endl; }

  void sit() {
    if (is_trained) {
      std::cout << name << " sits obediently" << std::endl;
    } else {
      std::cout << name << " doesn't understand the command" << std::endl;
    }
  }
};

// Another derived class: Cat
class Cat : public Animal {
private:
  bool is_indoor;
  int num_lives;

public:
  Cat(std::string name, int age, bool is_indoor)
      : Animal(name, age, "Cat"), is_indoor(is_indoor), num_lives(9) {
    std::cout << "Cat constructor: " << name << std::endl;
  }

  Cat(const Cat &other)
      : Animal(other), is_indoor(other.is_indoor), num_lives(other.num_lives) {
    std::cout << "Cat copy constructor: " << name << std::endl;
  }

  Cat() : Animal(), is_indoor(true), num_lives(9) {
    std::cout << "Cat default constructor" << std::endl;
  }

  void make_sound() override {
    std::cout << name << " meows: Meow! Meow!" << std::endl;
  }

  void print_info() override {
    std::cout << name << " (Cat, " << age << " years old, "
              << (is_indoor ? "Indoor" : "Outdoor") << ", " << num_lives
              << " lives left) - Cost: $" << get_care_cost() << std::endl;
  }

  int get_care_cost() override {
    int base_cost = Animal::get_care_cost();
    int indoor_cost = is_indoor ? 15 : 5;
    return base_cost + indoor_cost + 25; // Cat-specific costs
  }

  // Cat-specific functions
  void climb() { std::cout << name << " climbs up the tree" << std::endl; }

  void use_litter_box() {
    if (is_indoor) {
      std::cout << name << " uses the litter box" << std::endl;
    } else {
      std::cout << name << " goes outside" << std::endl;
    }
  }
};

// Container class: Zoo
class Zoo {
private:
  int capacity;
  int current_count;
  Animal **animals;

public:
  Zoo(int capacity) : capacity(capacity), current_count(0) {
    animals = new Animal *[capacity];
    std::cout << "Zoo created with capacity: " << capacity << std::endl;
  }

  void add_animal(Animal *animal) {
    if (current_count < capacity) {
      animals[current_count] = animal;
      current_count++;
      std::cout << "Added animal to zoo!" << std::endl;
    } else {
      std::cout << "Zoo is full!" << std::endl;
    }
  }

  void print_all_animals() {
    std::cout << "\n=== Zoo Animal Report ===" << std::endl;
    int total_cost = 0;

    for (int i = 0; i < current_count; i++) {
      animals[i]->print_info(); // Polymorphism in action!
      total_cost += animals[i]->get_care_cost();
    }

    std::cout << "Total care cost: $" << total_cost << std::endl;
  }

  void make_all_sounds() {
    std::cout << "\n=== Animal Sounds ===" << std::endl;
    for (int i = 0; i < current_count; i++) {
      animals[i]->make_sound(); // Polymorphism!
    }
  }

  void special_activities() {
    std::cout << "\n=== Special Activities ===" << std::endl;

    for (int i = 0; i < current_count; i++) {
      // Downcasting with dynamic_cast
      Dog *dog = dynamic_cast<Dog *>(animals[i]);
      if (dog) {
        std::cout << "Dog activities: ";
        dog->fetch();
        dog->sit();
      }

      Cat *cat = dynamic_cast<Cat *>(animals[i]);
      if (cat) {
        std::cout << "Cat activities: ";
        cat->climb();
        cat->use_litter_box();
      }
    }
  }

  int get_animal_count() const { return current_count; }

  // Destructor
  ~Zoo() {
    std::cout << "\nZoo cleanup:" << std::endl;
    for (int i = 0; i < current_count; i++) {
      delete animals[i]; // Virtual destructor ensures proper cleanup
    }
    delete[] animals;
    std::cout << "Zoo destroyed" << std::endl;
  }
};

// Demonstration functions
void demonstrate_inheritance() {
  std::cout << "\n=== Inheritance Demonstration ===" << std::endl;

  Animal generic_animal("Generic", 5, "Unknown");
  Dog my_dog("Buddy", 3, "Golden Retriever", true);
  Cat my_cat("Whiskers", 2, true);

  // All are animals (is-a relationship)
  Animal *animals[3] = {&generic_animal, &my_dog, &my_cat};

  for (int i = 0; i < 3; i++) {
    animals[i]->make_sound(); // Different sounds due to virtual functions
  }
}

void demonstrate_casting() {
  std::cout << "\n=== Casting Demonstration ===" << std::endl;

  Dog original_dog("Max", 4, "German Shepherd", true);

  // Upcasting (safe)
  Animal *animal_ptr = &original_dog;
  std::cout << "After upcasting:" << std::endl;
  animal_ptr->make_sound(); // Still calls Dog's make_sound due to virtual

  // Downcasting with dynamic_cast (safe)
  Dog *dog_ptr = dynamic_cast<Dog *>(animal_ptr);
  if (dog_ptr) {
    std::cout << "Successful downcast! Dog can fetch:" << std::endl;
    dog_ptr->fetch();
  }

  // Trying to cast to wrong type
  Cat *cat_ptr = dynamic_cast<Cat *>(animal_ptr);
  if (!cat_ptr) {
    std::cout << "Cannot cast dog to cat (correctly failed)" << std::endl;
  }
}

void demonstrate_copy_constructor() {
  std::cout << "\n=== Copy Constructor Demonstration ===" << std::endl;

  Dog original("Rocky", 5, "Bulldog", false);
  Dog copied = original; // Copy constructor called

  std::cout << "Original: ";
  original.print_info();
  std::cout << "Copied: ";
  copied.print_info();
}

int main() {
  std::cout << "=== Advanced C++ Features Demonstration ===" << std::endl;

  // Create zoo
  Zoo my_zoo(10);

  // Add various animals (demonstrates inheritance and polymorphism)
  my_zoo.add_animal(new Dog("Rex", 3, "Labrador", true));
  my_zoo.add_animal(new Dog("Spot", 2, "Dalmatian", false));
  my_zoo.add_animal(new Cat("Fluffy", 4, true));
  my_zoo.add_animal(new Cat("Shadow", 1, false));
  my_zoo.add_animal(new Animal("Mystery", 10, "Unknown Species"));

  // Demonstrate virtual functions and polymorphism
  my_zoo.print_all_animals();
  my_zoo.make_all_sounds();

  // Demonstrate dynamic_cast and downcasting
  my_zoo.special_activities();

  // Other demonstrations
  demonstrate_inheritance();
  demonstrate_casting();
  demonstrate_copy_constructor();

  std::cout << "\nProgram ending..." << std::endl;
  return 0;
  // Zoo destructor will be called automatically, cleaning up all animals
}

/*
This comprehensive example demonstrates:

1. INHERITANCE (is-a relationship):
   - Dog is-a Animal, Cat is-a Animal
   - Protected members accessible in derived classes
   - Constructor chaining (base constructor called first)

2. POLYMORPHISM:
   - Virtual functions enable different behavior for same function call
   - Dynamic binding at runtime based on actual object type
   - Same interface (Animal*) with different implementations

3. VIRTUAL FUNCTIONS:
   - make_sound(), print_info(), get_care_cost() behave differently
   - Runtime decision on which function to call
   - Virtual destructor for proper cleanup

4. OVERRIDE KEYWORD:
   - Explicit indication of function overriding
   - Compile-time safety against typos

5. COPY CONSTRUCTORS:
   - Deep copying of object data
   - Proper initialization of new objects from existing ones

6. UPCASTING & DOWNCASTING:
   - Upcasting: Dog* -> Animal* (always safe)
   - Downcasting: Animal* -> Dog* (using dynamic_cast for safety)

7. DYNAMIC_CAST:
   - Safe downcasting with runtime type checking
   - Returns nullptr if cast is invalid
   - Requires polymorphic base class (with virtual functions)

8. MEMORY MANAGEMENT:
   - Dynamic allocation with new/delete
   - Virtual destructor ensures proper cleanup
   - RAII principle (Resource Acquisition Is Initialization)

9. CONTAINERS:
   - Array of base class pointers managing different derived objects
   - Unified interface for heterogeneous collection

This example shows how object-oriented design principles work together
to create flexible, maintainable, and extensible code.
*/
