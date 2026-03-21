#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int INF = INT_MAX;
  vector<pair<int, int>> v(4);
  int min_x = INF, min_y = INF, max_x = INF, max_y = INF;
  for (int i = 0; i < 4; i++) {
    cin >> v[i].first >> v[i].second;
    if (min_x == INF)
      min_x = v[i].first;
    else
      min_x = min(min_x, v[i].first);
    if (min_y == INF)
      min_y = v[i].second;
    else
      min_y = min(min_y, v[i].second);
    if (max_x == INF)
      max_x = v[i].first;
    else
      max_x = max(max_x, v[i].first);
    if (max_y == INF)
      max_y = v[i].second;
    else
      max_y = max(max_y, v[i].second);
  }
  ll x1 = max_x + min_x;
  ll y1 = max_y + min_y;
  min_x = INF, min_y = INF, max_x = INF, max_y = INF;
  for (int i = 0; i < 4; i++) {
    cin >> v[i].first >> v[i].second;
    if (min_x == INF)
      min_x = v[i].first;
    else
      min_x = min(min_x, v[i].first);
    if (min_y == INF)
      min_y = v[i].second;
    else
      min_y = min(min_y, v[i].second);
    if (max_x == INF)
      max_x = v[i].first;
    else
      max_x = max(max_x, v[i].first);
    if (max_y == INF)
      max_y = v[i].second;
    else
      max_y = max(max_y, v[i].second);
  }
  ll x2 = max_x + min_x;
  ll y2 = max_y + min_y;
  ll p = y2 - y1;
  ll q = x2 - x1;
  ll g = gcd(p, q);
  p /= g;
  q /= g;
  if (p < 0 && q < 0) {
    p *= -1;
    q *= -1;
  } else if (p > 0 && q < 0) {
    p *= -1;
    q *= -1;
  }
  if (q == 1) {
    cout << p << ' ';
  } else {
    cout << p << '/' << q << ' ';
  }
  p = p * -x1 + y1 * q;
  q *= 2;
  g = gcd(p, q);
  p /= g;
  q /= g;
  if (p < 0 && q < 0) {
    p *= -1;
    q *= -1;
  } else if (p > 0 && q < 0) {
    p *= -1;
    q *= -1;
  }
  if (q == 1) {
    cout << p;
  } else {
    cout << p << '/' << q;
  }
  return 0;
}