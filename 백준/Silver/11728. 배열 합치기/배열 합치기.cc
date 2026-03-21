#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[2000001];
  for (int i = 0; i < n + m; i++)
    cin >> a[i];
  sort(a, a + n + m);
  for (int i = 0; i < n + m; i++)
    cout << a[i] << " ";
  cout << '\n';
  return 0;
}