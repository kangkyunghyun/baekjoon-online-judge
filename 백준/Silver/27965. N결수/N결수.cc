#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  string s = "0";
  for (int i = 1; i <= n; i++) {
    s += to_string(i);
    long long num = stoll(s);
    num %= k;
    s = to_string(num);
  }
  cout << s;
  return 0;
}