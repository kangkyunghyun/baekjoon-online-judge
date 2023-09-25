#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<pair<int, int>> v(26);
  for (int i = 0; i < 52; i++) {
    char c;
    cin >> c;
    int curr = c - 'A';
    if (v[curr].first == 0)
      v[curr].first = i + 1;
    else
      v[curr].second = i + 1;
  }
  int cnt = 0;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      if (v[i].first < v[j].first && v[j].first < v[i].second && v[i].second < v[j].second)
        cnt++;
  cout << cnt;
  return 0;
}