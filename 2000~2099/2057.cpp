// 2057: 팩토리얼 분해
//
// - 문제
// 음 아닌 정수 N이 주어졌을 때, 이 수를 서로 다른 정수 M(M ≥ 1)개의 팩토리얼의 합으로 나타낼 수 있는지 알아내는 프로그램을 작성하시오. 예를 들어 2=0!+1!로 나타낼 수 있지만, 5는 이와 같은 방식으로 나타낼 수 없다.
//
// - 입력
// 첫째 줄에 정수 N이 주어진다.
//
// - 출력
// 입력으로 주어진 수를 서로 다른 정수 M개의 팩토리얼의 합으로 나타낼 수 있으면 YES, 없으면 NO를 출력한다.
//
// - 제한
// 0 ≤ N ≤ 1,000,000,000,000,000,000

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  if (!n) {
    cout << "NO";
    return 0;
  }
  long long v[21] = {1, 1};
  for (int i = 2; i < 21; i++)
    v[i] = v[i - 1] * i;
  for (int i = 20; i >= 0; i--)
    if (n >= v[i])
      n -= v[i];
  cout << (n ? "NO" : "YES");
  return 0;
}