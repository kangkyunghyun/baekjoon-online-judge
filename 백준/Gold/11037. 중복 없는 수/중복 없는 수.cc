#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  while (cin >> n) {
    int flag = 0;
    for (int i = n + 1; i <= 999999999; i++) {
      string num = to_string(i);
      if (num.find('0') == string::npos) {
        vector<int> check(10, 0);
        for (int j = 0; j < num.size(); j++) {
          int a = num[j] - '0';
          if (check[a] >= 1)
            break;
          else
            check[a]++;

          if (j == num.size() - 1) {
            cout << num << '\n';
            flag = 1;
            break;
          }
        }
      }
      if (flag)
        break;
    }
    if (!flag)
      cout << 0 << '\n';
  }
  return 0;
}