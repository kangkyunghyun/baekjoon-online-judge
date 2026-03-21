#include <iostream>
using namespace std;

int main() {
  int t, score, result;
  cin >> t;
  string str;
  for (int i = 0; i < t; i++) {
    cin >> str;
    score = 0;
    result = 0;
    for (int j = 0; j < str.length(); j++) {
      if (str[j] == 'O') {
        score++;
        result += score;
      } else {
        score = 0;
      }
    }
    cout << result << '\n';
  }
  return 0;
}