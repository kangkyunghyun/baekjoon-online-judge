// 1145: 적어도 대부분의 배수
//
// - 문제
// 다섯 개의 자연수가 있다. 이 수의 적어도 대부분의 배수는 위의 수 중 적어도 세 개로 나누어 지는 가장 작은 자연수이다.
// 서로 다른 다섯 개의 자연수가 주어질 때, 적어도 대부분의 배수를 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 다섯 개의 자연수가 주어진다. 100보다 작거나 같은 자연수이고, 서로 다른 수이다.
//
// - 출력
// 첫째 줄에 적어도 대부분의 배수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> v(5);
  for (int i = 0; i < 5; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int n = v[0];
  while (1) {
    int cnt = 0;
    for (int i = 0; i < 5; i++)
      if (n % v[i] == 0)
        cnt++;
    if (cnt >= 3)
      break;
    n++;
  }
  cout << n;
  return 0;
}