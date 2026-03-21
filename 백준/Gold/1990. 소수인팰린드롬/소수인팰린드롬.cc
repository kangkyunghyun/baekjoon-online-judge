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
  cin.tie(NULL), cout.tie(NULL);
  vector<int> palindrome;
  for (int i = 1; i <= 10000; i++) {
    string s = to_string(i);
    string num = s;
    for (int j = s.size() - 2; j >= 0; j--)
      num += s[j];
    palindrome.push_back(stoi(num));
    num = s;
    for (int j = s.size() - 1; j >= 0; j--)
      num += s[j];
    palindrome.push_back(stoi(num));
  }
  sort(palindrome.begin(), palindrome.end());
  int a, b;
  cin >> a >> b;
  for (int i : palindrome)
    if (i >= a && i <= b && isPrime(i))
      cout << i << '\n';
  cout << -1;
  return 0;
}