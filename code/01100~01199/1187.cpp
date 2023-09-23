#include <bits/stdc++.h>
using namespace std;
#define piv pair<int, vector<int>>

int n;

vector<piv> f(vector<piv> v, int d) {
  int size = v.size();
  vector<piv> ans;
  piv a = v[0], b, c;
  for (int i = 1; i + 1 < size; i += 2) {
    b = v[i], c = v[i + 1];
    if ((a.first + b.first) % d == 0) {
      a.second.insert(a.second.begin(), b.second.begin(), b.second.end());
      ans.push_back({a.first + b.first, {a.second}});
      a = c;
    } else if ((b.first + c.first) % d == 0) {
      b.second.insert(b.second.begin(), c.second.begin(), c.second.end());
      ans.push_back({b.first + c.first, {b.second}});
      a = a;
    } else if ((a.first + c.first) % d == 0) {
      a.second.insert(a.second.begin(), c.second.begin(), c.second.end());
      ans.push_back({a.first + c.first, {a.second}});
      a = b;
    } else {
      a = b;
      i--;
    }
  }
  if (ans.size() * ans[0].second.size() > n)
    return f(ans, 2 * d);
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vector<piv> v(2 * n - 1);
  for (int i = 0; i < 2 * n - 1; i++) {
    int x;
    cin >> x;
    v[i] = {x, {x}};
  }
  vector<piv> ans = f(v, 2);
  for (int i : ans[0].second)
    cout << i << ' ';
  return 0;
}