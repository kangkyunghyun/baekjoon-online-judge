#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
  return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, w, h;
  cin >> n;
  vector<pair<int, double>> v;
  for (int i = 0; i < n; i++) {
    cin >> w >> h;
    double ppi = pow(w * w + h * h, 0.5) / 77;
    v.push_back(make_pair(i + 1, ppi));
  }
  stable_sort(v.begin(), v.end(), compare);
  for (auto i : v)
    cout << i.first << '\n';
  return 0;
}