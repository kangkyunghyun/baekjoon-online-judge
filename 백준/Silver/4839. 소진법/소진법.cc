#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int n;
    cin >> n;
    int origin = n;
    if (!n)
      break;
    vector<int> prime;
    for (int i = 2; i <= 23; i++)
      if (isPrime(i))
        prime.push_back(i);
    vector<int> v;
    int now = 1;
    for (int i = 0; i < prime.size(); i++) {
      now *= prime[i];
      v.push_back(now);
    }
    vector<string> ans;
    for (int i = v.size() - 1; i >= 0; i--) {
      if (v[i] <= n) {
        int cnt = n / v[i];
        n %= v[i];
        string tmp = to_string(cnt);
        for (int j = 0; j <= i; j++) {
          tmp += "*" + to_string(prime[j]);
        }
        ans.push_back(tmp);
      }
    }
    cout << origin << " = ";
    if (n > 0)
      cout << n;
    for (int i = ans.size() - 1; i >= 0; i--) {
      if (i != ans.size() - 1 || n > 0)
        cout << " + ";
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}