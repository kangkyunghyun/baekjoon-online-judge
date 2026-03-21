#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, ans = 0;
  cin >> n >> m;
  string IOI = "I", s;
  while (n--)
    IOI += "OI";
  cin >> s;
  int index = 0, findIndex = s.find(IOI);
  while (findIndex != string::npos) {
    ans++;
    index = findIndex + 1;
    findIndex = s.find(IOI, index);
  }
  cout << ans << '\n';
  return 0;
}