#include <bits/stdc++.h>
using namespace std;

int main() {
  double sum = 0, p = 0;
  for (int i = 0; i < 20; i++) {
    string name, grade;
    double point;
    cin >> name >> point >> grade;
    if (grade == "A+") {
      sum += point * 4.5;
      p += point;
    } else if (grade == "A0") {
      sum += point * 4.0;
      p += point;
    } else if (grade == "B+") {
      sum += point * 3.5;
      p += point;
    } else if (grade == "B0") {
      sum += point * 3.0;
      p += point;
    } else if (grade == "C+") {
      sum += point * 2.5;
      p += point;
    } else if (grade == "C0") {
      sum += point * 2.0;
      p += point;
    } else if (grade == "D+") {
      sum += point * 1.5;
      p += point;
    } else if (grade == "D0") {
      sum += point * 1.0;
      p += point;
    } else if (grade == "F")
      p += point;
  }
  cout.precision(6);
  cout << fixed << sum / p << '\n';
  return 0;
}