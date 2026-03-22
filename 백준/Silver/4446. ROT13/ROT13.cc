#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  string a1 = "aiyeou", a2 = "AIYEOU", b1 = "bkxznhdcwgpvjqtsrlmf", b2 = "BKXZNHDCWGPVJQTSRLMF";
  while (getline(cin, str)) {
    string ans = "";
    for (char elem : str) {
      if (a1.find(elem) != string::npos) {
        int index = a1.find(elem) + 3;
        if (index >= 6)
          index -= 6;
        ans += a1[index];
      } else if (a2.find(elem) != string::npos) {
        int index = a2.find(elem) + 3;
        if (index >= 6)
          index -= 6;
        ans += a2[index];
      } else if (b1.find(elem) != string::npos) {
        int index = b1.find(elem) + 10;
        if (index >= 20)
          index -= 20;
        ans += b1[index];
      } else if (b2.find(elem) != string::npos) {
        int index = b2.find(elem) + 10;
        if (index >= 20)
          index -= 20;
        ans += b2[index];
      } else {
        ans += elem;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}