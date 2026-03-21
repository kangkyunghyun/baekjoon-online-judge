#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
  if (a.size() == b.size()) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
  }
  return a.size() > b.size();
}

bool compare(string a, string b) {
  string ab = a + b;
  string ba = b + a;
  return ab > ba;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int k, n, flag = 0;
  cin >> k >> n;
  vector<string> v(k), tmp;
  for (int i = 0; i < k; i++)
    cin >> v[i];
  tmp = v;
  sort(v.begin(), v.end(), cmp);
  sort(tmp.begin(), tmp.end(), compare);
  for (int i = 0; i < k; i++) {
    if (tmp[i] == v[0] && !flag) {
      for (int j = 0; j < n - k + 1; j++)
        cout << tmp[i];
      flag = 1;
    } else
      cout << tmp[i];
  }
  return 0;
}