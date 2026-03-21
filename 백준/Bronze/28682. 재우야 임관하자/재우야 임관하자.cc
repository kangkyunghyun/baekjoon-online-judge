#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string a[] = {"swimming", "bowling", "soccer"};
  for (int i = 0; i < n; i++)
    cout << a[i % 3] << ' ';
  cout << endl;
  vector<string> ans;
  for (int i = 0; i < n; i++) {
    string res;
    cin >> res;
    if (res == a[0]) {
      if (i % 3 == 1)
        ans.push_back(a[2]);
      else
        ans.push_back(a[1]);
    } else if (res == a[1]) {
      if (i % 3 == 0)
        ans.push_back(a[2]);
      else
        ans.push_back(a[0]);
    } else {
      if (i % 3 == 0)
        ans.push_back(a[1]);
      else
        ans.push_back(a[0]);
    }
  }
  for (string s : ans)
    cout << s << ' ';
  cout << endl;
  return 0;
}