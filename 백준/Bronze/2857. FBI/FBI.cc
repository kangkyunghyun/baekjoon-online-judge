#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<string> v(5);
  for (int i = 0; i < 5; i++)
    cin >> v[i];
  int flag = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].find("FBI") != string::npos) {
      cout << i + 1 << ' ';
      flag++;
    }
  }
  if (!flag)
    cout << "HE GOT AWAY!";
  return 0;
}