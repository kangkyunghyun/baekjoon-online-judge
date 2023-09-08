// 1041: 주사위
//
// - 문제
//     +---+
//     | D |
// +---+---+---+---+
// | E | A | B | F |
// +---+---+---+---+
//     | C |
//     +---+
// 주사위는 위와 같이 생겼다. 주사위의 여섯 면에는 수가 쓰여 있다. 위의 전개도를 수가 밖으로 나오게 접는다.
// A, B, C, D, E, F에 쓰여 있는 수가 주어진다.
// 지민이는 현재 동일한 주사위를 N3개 가지고 있다. 이 주사위를 적절히 회전시키고 쌓아서, N×N×N크기의 정육면체를 만들려고 한다. 이 정육면체는 탁자위에 있으므로, 5개의 면만 보인다.
// N과 주사위에 쓰여 있는 수가 주어질 때, 보이는 5개의 면에 쓰여 있는 수의 합의 최솟값을 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N이 주어진다. 둘째 줄에 주사위에 쓰여 있는 수가 주어진다. 위의 그림에서 A, B, C, D, E, F에 쓰여 있는 수가 차례대로 주어진다. N은 1,000,000보다 작거나 같은 자연수이고, 쓰여 있는 수는 50보다 작거나 같은 자연수이다.
//
// - 출력
// 첫째 줄에 문제의 정답을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a, b, c, d, e, f, ans = 0;
  cin >> n >> a >> b >> c >> d >> e >> f;
  if (n == 1) {
    vector<long long> v{a, b, c, d, e, f};
    sort(v.begin(), v.end());
    for (int i = 0; i < 5; i++)
      ans += v[i];
  } else {
    vector<long long> v{a, b, c, d, e, f};
    long long one_face = *min_element(v.begin(), v.end());
    v = {a + b, a + c, a + d, a + e, b + c, b + d, b + f, c + e, c + f, d + e, d + f, e + f};
    long long two_face = *min_element(v.begin(), v.end());
    v = {a + b + c, a + b + d, a + d + e, a + c + e, b + c + f, b + d + f, c + e + f, d + e + f};
    long long three_face = *min_element(v.begin(), v.end());
    ans += three_face * 4 + two_face * ((n - 2) * 4 + (n - 1) * 4) + one_face * ((n - 2) * (n - 2) + (n - 2) * (n - 1) * 4);
  }
  cout << ans << '\n';
  return 0;
}