#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, float> a, pair<string, float> b) {
  return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (1) {
    cin >> n;
    if (n == 0)
      break;
    vector<pair<string, float>> v;
    string name;
    float height;
    for (int i = 0; i < n; i++) {
      cin >> name >> height;
      v.push_back(make_pair(name, height));
    }
    stable_sort(v.begin(), v.end(), compare);
    float max = v[0].second;
    for (auto i : v)
      if (i.second == max)
        cout << i.first << ' ';
    cout << '\n';
  }
  return 0;
}