#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    double sum = 0;
    while (x--) {
      string s;
      int a;
      double b;
      cin >> s >> a >> b;
      sum += b * a;
    }
    cout.precision(2);
    cout << '$' << fixed << round(sum * 100) / 100 << '\n';
  }
  return 0;
}