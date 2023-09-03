// 29159: 케이크 두 개
//
// - 문제
// SUAPC 2023 Summer 출제진을 먹일 $NMK$개의 2차원 케이크들이 연세대학교 공A527에 배달되었다. 문제를 만드느라 당이 떨어진 출제진은 그만 특별한 케이크 두 개만을 남기고 전부 먹어치우고 말았다.
// 뒤늦게 도착한 Sinchon ICPC 회장과 공간을 제공한 Morgorithm 회장에게 아직 열지 않은 두 개의 케이크 박스를 바침으로서 분노는 피했지만, 이 두 명은 케이크를 보고 새로운 문제 아이디어가 떠오르고 말았다. 두 개의 케이크가 모두 직사각형 모양이었던 것이다. 두 사람은 머릿속에서 단 한 번의 칼질만으로 두 개의 케이크를 각각 넓이가 같은 두 조각으로 나눌 수 있다는 것은 증명했지만, 당이 떨어진 나머지 실제로 이 칼질이 어떻게 이루어져야 하는지는 출제진에게 맡기고 말았다.
// 두 사람이 케이크를 전부 먹기 전에, 두 개의 케이크를 각각 넓이가 같은 두 조각으로 나눌 수 있도록 하는 칼질이 어떻게 이루어져야 하는지 구해 보자.
//
// - 입력
// 첫 번째 줄부터 $4$개의 줄에 걸쳐, 첫 번째 케이크 꼭지점의 $x$좌표와 $y$좌표를 나타내는 정수 $x_{1,i}, y_{1,i}$이 공백으로 구분되어 주어진다. $(1 \leq i \leq 4;$ $-100\,000 \le x_{1,i}, y_{1,i} \le 100\,000)$ 
// 다섯 번째 줄부터 $4$개의 줄에 걸쳐, 두 번째 케이크 꼭지점의 $x$좌표와 $y$좌표를 나타내는 정수 $x_{2,i}, y_{2,i}$이 공백으로 구분되어 주어진다. $(1 \leq i \leq 4;$ $-100\,000 \le x_{2,i}, y_{2,i} \le 100\,000)$ 
// 케이크는 항상 비어 있지 않은 직사각형이며, 케이크 꼭지점의 점 순서는 무작위로 주어짐에 유의하라. 또한, 두 케이크가 어느 한 점에서 만나는 경우나 $y$축에 평행하게 칼질하는 법이 존재하는 경우는 주어지지 않는다.
//
// - 출력
// 칼질이 직선 $y=px+q$의 일부일 때, 첫째 줄에 $p,q$를 공백으로 구분하여 출력한다. 답이 여러 개라면 아무거나 출력한다.
// 단, $p$나 $q$가 정수일 경우 그대로 출력하고, 정수가 아닐 경우 출력하려는 수가 $\frac{a}{b}$ 라면 $a$와 $b$를 ‘/’로 구분하여 출력한다. $(a,b$는 정수, $b>0$, $\gcd(a,b)=1)$ 
// 계산 및 출력 과정에서 $32$비트 정수의 범위를 넘을 수 있음에 유의하라.

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