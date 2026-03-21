#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n.length(); i++)
    sum += n[i] - '0';
  sort(n.begin(), n.end(), greater<>());
  if (n[n.length() - 1] == '0' && sum % 3 == 0)
    cout << n << '\n';
  else
    cout << -1 << '\n';
  return 0;
}