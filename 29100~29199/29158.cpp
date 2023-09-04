// 29158: 큰 수 만들기 게임
//
// - 문제
// 성현이와 지훈이는 큰 수 만들기 게임을 하고 있다. 성현이는 양의 정수 $N$이 적힌 카드 $1$장이 들어 있는 주머니를 들고 있다. 지훈이는 성현이의 카드를 몰래 본 다음 성현이의 카드에 적힌 $N$보다 작은 양의 정수 $M$을 선택하여 카드에 적은 후 자신의 주머니에 넣었다. 이 둘은 각자 $1$장의 카드가 들어 있는 주머니를 가지고, 다음 두 동작 중 원하는 동작을 원하는 만큼 수행할 수 있다.
// 동작 $1$ . 주머니 속에서 원하는 카드 $D$를 선택하여 꺼낸다. $D$가 임의의 정수 $K$로 나누어 떨어지면, 각각  $\frac{D}{K}$, $K$가 적힌 $2$개의 카드를 주머니에 넣는다. 단, $K$는 $D$를 나눌 수 있다면, 원하는 수로 정할 수 있다. $(2\leq K \lt D;$ $K \mid D)$ 
// 동작 $2$ . 주머니에 카드가 $2$개 이상 있을 때, 원하는 두 카드 $A, B$를 꺼낸다. 주머니에 $A \times B$가 적힌 $1$개의 카드를 넣는다.
// 원하는 만큼 동작을 수행한 이후에 주머니에 있는 모든 카드를 적절히 배치하여 하나의 수를 만든다. 배치할 때는 숫자가 아닌 카드에 적힌 수 단위로 재배열해야 한다. 즉, 남은 카드가 $7$, $91$일 때 만들 수 있는 최댓값은 $971$이 아닌, $917$임에 유의하자.
// 성현이와 지훈이가 각자 만들 수 있는 수의 최댓값의 합을 구하여라.
//
// - 입력
// 첫 번째 줄에 정수 $N$이 주어진다. $(2\leq N\leq 10^{12})$ 
//
// - 출력
// 두 사람이 만들 수 있는 수의 최댓값의 합을 구하여라.

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

bool cmp(string a, string b) {
  string ab = a + b;
  string ba = b + a;
  return ab > ba;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, t;
  cin >> n;
  t = n - 1;
  vector<string> v;
  for (ll i = 2; i * i <= n; i++)
    while (n % i == 0) {
      v.push_back(to_string(i));
      n /= i;
    }
  if (n > 1)
    v.push_back(to_string(n));
  sort(v.begin(), v.end(), cmp);
  string a = "", b = "";
  for (string i : v)
    a += i;
  v.clear();
  while (t > 3) {
    v.push_back("2");
    t /= 2;
  }
  v.push_back(to_string(t));
  sort(v.begin(), v.end(), cmp);
  for (string i : v)
    b += i;
  if (a.size() > b.size()) {
    string tmp = "";
    while (tmp.size() < a.size() - b.size())
      tmp += '0';
    b = tmp + b;
  } else {
    string tmp = "";
    while (tmp.size() < b.size() - a.size())
      tmp += '0';
    a = tmp + a;
  }
  vector<int> ans(a.size() + 1, 0);
  for (int i = a.size() - 1; i >= 0; i--) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    if (x + y + ans[i + 1] < 10) {
      ans[i + 1] = x + y + ans[i + 1];
    } else {
      ans[i] = 1;
      ans[i + 1] = x + y + ans[i + 1] - 10;
    }
  }
  if (ans[0])
    for (int i : ans)
      cout << i;
  else
    for (int i = 1; i < ans.size(); i++)
      cout << ans[i];
  return 0;
}