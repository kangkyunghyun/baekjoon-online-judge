// 27295: 선형 회귀는 너무 쉬워 1
//
// - 문제
// 유림이는 선형 회귀에 자신이 있다. 그래서 MatKor 동아리에서 선형 회귀에 관한 수업을 할 때 집중을 하지 않았다. 당시 강사였던 동우는 이를 못마땅하게 여겨 유림이에게 더 어려운 문제를 내주었다. 일반적인 선형 회귀의 경우 데이터 (x_1, y_1), (x_2, y_2), ... , (x_n, y_n)이 주어졌을 때, 잔차 제곱의 합이 0에 가장 가깝도록, 즉
// \displaystyle\sum_{i=1}^n (a_2x_i+b_2-y_i)^2이 최소가 되도록 하는 실수 a_2와 b_2를 찾는 문제이다. 동우는 여기에서 더 발전시켜 잔차 k제곱의 합 즉,
// \displaystyle\sum_{i=1}^n (a_kx_i+b_k-y_i)^k이 0에 가장 가깝도록 하는 실수 a_k와 b_k을 구하는 문제를 냈다. 이 문제를 풀던 유림이는 너무 어려워서 동우에게 조금만 쉽게 바꿔 달라고 하자 동우는 조금 고민을 하다 다음과 같은 조건을 추가한다. "k = 1일 때만 구해. 그리고 y절편이 정해져 있을 때 기울기만 정해."
// 유림이를 도와 y절편이 주어졌을 때 문제를 풀어보자. 즉, 주어진 b에 대해 다음 문제의 답을 구해보자.
// \displaystyle\sum_{i=1}^n (a_1x_i+b-y_i)^1의 값이 0에 가장 가깝도록 하는 실수 a_1을 구하시오.
//
// - 입력
// 첫 줄에 데이터의 개수를 의미하는 정수 n (1 ≤ n ≤ 10^5)과 y 절편을 의미하는 정수 b (-10^9 ≤ b ≤ 10^9)가 주어진다.
// 두 번째 줄부터 n개의 줄에 걸쳐 한 줄에 하나씩 점의 좌표를 나타내는 정수 x_i와 y_i (-10^9 ≤ x_i, y_i ≤ 10^9)의 값이 주어진다.
// 이때, 서로 같은 점이 여러 번 주어질 수 있음에 유의한다.
//
// - 출력
// 첫 번째 줄에
// \displaystyle\sum_{i=1}^n (a_1x_i+b-y_i)^1의 값이 0에 가장 가깝도록 하는 a_1을 출력한다.
// 만약 답이 정수라면 그대로 출력하고, 정수가 아닌 유리수라면 기약분수
// p/q (1 ≤ |p|,  2 ≤ q이며 gcd(|p|,q)=1)로 약분해 p/q의 형태로 출력한다.
// \displaystyle\sum_{i=1}^n (a_1x_i+b-y_i)^1의 값이 0에 가장 가깝도록 하는 a_1 중 유리수가 존재함을 증명할 수 있다.
// 만약 답으로 가능한 a_1이 여러 개 존재한다면, "EZPZ"를 출력한다.

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (!b)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long n, b, xSum = 0, ySum = 0, bSum = 0;
  cin >> n >> b;
  bSum = n * b;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    xSum += x;
    ySum += y;
  }
  if (xSum == 0) {
    cout << "EZPZ";
  } else if (bSum == ySum) {
    cout << 0;
  } else {
    long long left = xSum;
    long long right = ySum - bSum;
    if (right % left == 0) {
      cout << right / left;
    } else {
      long long d = gcd(left, right);
      long long p = right / d;
      long long q = left / d;
      if ((p < 0 && q > 0) || (p > 0 && q < 0))
        cout << '-' << abs(p) << '/' << abs(q);
      else
        cout << p << '/' << q;
    }
  }
  return 0;
}