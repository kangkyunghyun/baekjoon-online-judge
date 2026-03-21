#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> num(n);
  vector<double> v;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  for (char c : s) {
    if (c == '+') {
      double a = v.back();
      v.pop_back();
      double b = v.back();
      v.pop_back();
      v.push_back(a + b);
    } else if (c == '-') {
      double a = v.back();
      v.pop_back();
      double b = v.back();
      v.pop_back();
      v.push_back(b - a);
    } else if (c == '*') {
      double a = v.back();
      v.pop_back();
      double b = v.back();
      v.pop_back();
      v.push_back(a * b);
    } else if (c == '/') {
      double a = v.back();
      v.pop_back();
      double b = v.back();
      v.pop_back();
      v.push_back(b / a);
    } else {
      v.push_back(num[(int)c - 65]);
    }
  }
  cout.precision(2);
  cout << fixed << v.front();
  return 0;
}