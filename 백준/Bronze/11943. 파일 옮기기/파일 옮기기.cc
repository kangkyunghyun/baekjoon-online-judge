#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int case1 = a + d, case2 = b + c;
  if (case1 >= case2)
    cout << case2;
  else
    cout << case1;
  return 0;
}