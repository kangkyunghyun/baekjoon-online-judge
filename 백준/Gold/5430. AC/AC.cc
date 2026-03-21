#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string p;
    int n, flag = 0;
    cin >> p >> n;
    deque<int> dq;
    char temp;
    cin >> temp;
    if (n != 0)
      for (int i = 0; i < n; i++) {
        int num;
        cin >> num >> temp;
        dq.push_back(num);
      }
    else
      cin >> temp;
    bool reverse = false;
    for (char c : p) {
      if (c == 'R') {
        reverse = !reverse;
      } else if (c == 'D') {
        if (dq.empty()) {
          flag = 1;
          break;
        }
        if (reverse)
          dq.pop_back();
        else
          dq.pop_front();
      }
    }
    if (flag == 0) {
      cout << '[';
      if (reverse) {
        for (auto iter = dq.rbegin(); iter != dq.rend(); iter++) {
          cout << *iter;
          if (iter != --dq.rend())
            cout << ",";
        }
      } else {
        for (auto iter = dq.begin(); iter != dq.end(); iter++) {
          cout << *iter;
          if (iter != --dq.end())
            cout << ",";
        }
      }
      cout << "]\n";
    } else {
      cout << "error\n";
    }
  }
  return 0;
}