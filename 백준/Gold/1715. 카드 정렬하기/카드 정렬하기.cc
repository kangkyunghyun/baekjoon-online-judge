#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  priority_queue<int, vector<int>, greater<>> pq;
  while (n--) {
    int x;
    cin >> x;
    pq.push(x);
  }
  while (pq.size() != 1) {
    int temp = pq.top();
    pq.pop();
    temp += pq.top();
    pq.pop();
    pq.push(temp);
    ans += temp;
  }
  cout << ans << '\n';
  return 0;
}