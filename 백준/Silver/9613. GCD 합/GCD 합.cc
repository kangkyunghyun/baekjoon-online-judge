#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    vector<int> arr;
    int n, a;
    long long sum = 0;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a;
      arr.push_back(a);
    }
    for (int j = 0; j < arr.size(); j++)
      for (int k = j + 1; k < arr.size(); k++)
        sum += gcd(arr[j], arr[k]);
    cout << sum << '\n';
  }
  return 0;
}