// 9613: GCD 합
//
// - 문제
// 양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다.
// 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1,000,000을 넘지 않는다.
//
// - 출력
// 각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    vector<int> arr;
    int n, a;
    long long sum = 0;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a;
      arr.push_back(a);
    }
    for (int j = 0; j < arr.size(); j++)
      for (int k = j + 1; k < arr.size(); k++)
        sum += gcd(arr[j], arr[k]);
    cout << sum << '\n';
  }
  return 0;
}