#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<pair<string, char>> v;
  int arr[] = {10, 8, 6, 5, 4, 3, 2, 1};
  string s;
  while (cin >> s) {
    char t;
    cin >> t;
    v.push_back({s, t});
  }
  int R = 0, B = 0;
  sort(v.begin(), v.end());
  int size = v.size();
  for (int i = 0; i < min(size, 8); i++)
    if (v[i].second == 'R')
      R += arr[i];
    else
      B += arr[i];
  cout << (R > B ? "Red\n" : "Blue\n");
  return 0;
}