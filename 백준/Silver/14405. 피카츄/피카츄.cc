#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str.find("pi") != string::npos) {
      int index = str.find("pi");
      str[index] = '*';
      str[index + 1] = '*';
    }
    if (str.find("ka") != string::npos) {
      int index = str.find("ka");
      str[index] = '*';
      str[index + 1] = '*';
    }
    if (str.find("chu") != string::npos) {
      int index = str.find("chu");
      str[index] = '*';
      str[index + 1] = '*';
      str[index + 2] = '*';
    }
  }
  int cnt = 0;
  for (int i = 0; i < str.length(); i++)
    if (str[i] == '*')
      cnt++;
  if (cnt == str.length())
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
  return 0;
}