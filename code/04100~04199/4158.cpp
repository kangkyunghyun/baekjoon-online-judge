// 4158: CD
//
// - 문제
// 상근이와 선영이는 동시에 가지고 있는 CD를 팔려고 한다. CD를 몇 개나 팔 수 있을까?
//
// - 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 상근이가 가지고 있는 CD의 수 N, 선영이가 가지고 있는 CD의 수 M이 주어진다. N과 M은 최대 백만이다. 다음 줄부터 N개 줄에는 상근이가 가지고 있는 CD의 번호가 오름차순으로 주어진다. 다음 M개 줄에는 선영이가 가지고 있는 CD의 번호가 오름차순으로 주어진다. CD의 번호는 십억을 넘지 않는 양의 정수이다. 입력의 마지막 줄에는 0 0이 주어진다.
// 상근이와 선영이가 같은 CD를 여러장 가지고 있는 경우는 없다.
//
// - 출력
// 두 사람이 동시에 가지고 있는 CD의 개수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  while (1) {
    int n, m, ans = 0, start = 0, end = 0;
    cin >> n >> m;
    if (!n && !m)
      break;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    while (1) {
      if (start == a.size() || end == b.size())
        break;
      else if (a[start] < b[end])
        start++;
      else if (a[start] > b[end])
        end++;
      else {
        start++;
        end++;
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}