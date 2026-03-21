#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, tmp = 200001;
    cin >> x;
    for (int j = 0; j < x; j++) {
      int t;
      cin >> t;
      if (t < tmp)
        tmp = t;
      else {
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
  return 0;
}