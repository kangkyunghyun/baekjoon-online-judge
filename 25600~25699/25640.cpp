// 25640: MBTI
//
// - 문제
// 진호는 요즘 유행하는 심리 검사인 MBTI에 관심이 많다. MBTI는 아래와 같이 네 가지 척도로 사람들의 성격을 구분해서, 총 $16$가지의 유형중에서 자신의 유형을 찾을 수 있는 심리 검사이다.
// 내향(I) / 외향(E)
// 직관(N) / 감각(S)
// 감정(F) / 사고(T)
// 인식(P) / 판단(J)
// 모든 유형의 목록은 다음과 같다.
// INFP, ENFP, ISFP, ESFP, INTP, ENTP, ISTP, ESTP, INFJ, ENFJ, ISFJ, ESFJ, INTJ, ENTJ, ISTJ, ESTJ
// 진호는 N명의 친구들에게 MBTI 유형을 물어 봤다. 이 중에서 진호와 MBTI 유형이 같은 사람의 수는 얼마일까?
//
// - 입력
// 첫째 줄에 진호의 MBTI 유형이 주어진다.
// 둘째 줄에 진호의 친구의 수 N(1 ≤ N ≤ 100)이 주어진다.
// 셋째 줄부터 N개의 줄에 친구들의 MBTI 유형이 주어진다.
//
// - 출력
// 진호와 MBTI 유형이 같은 사람의 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  string j, f;
  cin >> j;
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f;
    if (f == j)
      cnt++;
  }
  cout << cnt << '\n';
  return 0;
}