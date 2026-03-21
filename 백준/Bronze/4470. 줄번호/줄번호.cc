#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 1; i <= n; i++) {
    string str;
    getline(cin, str);
    cin.clear();
    cout << i << ". " << str << '\n';
  }
  return 0;
}