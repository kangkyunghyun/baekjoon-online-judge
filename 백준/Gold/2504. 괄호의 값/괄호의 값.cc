#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<char> v;
  int ans = 0, temp = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      temp *= 2;
      v.push_back(s[i]);
    } else if (s[i] == '[') {
      temp *= 3;
      v.push_back(s[i]);
    } else if (s[i] == ')') {
      if (v.empty() || v.back() != '(') {
        ans = 0;
        break;
      } else if (s[i - 1] == '(') {
        ans += temp;
        temp /= 2;
        v.pop_back();
      } else {
        temp /= 2;
        v.pop_back();
      }
    } else if (s[i] == ']') {
      if (v.empty() || v.back() != '[') {
        ans = 0;
        break;
      } else if (s[i - 1] == '[') {
        ans += temp;
        temp /= 3;
        v.pop_back();
      } else {
        temp /= 3;
        v.pop_back();
      }
    }
  }
  if (!v.empty())
    ans = 0;
  cout << ans;
  return 0;
}