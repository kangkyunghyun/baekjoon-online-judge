// 4839: 소진법
//
// - 문제
// 2보다 크거나 같은 자연수 b가 주어졌을 때, 모든 양의 정수 n을 b진법으로 표현하는 방법은 유일하다.
// n = a0 + a1*b + a2*b*b + a3*b*b*b + ...
// 여기서 a0, a1, a2, a3, ...은 0보다 크거나 같고, b-1보다 작거나 같은 값을 가진다.
// p0=2, p1=3, p2=5, ... 과 같이 pi를 i번째 소수라고 했을 때, 모든 양의 정수 n도 소수를 이용한 진법으로 유일하게 표현할 수 있다. 이를 소진법이라고 한다.
// n = a0 + a1*p0 + a2*p0*p1 + a3*p0*p1*p2 + ...
// 여기서 a0, a1, a2, a3, ...은 0보다 크거나 같고, pi-1보다 작거나 같은 값을 가진다. 예를 들면, a3은 0보다 크거나 같고, p3-1보다 작거나 같다.
// 양의 정수 n이 주어졌을 때, 이를 소진법으로 나타내는 프로그램을 작성하시오.
//
// - 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n을 포함하고 있다. n은 양의 정수로 231-1보다 작거나 같다. 마지막 줄에는 0이 주어진다.
//
// - 출력
// 각 테스트 케이스에 대해서, 입력으로 주어진 수, 공백, 등호, 공백을 출력하고 문제 설명에 나온 것 같이 소진법으로 나타내 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int n;
    cin >> n;
    int origin = n;
    if (!n)
      break;
    vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23}, v;
    int now = 1;
    for (int i = 0; i < prime.size(); i++) {
      now *= prime[i];
      v.push_back(now);
    }
    vector<string> ans;
    for (int i = v.size() - 1; i >= 0; i--) {
      if (v[i] <= n) {
        int cnt = n / v[i];
        n %= v[i];
        string tmp = to_string(cnt);
        for (int j = 0; j <= i; j++) {
          tmp += "*" + to_string(prime[j]);
        }
        ans.push_back(tmp);
      }
    }
    cout << origin << " = ";
    if (n > 0)
      cout << n;
    for (int i = ans.size() - 1; i >= 0; i--) {
      if (i != ans.size() - 1 || n > 0)
        cout << " + ";
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}