// 29160: 나의 FIFA 팀 가치는?
//
// - 문제
// 넥슨의 FIFA ONLINE 4는 축구 경기 시뮬레이션을 생동감 있게 플레이할 수 있는 게임이다. 각 선수별로 포지션이 있으며, 선수별로 능력치와 선수 가치가 존재하여 경기에 영향을 미치게 된다. 또한 선발 선수와 후보 선수를 구분하여 선발 선수의 컨디션이 안 좋은 경우 후보 선수와 교체할 수도 있다.
// FIFA ONLINE 4를 즐겨하는 주원이는 다음 과정대로 팀을 구성하면 $K$년 $12$월에 되었을 때 팀의 선발 선수 가치의 합은 얼마가 되어 있을지 궁금해 하였다.
// 팀은 총 $11$명으로, 포지션 번호는 $1$ 이상 $11$ 이하인 정수이다.
// $3$월에 같은 포지션 중 선수 가치가 가장 높은 선수가 선발 선수가 된다. 선수 가치가 가장 높은 선수가 여러 명 있을 경우, 그 중 아무나 선발 선수로 선택한다.포지션에 해당하는 선수가 없을 시, 해당 포지션을 공석으로 팀을 구성한다.
// $8$월에 현재 팀에 있는 선발 선수의 선수 가치는 모두 $1$이 떨어진다. 선수 가치는 $0$보다 작아지지 않는다.
// $11$월에 2의 조건대로 선발 선수를 재구성한다.
// 선수 $N$명의 포지션 번호와 선수 가치가 주어졌을 때, $1, 2, \cdots, K$년이 될 때마다 매년 위 과정대로 새로운 팀을 구성한다. $K$년 $12$월에 되었을 때 만든 팀의 선발 선수 가치의 합을 구하여라.
//
// - 입력
// 첫 번째 줄에 선수의 수 $N$과 $K$가 공백으로 구분되어 주어진다. $(0\leq N\leq 1\,000\,000;$ $1\leq K\leq 50\,000)$ 
// 두 번째 줄부터 $N$개의 줄에 걸쳐 각 줄에 $i$번째 선수의 포지션 $P_{i}$, 선수 가치 $W_{i}$가 공백으로 구분되어 주어진다. $(1 \leq i \leq N;$ $1\leq P_{i}\leq 11;$ $1\leq W_{i}\leq 100\,000)$ 
// 입력으로 주어지는 수는 모두 정수이다.
//
// - 출력
// $K$년 $12$월에 되었을 때 만든 팀의 선발 선수 가치의 합을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l, q;
  cin >> n;
  vector<int> length(n + 1), prefix_sum(n + 1, 0);
  vector<double> coordinate(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> length[i];
    prefix_sum[i] = length[i] + prefix_sum[i - 1];
    coordinate[i] = prefix_sum[i] - (double)length[i] / 2;
  }
  cin >> l >> q;
  cout.precision(2);
  cout << fixed;
  double mid = (double)l / 2;
  while (q--) {
    int x;
    cin >> x;
    double gap = mid - coordinate[x];
    if (gap >= 0 || prefix_sum[n] < l)
      cout << (double)0;
    else if ((double)prefix_sum[n] - coordinate[x] < (double)l / 2)
      cout << (double)prefix_sum[n] - l;
    else
      cout << -gap;
    cout << '\n';
  }
  return 0;
}