#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  priority_queue<int> max;
  priority_queue<int, vector<int>, greater<>> min;
  while (n--) {
    int x;
    cin >> x;
    if (max.size() == min.size())
      max.push(x);
    else
      min.push(x);
    if (!max.empty() && !min.empty() && max.top() > min.top()) {
      int a = max.top();
      int b = min.top();
      max.pop();
      min.pop();
      max.push(b);
      min.push(a);
    }
    cout << max.top() << '\n';
  }
  return 0;
}