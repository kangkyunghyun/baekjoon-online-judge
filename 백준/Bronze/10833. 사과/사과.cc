#include <iostream>
using namespace std;

int main() {
  int n, result = 0, student, apple;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> student >> apple;
    result += apple % student;
  }
  cout << result << '\n';
  return 0;
}