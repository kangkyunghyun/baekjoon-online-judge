// 28683: 피타! 피타! 피타츄!
//
// - 문제
// 포켓몬스터를 좋아하는 종우는 포켓몬스터를 연구하다가 포켓몬스터가 상당히 수학적이고 코딩과 밀접한 관련이 있는 게임이라는 것을 알게 되었다. 모든 이동은 유클리드 공간에 평행하게 이동하며, 데미지 및 급소 공격 등 수학적인 계산이 상당히 복잡하다. 또한 포켓몬스터 시리즈 역시 처음 발매된 시리즈의 이름부터 레드, 그린, 블루의 RGB이며, 블랙, 화이트 시리즈는 흑백이고, X, Y 시리즈는 미지수의 변수 이름이기도 하다. 심지어 아예 알고리즘의 이름을 따서 포켓몬스터 DP 시리즈도 있을 정도이다!
// 종우는 포켓몬들에게도 이러한 것이 숨겨져 있으리라 생각하고 피카츄도 사실 “피타츄”에서 유래되었다는 가설을 생각하게 되었다. 그래서 피카츄를 자세히 보던 중, 초기 피카츄의 꼬리가 직각이 많다는 것을 알아내었다! 피타고라스의 정리를 생각하던 종우는 문득 다음과 같은 의문이 들었다.
// 적어도 한 변의 길이가 $\sqrt{n}$인 서로 다른 모양의 직각삼각형 중 적어도 두 변의 길이가 정수인 직각삼각형은 몇 개일까? 합동이 아닌 삼각형을 서로 다른 모양의 삼각형이라고 한다.
// 종우를 도와 문제를 풀어보자.
//
// - 입력
// 직각삼각형이 포함해야 하는 변의 길이의 제곱을 나타내는 정수 $n(1\le n\le10^{12})$이 주어진다.
//
// - 출력
// 조건을 만족하는 직각삼각형의 개수를 출력한다.
// 만약 그러한 삼각형이 무한히 존재한다면, -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  if (sqrt(n) == (ll)sqrt(n)) {
    cout << -1;
    return 0;
  }
  set<pair<ll, ll>> ans;
  for (ll i = 1; i <= sqrt(n); i++) {
    ll x = i;
    double y = sqrt(n - x * x);
    ll tmp = y;
    if (y == tmp) {
      if (x > tmp)
        swap(x, tmp);
      ans.insert({x, tmp});
    }
  }
  vector<ll> divisor;
  for (ll i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      divisor.push_back(i);
      if (i != n / i)
        divisor.push_back(n / i);
    }
  }
  sort(divisor.begin(), divisor.end());
  for (ll i = 0; i < (divisor.size() + 1) / 2; i++) {
    if (divisor[i] % 2 == divisor[divisor.size() - i - 1] % 2)
      ans.insert({divisor[i], divisor[divisor.size() - i - 1]});
  }
  cout << ans.size();
  return 0;
}