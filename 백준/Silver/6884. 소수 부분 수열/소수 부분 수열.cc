#include <bits/stdc++.h>
using namespace std;

int isPrime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
      return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, tmp = 0;
    cin >> n;
    vector<int> v(n), sum;
    sum.push_back(0);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      tmp += v[i];
      sum.push_back(tmp);
    }
    int size = 2, flag = 0;
    while (size <= n) {
      for (int i = 1, j = i + size - 1; j <= n; i++, j++) {
        int s = sum[j] - sum[i - 1];
        if (isPrime(s)) {
          cout << "Shortest primed subsequence is length " << size << ": ";
          for (int k = i - 1; k < j; k++)
            cout << v[k] << ' ';
          cout << '\n';
          flag = 1;
          break;
        }
      }
      if (flag)
        break;
      size++;
    }
    if (!flag)
      cout << "This sequence is anti-primed.\n";
  }
  return 0;
}