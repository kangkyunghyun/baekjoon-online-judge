// 4383: 점프는 즐거워
//
// - 문제
// Jolly jumper라 불리는 수열이 있다. 길이가 1인 수열은 무조건 Jolly jumper이고, 길이가 2이상일 때는 n개의 연속된 두 수의 차의 절댓값이 1부터 n-1까지 모두 나와야 Jolly jumper라고 한다. 예를 들어
// 1 4 2 3
// 이것은 Jolly jumper인데, 두 수의 차의 절댓값이 각각 3,2,1이기 때문이다. 하여튼 조건을 충족하면 어느 수열이든 Jolly jumper라 할 수 있다. 이제 각 케이스마다 Jolly jumper인지를 판별하자.
//
// - 입력
// 각 줄의 첫 수로 n이 주어진다.(n < 3000) 그 다음에는 n개의 수가 주어진다.
//
// - 출력
// 각 줄마다 Jolly 인지 Not jolly 인지 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  while (cin >> n) {
    int ans = 0;
    vector<int> v(n), check(n, 0);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    for (int i = 0; i < n - 1; i++) {
      int tmp = abs(v[i] - v[i + 1]);
      if (tmp >= 1 && tmp <= n - 1)
        check[tmp] = 1;
    }
    for (int i = 1; i < n; i++)
      if (check[i])
        ans++;
    if (ans == n - 1)
      cout << "Jolly\n";
    else
      cout << "Not jolly\n";
  }
  return 0;
}