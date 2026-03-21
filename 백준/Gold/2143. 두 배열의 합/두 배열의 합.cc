#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T, n, m;
  int A[1001], B[1001];
  cin >> T >> n;
  for (int i = 0; i < n; i++)
    cin >> A[i];
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> B[i];
  vector<int> aSum, bSum;
  for (int i = 0; i < n; i++) {
    int sum = A[i];
    aSum.push_back(sum);
    for (int j = i + 1; j < n; j++) {
      sum += A[j];
      aSum.push_back(sum);
    }
  }
  for (int i = 0; i < m; i++) {
    int sum = B[i];
    bSum.push_back(sum);
    for (int j = i + 1; j < m; j++) {
      sum += B[j];
      bSum.push_back(sum);
    }
  }
  sort(bSum.begin(), bSum.end());
  long long ans = 0;
  for (int i = 0; i < aSum.size(); i++) {
    int tmp = T - aSum[i];
    int u = upper_bound(bSum.begin(), bSum.end(), tmp) - bSum.begin();
    int l = lower_bound(bSum.begin(), bSum.end(), tmp) - bSum.begin();
    ans += u - l;
  }
  cout << ans;
  return 0;
}