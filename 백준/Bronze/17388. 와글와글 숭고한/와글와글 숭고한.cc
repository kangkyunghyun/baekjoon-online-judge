#include <bits/stdc++.h>
using namespace std;

int main() {
  int s, k, h;
  cin >> s >> k >> h;
  if (s + k + h >= 100) {
    cout << "OK";
  } else {
    string ans = "Soongsil";
    int n = s;
    if (n > k) {
      n = k;
      ans = "Korea";
    }
    if (n > h) {
      n = h;
      ans = "Hanyang";
    }
    cout << ans;
  }
  return 0;
}