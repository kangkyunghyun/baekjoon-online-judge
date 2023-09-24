#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pll> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].second;
  for (int i = 0; i < n; i++)
    cin >> v[i].first;
  sort(v.begin(), v.end());
  ll ans = v[0].second;
  priority_queue<ll> pq;
  for (int i = 1; i < n - 1; i += 2) {
    pq.push(v[i].second);
    pq.push(v[i + 1].second);
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
  return 0;
}