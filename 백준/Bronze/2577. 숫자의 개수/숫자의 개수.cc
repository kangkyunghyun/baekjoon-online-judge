#include <iostream>
#include <string>
using namespace std;

int main() {
  int a, b, c, cnt = 0;
  string str;
  int arr[10] = {0};
  cin >> a >> b >> c;
  str = to_string(a * b * c);
  for (int i = 0; i < 10; i++) {
    cnt = 0;
    char k = char(i + 48);
    for (int j = 0; j < str.length(); j++) {
      if (k == str[j]) {
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}