#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  cin >> m >> n;
  map<char, string> dict{{'0', "zero"}, {'1', "one"}, {'2', "two"}, {'3', "three"}, {'4', "four"}, {'5', "five"}, {'6', "six"}, {'7', "seven"}, {'8', "eight"}, {'9', "nine"}};
  vector<pair<int, string>> v;
  for (int i = m; i <= n; i++) {
    string num = to_string(i);
    string item = "";
    for (char c : num)
      item += dict[c] + ' ';
    v.push_back(make_pair(i, item));
  }
  sort(v.begin(), v.end(), compare);
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first;
    cnt++;
    if (cnt % 10 == 0)
      cout << '\n';
    else
      cout << ' ';
  }
  return 0;
}