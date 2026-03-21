#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    priority_queue<ll> pq;
    int n, x;
    ll ans = 0;
    cin >> n;
    while (n--) {
      cin >> x;
      pq.push(-x);
    }
    while (pq.size() != 1) {
      ll a = -pq.top();
      pq.pop();
      ll b = -pq.top();
      pq.pop();
      ans += a + b;
      pq.push(-(a + b));
    }
    cout << ans << '\n';
  }
  return 0;
}