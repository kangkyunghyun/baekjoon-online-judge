#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, x;
    cin >> n >> m >> k;
    int a_min = 1e18, a_max = 0, a_sum = 0;
    int b_min = 1e18, b_max = 0, b_sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a_min = min(a_min, x);
      a_max = max(a_max, x);
      a_sum += x;
    }
    for (int i = 0; i < m; i++) {
      cin >> x;
      b_min = min(b_min, x);
      b_max = max(b_max, x);
      b_sum += x;
    }
    int total_max = max(a_max, b_max);
    int total_min = min(a_min, b_min);
    if (a_min < b_max) {
      if (a_max >= b_max && a_min >= b_min) {
        if (k % 2) {
          cout << a_sum - a_min + b_max;
        } else {
          cout << a_sum - a_max - a_min + b_max + b_min;
        }
      } else if (a_max >= b_max && a_min < b_min) {
        if (k % 2) {
          cout << a_sum - a_min + b_max;
        } else {
          cout << a_sum - a_max + b_max;
        }
      } else if (a_max < b_max && a_min < b_min) {
        if (k % 2) {
          cout << a_sum - a_min + b_max;
        } else {
          cout << a_sum;
        }
      } else if (a_max < b_max && a_min >= b_min) {
        if (k % 2) {
          cout << a_sum - a_min + b_max;
        } else {
          cout << a_sum - a_min + b_min;
        }
      }
    } else {
      if (k % 2) {
        cout << a_sum;
      } else {
        cout << a_sum - a_max + b_min;
      }
    }
    cout << '
';
  }
}