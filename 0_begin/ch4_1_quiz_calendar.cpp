#include <iostream>

using namespace std;

class Date {
  int year_;
  int month_;
  int day_;

 public:
  void CalcDate(int day_temp, int max_day) {
    if (day_temp <= max_day) {
      day_ = day_temp;
    } else {
      month_++;
      day_ = day_temp - max_day;
    }
  }
  void SetDate(int year, int month, int date) {
    year_ = year;
    month_ = month;
    day_ = date;
  }
  void AddDay(int inc) {
    // day_ += inc;
    int day_temp = day_ + inc;

    switch (month_) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        CalcDate(day_temp, 31);
        break;
      case 2:
        CalcDate(day_temp, 28);
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        CalcDate(day_temp, 30);
        break;
    }

    if (day_temp < 29) {
      day_ = day_temp;
    } else {
    }
  }
  void AddMonth(int inc) {
    // month_ += inc;
    int month_temp = month_ + inc;
    if (month_temp > 12) {
      ++year_;
      month_ = month_temp - 12;
    } else {
      month_ = month_temp;
    }
  }
  void AddYear(int inc) { year_ += inc; }

  void ShowDate() {
    cout << year_ << "." << month_ << "." << day_ << " " << endl;
  }
};

int main() {
  Date date;
  int now_year, now_month, now_day;

  cout << "Current year: ";
  cin >> now_year;
  cout << "Current month: ";
  cin >> now_month;
  cout << "Current day: ";
  cin >> now_day;

  // date.SetDate(2025, 7, 3);
  date.SetDate(now_year, now_month, now_day);
  date.ShowDate();

  // date.AddDay(3);
  // date.ShowDate();

  cout << "Current date is: ";
  date.ShowDate();
  // cout << "After 2years, 3months, 5days.. " << endl;

  int inc_year, inc_month, inc_day;
  cout << "\nAfter nth year: ";
  cin >> inc_year;
  cout << "After nth month: ";
  cin >> inc_month;
  cout << "After nth day: ";
  cin >> inc_day;

  date.AddDay(inc_day);
  date.AddMonth(inc_month);
  date.AddYear(inc_year);

  date.ShowDate();
}
