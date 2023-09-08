// 28432: 끝말잇기
//
// - 문제
// 끝말잇기는 단어를 중복하지 않고 단어의 맨 끝 글자에 이어서 말하는 놀이입니다. 끝말잇기 기록은 단어들의 나열로 이루어집니다. 올바른 끝말잇기 기록은 각 단어의 마지막 글자가 다음 단어의 첫 글자이며, 단어가 중복되어서 나타나면 안 됩니다.
// 끝말잇기 기록이 주어지는데, 하나의 기록은 “?”로 가려진 채로 들어옵니다. “?”에 들어갈 수 있는 문자열들의 후보가 주어질 때, 올바른 끝말잇기 기록을 만드는 “?”에 들어갈 문자열을 출력하세요.
//
// - 입력
// 첫 줄에 끝말잇기 기록의 길이 $N$ 이 주어집니다. $(1 \le N \le 100)$ 둘째 줄부터 다음 $N$개의 줄에는 끝말잇기의 기록 $S_1, \cdots, S_N$이 한 줄에 하나씩 주어집니다. 여기서, 하나의 $S_i$는 “?” 로 주어집니다. 나머지 $S_i$는 길이 $2$ 이상 $10$ 이하의 영어 소문자로 이루어진 문자열입니다.
// 다음 줄에 후보 단어의 개수 $M$이 주어집니다. $(1 \le M \le 100)$ 다음 $M$개의 줄에는 후보 단어 $A_1, \cdots, A_M$이 주어집니다. $A_i$는 길이 $2$ 이상 $10$ 이하의 영어 소문자로 이루어진 문자열입니다. $A_1, \cdots, A_M$은 서로 다릅니다.
// 문제의 답이 정확히 하나인 경우만 입력으로 주어집니다.
//
// - 출력
// “?”에 들어갈 수 있는 문자열을 후보 단어인 $A_1, \cdots, A_M$ 중에서 하나 찾아서 출력하세요.

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