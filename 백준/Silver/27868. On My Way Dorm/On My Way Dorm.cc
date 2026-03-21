#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, s;
  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  string cmd;
  cin >> cmd;
  reverse(cmd.begin(), cmd.end());
  cout << cmd;
  return 0;
}