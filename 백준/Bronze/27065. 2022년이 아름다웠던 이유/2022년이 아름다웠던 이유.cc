#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
  vector<int> v;
  for (int i = 1; i <= n; i++)
    if (n % i == 0)
      v.push_back(i);
  int sum = 0;
  for (int i = 0; i < v.size() - 1; i++)
    sum += v[i];
  if (sum > n)
    return true;
  else
    return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
      if (n % i == 0)
        v.push_back(i);
    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++)
      sum += v[i];
    if (sum <= n) {
      cout << "BOJ 2022\n";
    } else {
      int cnt = 0;
      for (int i = 0; i < v.size() - 1; i++)
        if (!check(v[i]))
          cnt++;
      if (cnt == v.size() - 1)
        cout << "Good Bye\n";
      else
        cout << "BOJ 2022\n";
    }
  }
  return 0;
}