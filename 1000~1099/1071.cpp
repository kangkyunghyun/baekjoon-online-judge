// 1071: 소트
//
// - 문제
// N개의 정수가 주어지면, 이것을 연속된 두 수가 연속된 값이 아니게 정렬(A[i] + 1 ≠ A[i+1])하는 프로그램을 작성하시오. 가능한 것이 여러 가지라면 사전순으로 가장 앞서는 것을 출력한다.
//
// - 입력
// 첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 N개의 수가 주어진다. N개의 수는 1,000보다 작거나 같은 자연수 또는 0이다.
//
// - 출력
// 첫째 줄에 문제의 정답을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n), ans;
  deque<int> dq;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
    dq.push_back(v[i]);
  while (!dq.empty()) {
    if (dq.back() - dq.front() <= 1) {
      while (!dq.empty()) {
        ans.push_back(dq.back());
        dq.pop_back();
      }
    } else {
      if (ans.size() == 0) {
        ans.push_back(dq.front());
        dq.pop_front();
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (dq[i] - ans.back() != 1) {
          ans.push_back(dq[i]);
          for (int j = 0; j < i; j++) {
            dq.push_back(dq.front());
            dq.pop_front();
          }
          dq.pop_front();
          for (int j = 0; j < i; j++) {
            dq.push_front(dq.back());
            dq.pop_back();
          }
          break;
        }
      }
    }
  }
  for (int i : ans)
    cout << i << ' ';
  cout << '\n';
  return 0;
}