#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int cnt = 0;
    for (int j = 0; j < str.length() - 1; j++)
      if (str[j] != str[j + 1]) {
        string str1 = str.substr(j + 1, str.length() - j - 1);
        int error = count(str1.begin(), str1.end(), str[j]);
        if (error != 0)
          cnt++;
      }
    if (cnt == 0)
      ans++;
  }
  cout << ans << '\n';
  return 0;
}