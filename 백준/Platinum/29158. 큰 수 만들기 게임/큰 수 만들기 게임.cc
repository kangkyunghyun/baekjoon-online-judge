#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

bool cmp(string a, string b) {
  string ab = a + b;
  string ba = b + a;
  return ab > ba;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, t;
  cin >> n;
  t = n - 1;
  vector<string> v;
  for (ll i = 2; i * i <= n; i++)
    while (n % i == 0) {
      v.push_back(to_string(i));
      n /= i;
    }
  if (n > 1)
    v.push_back(to_string(n));
  sort(v.begin(), v.end(), cmp);
  string a = "", b = "";
  for (string i : v)
    a += i;
  v.clear();
  while (t > 3) {
    v.push_back("2");
    t /= 2;
  }
  v.push_back(to_string(t));
  sort(v.begin(), v.end(), cmp);
  for (string i : v)
    b += i;
  if (a.size() > b.size()) {
    string tmp = "";
    while (tmp.size() < a.size() - b.size())
      tmp += '0';
    b = tmp + b;
  } else {
    string tmp = "";
    while (tmp.size() < b.size() - a.size())
      tmp += '0';
    a = tmp + a;
  }
  vector<int> ans(a.size() + 1, 0);
  for (int i = a.size() - 1; i >= 0; i--) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    if (x + y + ans[i + 1] < 10) {
      ans[i + 1] = x + y + ans[i + 1];
    } else {
      ans[i] = 1;
      ans[i + 1] = x + y + ans[i + 1] - 10;
    }
  }
  if (ans[0])
    for (int i : ans)
      cout << i;
  else
    for (int i = 1; i < ans.size(); i++)
      cout << ans[i];
  return 0;
}