#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l, q;
  cin >> n;
  vector<int> length(n + 1), prefix_sum(n + 1, 0);
  vector<double> coordinate(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> length[i];
    prefix_sum[i] = length[i] + prefix_sum[i - 1];
    coordinate[i] = prefix_sum[i] - (double)length[i] / 2;
  }
  cin >> l >> q;
  cout.precision(2);
  cout << fixed;
  double mid = (double)l / 2;
  while (q--) {
    int x;
    cin >> x;
    double gap = mid - coordinate[x];
    if (gap >= 0 || prefix_sum[n] < l)
      cout << (double)0;
    else if ((double)prefix_sum[n] - coordinate[x] < (double)l / 2)
      cout << (double)prefix_sum[n] - l;
    else
      cout << -gap;
    cout << '\n';
  }
  return 0;
}