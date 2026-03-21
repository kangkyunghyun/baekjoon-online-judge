#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, cnt = 1, sum = 0;
  cin >> a >> b;
  vector<int> v;
  for (int i = 0; v.size() < b; i++) {
    for (int j = 0; j < cnt; j++)
      v.push_back(cnt);
    cnt++;
  }
  for (int i = a - 1; i < b; i++)
    sum += v[i];
  cout << sum;
  return 0;
}