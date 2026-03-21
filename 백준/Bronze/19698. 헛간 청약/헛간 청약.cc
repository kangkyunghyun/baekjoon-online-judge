#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w, h, l;
  cin >> n >> w >> h >> l;
  if ((w / l) * (h / l) > n)
    cout << n << '\n';
  else
    cout << (w / l) * (h / l) << '\n';
  return 0;
}