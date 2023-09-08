// 1790: 수 이어 쓰기 2
//
// - 문제
// 1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.
// 1234567891011121314151617181920212223...
// 이렇게 만들어진 새로운 수에서, 앞에서 k번째 자리 숫자가 어떤 숫자인지 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N(1 ≤ N ≤ 100,000,000)과,  k(1 ≤ k ≤ 1,000,000,000)가 주어진다. N과 k 사이에는 공백이 하나 이상 있다.
//
// - 출력
// 첫째 줄에 앞에서 k번째 자리 숫자를 출력한다. 수의 길이가 k보다 작아서 k번째 자리 숫자가 없는 경우는 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int sum = 0, c = 1, d = 10, ans = -1;
  for (int i = 1; i <= n; i++) {
    if (i % d == 0) {
      d *= 10;
      c++;
    }
    sum += c;
    if (sum >= k) {
      string s = to_string(i);
      int index = s.size() - sum + k - 1;
      ans = s[index] - '0';
      break;
    }
  }
  cout << ans;
  return 0;
}