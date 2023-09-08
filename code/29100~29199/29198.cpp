// 29198: 이번에는 C번이 문자열
//
// - 문제
// 지난 대회에 이어 이번에도 문자열 문제를 출제하고 싶은 에릭은 다음과 같은 문제를 떠올렸다. 정답 코드를 짜기 귀찮은 에릭을 위해 대신 문제를 풀어주자!
// 길이가 $M$인 $N$개의 문자열 $S_1, S_2, \cdots, S_N$이 주어진다.
// 다음 방법으로 만들 수 있는 문자열 $T$ 중 사전순으로 가장 앞에 오는 것을 출력한다.
// $S_1, S_2, \cdots, S_N$ 중 $K$개를 선택한 후, 이어 붙여서 길이 $K \cdot M$의 문자열을 만든다.
// 이렇게 얻은 $K \cdot M$개의 문자를 적당히 재배치하여 문자열 $T$를 만든다.
// 서로 다른 두 문자열 $a$, $b$에 대해 다음 중 하나가 성립할 때 문자열 $a$가 문자열 $b$보다 사전순으로 앞에 온다고 말한다.
// $a$가 $b$의 접두사
// $a$와 $b$가 달라지는 첫 위치에서 $a$의 문자가 알파벳 순으로 $b$의 문자보다 앞에 위치함
//
// - 입력
// 첫 번째 줄에 세 정수 $N$, $M$, $K$가 공백으로 구분되어 주어진다.
// $i + 1$번째 줄에는 문자열 $S_i$가 주어진다. $(1 \le i \le N)$ 
//
// - 출력
// $S_1, S_2, \cdots, S_N$을 이용하여 위에서 설명한 방법으로 만들 수 있는 문자열 $T$ 중 사전순으로 가장 앞에 오는 것을 출력한다.
//
// - 제한
// $1 \le K \le N \le 300$ 
// $1 \le M \le 300$ 
// $S_i$는 영어 대문자로 구성된 길이 $M$의 문자열 $(1 \le i \le N)$ 

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sort(v[i].begin(), v[i].end());
  }
  sort(v.begin(), v.end());
  string ans = "";
  for (int i = 0; i < k; i++)
    ans += v[i];
  sort(ans.begin(), ans.end());
  cout << ans;
  return 0;
}