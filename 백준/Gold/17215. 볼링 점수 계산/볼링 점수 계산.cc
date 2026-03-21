#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int frame = 0, ans = 0, check = 0;
  string str;
  cin >> str;
  for (int i = 0; frame < 10; i++) {
    if (str[i] >= 49 && str[i] <= 57) {
      ans += str[i] - '0';
      if (check) {
        check = 0;
        frame++;
      } else {
        check = 1;
      }
    } else if (str[i] == 'S') {
      ans += 10;
      frame++;
      for (int j = 1; j < 3; j++) {
        if (str[i + j] >= 49 && str[i + j] <= 57) {
          ans += str[i + j] - '0';
        } else if (str[i + j] == 'S') {
          ans += 10;
        } else if (str[i + j] == 'P') {
          if (str[i + j - 1] >= 49 && str[i + j - 1] <= 57) {
            ans += 10 - (str[i + j - 1] - '0');
          } else {
            ans += 10;
          }
        }
      }
    } else if (str[i] == 'P') {
      check = 0;
      frame++;
      if (str[i - 1] >= 49 && str[i - 1] <= 57) {
        ans += 10 - (str[i - 1] - '0');
      } else {
        ans += 10;
      }
      if (str[i + 1] >= 49 && str[i + 1] <= 57) {
        ans += str[i + 1] - '0';
      } else if (str[i + 1] == 'S') {
        ans += 10;
      }
    } else {
      if (check) {
        check = 0;
        frame++;
      } else {
        check = 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}