#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<string> a{
      "Never gonna give you up",
      "Never gonna let you down",
      "Never gonna run around and desert you",
      "Never gonna make you cry",
      "Never gonna say goodbye",
      "Never gonna tell a lie and hurt you",
      "Never gonna stop",
  };
  int n;
  cin >> n;
  bool flag = 0;
  cin.ignore();
  while (n--) {
    string s;
    getline(cin, s);
    if (find(a.begin(), a.end(), s) == a.end())
      flag = 1;
  }
  if (flag)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}