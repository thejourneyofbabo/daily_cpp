#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
int main() {
  vector<int> A;
  A.push_back(10);
  A.push_back(30);
  A.push_back(5);
  A.push_back(8);
  A.push_back(8);

  A.push_back(1);
  A.insert(A.begin(), 7);
  A.insert(A.begin() + 2, 10);

  A[4] = -5;

  A.pop_back();
  A.erase(A.begin() + 3);

  cout << A.size() << endl;
  cout << A.front() << endl;
  cout << A.back() << endl;
  cout << A[3] << endl;
  cout << A.at(5) << endl;
}
