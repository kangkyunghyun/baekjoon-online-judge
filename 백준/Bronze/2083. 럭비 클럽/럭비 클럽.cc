#include <bits/stdc++.h>
using namespace std;

int main() {
  string name;
  int age, kg;
  while (cin >> name >> age >> kg) {
    if (name == "#" && age == 0 && kg == 0)
      break;
    if (age > 17 || kg >= 80)
      cout << name << " Senior" << '\n';
    else
      cout << name << " Junior" << '\n';
  }
  return 0;
}