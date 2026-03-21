#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  string s;
  cin >> n >> s;
  cin.ignore();
  int idx = s.find('*');
  string front = s.substr(0, idx);
  string back = s.substr(idx + 1, s.size() - idx + 1);
  while (n--) {
    getline(cin, s);
    if (s.find(front) == 0 && s.find(back, s.size() - back.size()) == s.size() - back.size()) {
      if (front.size() - 1 >= s.size() - back.size())
        cout << "NE\n";
      else
        cout << "DA\n";
    } else
      cout << "NE\n";
  }
  return 0;
}