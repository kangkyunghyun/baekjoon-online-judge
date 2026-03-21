#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'K') {
      if (s.find('O', i) != string::npos) {
        int idx = s.find('O', i);
        if (s.find('R', idx) != string::npos) {
          idx = s.find('R', idx);
          if (s.find('E', idx) != string::npos) {
            idx = s.find('E', idx);
            if (s.find('A', idx) != string::npos) {
              cout << "KOREA";
              return 0;
            }
          }
        }
      }
    }
    if (s[i] == 'Y') {
      if (s.find('O', i) != string::npos) {
        int idx = s.find('O', i);
        if (s.find('N', idx) != string::npos) {
          idx = s.find('N', idx);
          if (s.find('S', idx) != string::npos) {
            idx = s.find('S', idx);
            if (s.find('E', idx) != string::npos) {
              idx = s.find('E', idx);
              if (s.find('I', idx) != string::npos) {
                cout << "YONSEI";
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}