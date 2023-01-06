// 2556: 별 찍기 - 14
//
// - 문제
// 지금까지 안 나온 별 찍기가 뭐가 있는지 생각해본 후, 별을 적절히 찍으세요.
//
// - 입력
// 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
//
// - 출력
// N개의 줄에 걸쳐 별을 적절히 찍는다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << '*';
    cout << '\n';
  }
  return 0;
}