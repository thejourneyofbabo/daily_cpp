// Using switch
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int user_input;
  cout << "Info of myself" << endl;
  cout << "1. Name" << endl;
  cout << "2. Age" << endl;
  cout << "3. Sex" << endl;
  cin >> user_input;

  switch (user_input) {
    case 1:
      cout << "Psi ! " << endl;
      break;

    case 2:
      cout << "99 years old" << endl;
      break;

    case 3:
      cout << "Male" << endl;
      break;

    default:
      cout << "You have lots of questions~~" << endl;
      break;
  }

  return 0;
}
