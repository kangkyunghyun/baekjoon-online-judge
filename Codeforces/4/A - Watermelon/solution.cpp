#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int w;
  cin >> w;
  if (w == 2)
    cout << "NO";
  else if (w % 2)
    cout << "NO";
  else
    cout << "YES";
}