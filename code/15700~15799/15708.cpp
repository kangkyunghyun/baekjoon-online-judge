#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, t, p, sum = 0, ans = 0;
  cin >> n >> t >> p;
  priority_queue<ll> pq;
  for (int i = 0; i < n; i++) {
    ll k;
    cin >> k;
    sum += k;
    pq.push(k);
    while (!pq.empty() && sum + i * p > t) {
      sum -= pq.top();
      pq.pop();
    }
    ans = max(ans, (ll)pq.size());
  }
  cout << ans;
  return 0;
}