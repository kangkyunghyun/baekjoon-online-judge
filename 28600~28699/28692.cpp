// 28692: 선형 회귀는 너무 쉬워 2
//
// - 문제
// 유림이는 선형 회귀에 자신이 있다. 그래서 MatKor 동아리에서 선형 회귀에 관한 수업을 할 때 집중하지 않았다. 당시 강사였던 동우는 이를 못마땅하게 여겨 유림이에게 다른 문제 선형 회귀는 너무 쉬워 1을 내주었고, 유림이는 문제를 쉽게 풀었다.
// 동우는 이제 기존의 선형 회귀 문제를 내주었다. 데이터 $(x_1, y_1), (x_2, y_2), \cdots , (x_n, y_n)$이 주어졌을 때, 이를 가장 잘 설명하는 일차함수 $y=ax+b$를 찾는 문제이다. 여기서 주어진 점들 $(x_i, y_i)$에 대해 $x_i$를 통해 얻는 추정치 $\hat{y_i} = ax_i+b$로 정의하고, 실제 $y_i$에서 예측치인 $\hat{y_i}$를 뺀 값 $y_i-\hat{y_i}$를 잔차 $\epsilon_i$로 정의한다.
// 선형 회귀 문제는 이 잔차 제곱의 합이 $0$에 가장 가깝도록, 즉 $\displaystyle\sum_{i=1}^n \epsilon_i^2 = \displaystyle\sum_{i=1}^n (y_i-ax_i-b)^2$이 최소가 되도록 하는 실수 $a$와 $b$를 찾는 문제이다. 이 값이 최소가 되도록 하는 $a$와 $b$를 $a_2$, $b_2$라고 한다. 여기서 $\displaystyle\sum_{i=1}^n \epsilon_i^2$은 $\epsilon_1^2+\epsilon_2^2+\cdots+\epsilon_n^2$를, $\displaystyle\sum_{i=1}^n (y_i-ax_i-b)^2$은 $(y_1-ax_1-b)^2+(y_2-ax_2-b)^2+\cdots+(y_n-ax_n-b)^2$를 나타낸다.
// 동우는 유림이에게 주어진 점들에 대해 잔차 제곱의 합이 최소가 되도록 하는 실수 $a_2$와 $b_2$를 구해보라는 문제를 내주었다.
// 그러나 유림이는 이미 답을 알고 있고, 바로 코딩하기로 했다. 답은 다음과 같다.
// 먼저 $x_i$의 합을 $S_x$, $y_i$의 합을 $S_y$, $x_i^2$의 합을 $S_{xx}$, $x_iy_i$의 합을 $S_{xy}$라 하고, 이를 구하자. 그렇다면 $a_2$와 $b_2$는 경우에 따라 다음과 같다.
// 만약 $S_x^2\ne nS_{xx}$라면 아래와 같이 답을 구할 수 있다.
// \[\begin{align*}a_2&=\frac{nS_{xy}-S_xS_y}{nS_{xx}-S_x^2}\\ b_2&=\frac{S_y-a_2S_x}{n}\end{align*}\]
// 계산 중 분자와 분모에 대해 $2\times 10^{18}$의 큰 수가 등장할 수 있음에 유의해 적절한 자료형을 사용하도록 하자.
// 만약 $S_x^2=nS_{xx}$이라면 가능한 $a_2$와 $b_2$ 쌍이 유일하지 않고 여러 개 존재한다.
// 위의 결과에 대한 구체적인 증명 과정은 아래 노트에 있으므로, 관심이 있다면 나중에 읽어보자.
//
// - 입력
// 첫 줄에 데이터의 개수를 의미하는 정수 $n(2 \le n \le 10^6)$이 주어진다.
// 두 번째 줄부터 $n$개의 줄에 걸쳐 한 줄에 하나씩 점의 좌표를 나타내는 정수 $x_i$와 $y_i$($-10^3 \le x_i, y_i \le 10^3$)의 값이 주어진다.
// 이때, 서로 같은 점이 여러 번 주어질 수 있음에 유의한다.
//
// - 출력
// 첫 번째 줄에 $\displaystyle\sum_{i=1}^n (a_2x_i+b_2-y_i)^2$의 값이 $0$에 가장 가깝도록 하는 $a_2$와 $b_2$가 유일하게 존재한다면, 이를 공백으로 구분하여 출력한다
// 만약 답으로 가능한 $a_2$와 $b_2$ 쌍이 여러 개 존재한다면, 첫 줄에 EZPZ를 출력한다.
// 정답과의 절대 혹은 상대 오차가 $10^{-6}$ 이하라면 정답으로 간주한다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  ll Sx = 0, Sy = 0, Sxx = 0, Sxy = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    Sx += x;
    Sy += y;
    Sxx += x * x;
    Sxy += x * y;
  }
  double a = (double)(n * Sxy - Sx * Sy) / (n * Sxx - Sx * Sx);
  double b = (double)(Sy - a * Sx) / n;
  cout.precision(9);
  if (isnan(a) && isnan(b))
    cout << "EZPZ";
  else
    cout << fixed << a << ' ' << b;
  return 0;
}