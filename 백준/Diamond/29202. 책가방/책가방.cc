#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, ans = LLONG_MAX;
struct Node {
  ll w, v, t;
};
vector<ll> bag, answer;
int visited[200001] = {0};
vector<Node> vec;

void dfs(ll depth) {
  if (depth >= k) {
    ll S = 0, M = 0, m = LLONG_MAX;
    for (ll i : bag) {
      S += vec[i].w;
      M = max(M, vec[i].v);
      m = min(m, vec[i].t);
    }
    if (ans > S + M + m) {
      ans = S + M + m;
      answer = bag;
    }
    return;
  }
  for (ll i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      bag.push_back(i);
      dfs(depth + 1);
      bag.pop_back();
      visited[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  vec.resize(n + 1);
  for (ll i = 0; i < n; i++)
    cin >> vec[i].w >> vec[i].v >> vec[i].t;
  dfs(0);
  cout << ans << '\n';
  for (ll i : answer)
    cout << i + 1 << ' ';
  return 0;
}