#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int j = 0; j < n; j++)
      cin >> v[j];
    cout << "Class " << i + 1 << '\n';
    sort(v.begin(), v.end(), greater<>());
    int gap = v[0] - v[1];
    for (int i = 0; i < n - 1; i++)
      if (gap < v[i] - v[i + 1])
        gap = v[i] - v[i + 1];
    cout << "Max " << v[0] << ", Min " << v[n - 1] << ", Largest gap " << gap << '\n';
  }
  return 0;
}