#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
  string ab = a + b;
  string ba = b + a;
  return ab > ba;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, flag = 0;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] != "0")
      flag = 1;
  }
  if (flag) {
    sort(v.begin(), v.end(), cmp);
    for (string i : v)
      cout << i;
  } else {
    cout << 0;
  }
  return 0;
}