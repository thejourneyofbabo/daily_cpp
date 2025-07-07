#include <iostream>
#include <string>

class Employee {
protected:
  std::string name;
  int age;
  std::string position;
  int rank;

public:
  Employee(std::string name, int age, std::string position, int rank)
      : name(name), age(age), position(position), rank(rank) {
    std::cout << "Employee 일반 생성자: " << name << std::endl;
  }

  // 복사 생성자 (호출되는지 확인용 메시지 추가)
  Employee(const Employee &employee) {
    std::cout << "🔄 Employee 복사 생성자 호출: " << employee.name << std::endl;
    name = employee.name;
    age = employee.age;
    position = employee.position;
    rank = employee.rank;
  }

  Employee() { std::cout << "Employee 디폴트 생성자" << std::endl; }

  void print_info() {
    std::cout << name << " (" << position << " , " << age << ") ==> "
              << calculate_pay() << "만원" << std::endl;
  }
  int calculate_pay() { return 200 + rank * 50; }
};

class Manager : public Employee {
  int year_of_service;

public:
  Manager(std::string name, int age, std::string position, int rank,
          int year_of_service)
      : Employee(name, age, position, rank), year_of_service(year_of_service) {
    std::cout << "Manager 일반 생성자: " << name << std::endl;
  }

  // 복사 생성자 (호출되는지 확인용 메시지 추가)
  Manager(const Manager &manager)
      : Employee(manager.name, manager.age, manager.position, manager.rank) {
    std::cout << "🔄 Manager 복사 생성자 호출: " << manager.name << std::endl;
    year_of_service = manager.year_of_service;
  }

  Manager() : Employee() { std::cout << "Manager 디폴트 생성자" << std::endl; }

  int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
  void print_info() {
    std::cout << name << " (" << position << " , " << age << ", "
              << year_of_service << "년차) ==> " << calculate_pay() << "만원"
              << std::endl;
  }
};

// 복사 생성자가 사용되는 경우들을 보여주는 함수들
void showEmployee(Employee emp) { // 값으로 전달 - 복사 생성자 호출!
  std::cout << "함수 내부에서: ";
  emp.print_info();
}

Employee createEmployee() { // 값으로 반환 - 복사 생성자 호출!
  Employee temp("임시직원", 25, "임시", 0);
  return temp;
}

int main() {
  std::cout << "=== 원본 코드 실행 (복사 생성자 사용 안 됨) ===\n";

  // 원본 코드에서는 모두 포인터로 동적 할당
  // new를 사용하므로 복사 생성자가 호출되지 않음
  Employee *emp1 = new Employee("노홍철", 34, "평사원", 1);
  Employee *emp2 = new Employee("하하", 34, "평사원", 1);
  Manager *mgr1 = new Manager("유재석", 41, "부장", 7, 12);

  std::cout << "\n=== 복사 생성자가 호출되는 경우들 ===\n";

  // 경우 1: 객체를 다른 객체로 초기화
  std::cout << "\n1. 객체 복사 초기화:\n";
  Employee original("김철수", 30, "사원", 2);
  Employee copied = original; // 🔄 복사 생성자 호출!

  // 경우 2: 함수 매개변수로 전달 (값으로)
  std::cout << "\n2. 함수 매개변수로 전달:\n";
  showEmployee(original); // 🔄 복사 생성자 호출!

  // 경우 3: 함수에서 객체 반환
  std::cout << "\n3. 함수에서 객체 반환:\n";
  Employee returned = createEmployee(); // 🔄 복사 생성자 호출!

  // 경우 4: Manager도 복사해보기
  std::cout << "\n4. Manager 객체 복사:\n";
  Manager boss("이사장", 50, "이사", 10, 20);
  Manager boss_copy = boss; // 🔄 Manager 복사 생성자 호출!

  std::cout << "\n=== 원본 vs 복사본 비교 ===\n";
  std::cout << "원본: ";
  original.print_info();
  std::cout << "복사본: ";
  copied.print_info();

  // 메모리 해제 (원본 코드에서 동적 할당한 것들)
  delete emp1;
  delete emp2;
  delete mgr1;

  return 0;
}

/*
분석 결과:

❌ 원본 코드에서 복사 생성자가 사용되지 않는 이유:

1. 모든 객체가 동적 할당으로 생성됨
   new Employee(...) → 포인터로 생성, 복사 없음
   new Manager(...) → 포인터로 생성, 복사 없음

2. 객체를 직접 복사하는 코드가 없음
   Employee a = b; ← 이런 코드가 없음

3. 함수 매개변수도 포인터로 전달
   add_employee(Employee* employee) ← 포인터 전달, 복사 없음

✅ 복사 생성자가 호출되는 경우들:

1. 객체 복사 초기화: Employee b = a;
2. 함수 매개변수 (값으로): func(Employee obj)
3. 함수 반환 (값으로): return employee_obj;
4. 명시적 복사: Employee b(a);

🤔 그럼 왜 복사 생성자를 정의했을까?

1. 완전성: 클래스 설계 시 복사 기능도 제공
2. 미래 확장성: 나중에 복사가 필요할 수 있음
3. 안전성: 기본 복사 생성자보다 명확한 동작
4. 교육 목적: 복사 생성자 구현 방법 학습

💡 실제로는:
이 코드에서 복사 생성자를 제거해도 동작에는 영향 없음
하지만 좋은 클래스 설계를 위해 포함된 것으로 보임
*/
