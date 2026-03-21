#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> v;
  for (char c : s) {
    if (c == '+') {
      int a = v.back();
      v.pop_back();
      int b = v.back();
      v.pop_back();
      v.push_back(a + b);
    } else if (c == '-') {
      int a = v.back();
      v.pop_back();
      int b = v.back();
      v.pop_back();
      v.push_back(b - a);
    } else if (c == '*') {
      int a = v.back();
      v.pop_back();
      int b = v.back();
      v.pop_back();
      v.push_back(a * b);
    } else if (c == '/') {
      int a = v.back();
      v.pop_back();
      int b = v.back();
      v.pop_back();
      v.push_back(b / a);
    } else {
      v.push_back(c - '0');
    }
  }
  cout << v.front();
  return 0;
}