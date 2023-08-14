// 28703: Double It
//
// - 문제
// 양의 정수로 이루어진 길이가 N인 배열 A_1, \cdots, A_N이 주어집니다. 당신은 원하는 만큼 다음 조작을 할 수 있습니다.
// 배열에서 원하는 수 하나를 골라서 2를 곱합니다.
// 조작 이후 A_1, \cdots, A_N의 최댓값과 최솟값의 차이로 가능한 최솟값을 구하세요.
//
// - 입력
// 첫 줄에 배열의 길이 N이 주어집니다. (1 ≤ N ≤ 200\,000)
// 둘째 줄에 N개의 양의 정수 A_1, A_2, \cdots, A_N이 주어집니다. (1 ≤ A_i ≤ 10^9) 
//
// - 출력
// 조작 이후 A_1, \cdots, A_N의 최댓값과 최솟값의 차이로 가능한 최솟값을 구하세요.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m = 0;
  cin >> n;
  priority_queue<int> q;
  while (n--) {
    int x;
    cin >> x;
    m = max(m, x);
    q.push(-x);
  }
  int mx = m;
  int ans = mx + q.top();
  while (-q.top() < m) {
    int x = -q.top();
    q.pop();
    ans = min(ans, mx - x);
    mx = max(mx, 2 * x);
    q.push(-2 * x);
  }
  cout << min(mx + q.top(), ans);
  return 0;
}