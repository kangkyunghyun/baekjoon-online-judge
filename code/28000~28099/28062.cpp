// 28062: 준석이의 사탕 사기
//
// - 문제
// 준석이는 두 동생을 위해 사탕 가게에서 사탕을 최대한 많이 사 가려고 한다. 사탕 가게에는 $N$개의 사탕 묶음이 있으며 $i$번째 사탕 묶음에는 $a_i$개의 사탕이 있다.
// 준석이는 정말 부자라 사탕 묶음을 마음껏 살 수 있다. 하지만 준석이가 사간 총 사탕의 개수가 홀수가 되면 두 동생이 사탕을 한 개라도 더 갖기 위해 서로 싸울 것이라 총 짝수 개의 사탕을 가져가려고 한다. 준석이를 위해서 최대로 가져갈 수 있는 사탕의 개수를 구해주자!
//
// - 입력
// 첫째 줄에 사탕 묶음의 개수 $N$이 주어진다. \((1 \leq N \leq 1000)\) 
// 둘째 줄에 각각의 사탕 묶음에 담겨있는 사탕의 개수 $a_1,a_2, \cdots, a_N$가 주어진다. \((1 \leq a_i \leq 1000)\) 
// 입력으로 주어지는 모든 수는 정수이다.
//
// - 출력
// 준석이가 최대로 가져갈 수 있는 사탕의 개수를 출력한다.
// 사탕을 홀수 개로만 가져갈 수 있으면 $0$을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n), odd;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] % 2)
      odd.push_back(v[i]);
  }
  if (odd.size() == 1 && n == 1) {
    cout << 0;
  } else if (odd.size() % 2) {
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (v[i] % 2 == 0)
        ans += v[i];
    sort(odd.begin(), odd.end(), greater<>());
    for (int i = 0; i < odd.size() - 1; i++)
      ans += odd[i];
    cout << ans;
  } else {
    cout << accumulate(v.begin(), v.end(), 0);
  }
  return 0;
}