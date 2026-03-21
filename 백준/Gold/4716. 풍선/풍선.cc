#include <bits/stdc++.h>
using namespace std;

struct team {
  int K, a, b;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int N, A, B;
    long long ans = 0;
    cin >> N >> A >> B;
    if (!N && !A && !B)
      break;
    vector<team> v(N);
    for (int i = 0; i < N; i++)
      cin >> v[i].K >> v[i].a >> v[i].b;
    sort(v.begin(), v.end(), [](team a, team b) { return abs(a.a - a.b) > abs(b.a - b.b); });
    for (int i = 0; i < N; i++) {
      int K = v[i].K, a = v[i].a, b = v[i].b;
      int m = a > b ? 0 : 1;
      if (m) {
        if (A >= K) {
          ans += K * a;
          A -= K;
        } else {
          ans += A * a;
          K -= A;
          A = 0;
          ans += K * b;
          B -= K;
        }
      } else {
        if (B >= K) {
          ans += K * b;
          B -= K;
        } else {
          ans += B * b;
          K -= B;
          B = 0;
          ans += K * a;
          A -= K;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}