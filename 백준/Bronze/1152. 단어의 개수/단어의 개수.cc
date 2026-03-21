#include <iostream>
#include <string>
using namespace std;

int main() {
  string a;
  int cnt = 0;
  getline(cin, a);
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == ' ') {
      cnt++;
    }
  }
  if (a[0] == ' ') {
    cnt--;
  }
  if (a[a.length() - 1] == ' ') {
    cnt--;
  }
  cout << cnt + 1 << '\n';
  return 0;
}