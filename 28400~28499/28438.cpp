// 28438: 행렬 연산 (행렬 계산하기)
//
// - 문제
// $N$행 $M$열로 이루어진 $2$차원 행렬이 있습니다. 이 행렬의 모든 원소는 처음에 $0$입니다.
// 이 행렬에 다음과 같은 연산을 할 수 있습니다.
// $1$ $r$ $v$
// $1$ 이상 $N$ 이하의 수 $r$과 정수 $v$를 정합니다. $r$번째 행의 모든 원소에 $v$를 더합니다.
// $2$ $c$ $v$
// $1$ 이상 $M$ 이하의 수 $c$와 정수 $v$를 정합니다. $c$번째 열의 모든 원소에 $v$를 더합니다.
// 연산 $Q$ 개가 주어졌을 때, 연산을 차례대로 시행한 결과를 출력하세요.
//
// - 입력
// 첫 줄에 행렬 $A$의 크기를 나타내는 $N$, $M$과 연산의 개수 $Q$가 공백으로 구분되어 주어집니다. $(1 \le N, M; N \times M \le 500\,000; 1 \le Q \le 500\,000)$ 
// 다음 $Q$개의 줄에는 각 연산을 의미하는 세 개의 정수가 공백으로 구분되어 주어집니다. 쿼리는 문제에서 주어진 “$1$ $r$ $v$” 혹은 “$2$ $c$ $v$” 의 형태입니다. $(1 \le r \le N;$ $1 \le c \le M;$ $-1\,000 \le v \le 1\,000)$ 
//
// - 출력
// $N$개의 줄을 출력하세요. $i$번째 줄에는 $M$개의 공백으로 구분된 정수가 있어야 하고, 이 중 $j$번째 수는 연산이 끝난 이후 $i$번째 행 $j$번째 열에 있는 수를 의미합니다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, idx;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == "?")
      idx = i;
  }
  int m;
  cin >> m;
  string s, ans;
  while (m--) {
    cin >> s;
    if (find(v.begin(), v.end(), s) == v.end()) {
      if (n == 1) {
        ans = s;
        break;
      } else if (idx == 0) {
        string next = v[idx + 1];
        char last = s[s.size() - 1];
        char first = next[0];
        if (last == first) {
          ans = s;
          break;
        }
      } else if (idx == n - 1) {
        string prev = v[idx - 1];
        char first = s[0];
        char last = prev[prev.size() - 1];
        if (first == last) {
          ans = s;
          break;
        }
      } else {
        string next = v[idx + 1];
        string prev = v[idx - 1];
        char nextFirst = next[0];
        char last = s[s.size() - 1];
        char prevLast = prev[prev.size() - 1];
        char first = s[0];
        if (nextFirst == last && prevLast == first) {
          ans = s;
          break;
        }
      }
    }
  }
  cout << s;
  return 0;
}