#include <bits/stdc++.h>
using namespace std;

int check(int n) {
  string s = to_string(n);
  for (int i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - 1 - i])
      return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> sieve(10000001, 1), prime;
  for (int i = 2; i <= 10000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 10000000; j += i)
        sieve[j] = 0;
    }
  for (int i : prime)
    if (i >= n && check(i)) {
      cout << i;
      return 0;
    }
  return 0;
}