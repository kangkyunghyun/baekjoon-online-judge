#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  getline(cin, s);
  if (s.find('U') != string::npos) {
    int idx = s.find('U');
    if (s.find('C', idx) != string::npos) {
      idx = s.find('C', idx);
      if (s.find('P', idx) != string::npos) {
        idx = s.find('P', idx);
        if (s.find('C', idx) != string::npos) {
          cout << "I love UCPC";
          return 0;
        }
      }
    }
  }
  cout << "I hate UCPC";
  return 0;
}