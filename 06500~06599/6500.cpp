// 6500: 랜덤 숫자 만들기
//
// - 문제
// 존 폰 노이만은 1946년에 유사난수(Pseudo-random Number) 수열을 만드는 방법을 제시했다. 이 방법은 "middle-square" 방법으로 알려져 있으며, 다음과 같이 동작한다.
// 먼저, 초기값 a0을 고른다. a0은 십진법으로 표기했을 때, 길이가 n을 넘지 않아야 한다. 그 다음, a0을 제곱한 다음에, 길이가 2*n이 될 때 까지 앞에 0을 붙인다. 이제, 가운데 n자리를 ai라고 한다. 이 방법을 사용해 각각의 i>0에 대해서, ai를 계산할 수 있다. 이 문제에서 n=4를 이용한다.
// 예 1: a0 = 5555, a02 = 30858025, a1 = 8580
// 예 2: a0 = 1111, a02 = 01234321, a1 = 2343
// 사실 이 방법은 난수를 만드는데 그렇게 좋은 방법은 아니다.
// a0이 주어졌을 때, 서로 다른 난수를 몇 개 만드는지 구하는 프로그램을 작성하시오.
//
// - 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄이며, a0을 포함하고 있다. (0 < a0 < 10000) 숫자가 네 자리가 아닌 경우에는, 앞에 0을 추가해 네 자리로 만들어져 있다. 입력의 마지막 줄에는 0이 하나 주어진다.
//
// - 출력
// 각 테스트 케이스에 대해서, 서로 다른 ai가 몇 개 나오는지 출력한다. a0도 포함해서 세야 한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int n;
    cin >> n;
    if (!n)
      break;
    vector<int> v;
    v.push_back(n);
    n *= n;
    while (1) {
      string s = to_string(n);
      while (s.size() < 8)
        s = "0" + s;
      n = stoi(s.substr(2, 4));
      if (find(v.begin(), v.end(), n) != v.end())
        break;
      v.push_back(n);
      n *= n;
    }
    cout << v.size() << '\n';
  }
  return 0;
}