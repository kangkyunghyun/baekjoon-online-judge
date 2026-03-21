#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n), a, b;
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int next = 1;
  while (a.size() != n) {
    if (!v.empty()) {
      if (v.front() == next) {
        a.push_back(v.front());
        v.erase(v.begin());
        next++;
      } else if (!b.empty() && b.back() == next) {
        a.push_back(b.back());
        b.pop_back();
        next++;
      } else {
        b.push_back(v.front());
        v.erase(v.begin());
      }
    } else {
      if (b.back() == next) {
        a.push_back(b.back());
        b.pop_back();
        next++;
      } else {
        break;
      }
    }
  }
  if (a.size() == n)
    cout << "Nice";
  else
    cout << "Sad";
  return 0;
}