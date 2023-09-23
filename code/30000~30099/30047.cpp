#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  stack<int> st;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'x') {
      if (st.empty()) {
        cout << -1;
        return 0;
      }
      int tmp = 0;
      while (!st.empty() && st.top() == -1) {
        st.pop();
        tmp++;
      }
      if (tmp != 0)
        st.push(tmp);
      else
        st.push(0);
      while (st.size() > 2) {
        int a = st.top();
        st.pop();
        if (st.top() < 0) {
          st.push(a);
          break;
        }
        int b = st.top();
        st.pop();
        while (!st.empty() && st.top() == -2) {
          st.pop();
          st.push(min(a, b));
          tmp = st.top();
          st.pop();
          while (!st.empty() && st.top() == -1) {
            st.pop();
            tmp++;
          }
          st.push(tmp);
        }
      }
    } else if (s[i] == 'g') {
      st.push(-1);
    } else {
      st.push(-2);
    }
  }
  if (st.size() > 1)
    cout << -1;
  else
    cout << st.top();
  return 0;
}