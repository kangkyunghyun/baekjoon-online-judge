#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 65 && s[i] <= 90)
        s[i] += 32;
    }
    cout << s << '\n';
  }
  return 0;
}