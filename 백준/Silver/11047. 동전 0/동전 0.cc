#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, x, sum = 0, cnt = 0;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  while (k > 0) {
    int temp = k / v.back();
    if (temp > 0) {
      k -= v.back() * (temp);
      cnt += temp;
    }
    v.erase(v.end() - 1);
  }
  cout << cnt;
  return 0;
}