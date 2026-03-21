#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int n;
    cin >> n;
    if (!n)
      break;
    vector<int> v;
    v.push_back(n);
    int p = n * n;
    while (1) {
      string s = to_string(p);
      while (s.size() < 8) {
        string tmp = "0";
        tmp += s;
        s = tmp;
      }
      p = stoi(s.substr(2, 4));
      if (find(v.begin(), v.end(), p) != v.end()) {
        break;
      }
      v.push_back(p);
      p *= p;
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << '\n';
  }
  return 0;
}