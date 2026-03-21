#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<pair<string, char>> v;
  int arr[] = {10, 8, 6, 5, 4, 3, 2, 1};
  for (int i = 0; i < 8; i++) {
    string s;
    char t;
    cin >> s >> t;
    v.push_back({s, t});
  }
  sort(v.begin(), v.end());
  int R = 0, B = 0;
  int size = v.size();
  for (int i = 0; i < 8; i++)
    if (v[i].second == 'R')
      R += arr[i];
    else
      B += arr[i];
  cout << (R > B ? "Red\n" : "Blue\n");
  return 0;
}