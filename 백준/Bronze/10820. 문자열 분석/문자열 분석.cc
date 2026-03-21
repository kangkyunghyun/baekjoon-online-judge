#include <iostream>
using namespace std;

int main() {
  string str;
  while (getline(cin, str)) {
    int small = 0, capital = 0, num = 0, space = 0;
    for (int i = 0; i < str.length(); i++) {
      if ((int)str[i] >= 97 && (int)str[i] <= 122) {
        small++;
      } else if ((int)str[i] >= 65 && (int)str[i] <= 90) {
        capital++;
      } else if ((int)str[i] >= 48 && (int)str[i] <= 57) {
        num++;
      } else if (str[i] == ' ') {
        space++;
      }
    }
    cout << small << ' ' << capital << ' ' << num << ' ' << space << '\n';
  }
  return 0;
}