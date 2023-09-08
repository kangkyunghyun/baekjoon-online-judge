// 6884: 소수 부분 수열
//
// - 문제
// 양의 정수로 이루어진 길이가 n인 수열이 있다. 소수 부분 수열이란 길이가 적어도 2이면서, 합이 2보다 크거나 같은 소수가 되는 연속 부분 수열이다.
// 예를 들어, 수열이 [3, 5, 6, 3, 8] 일 때, 길이가 2인 소수 부분 수열이 두 개(5 + 6 = 11, 3 + 8 = 11)이 있고, 길이가 3인 소수 부분 수열은 1개 (6 + 3 + 8 = 17), 길이가 4인 소수 부분 수열은 1개 (3 + 5 + 6 + 3 = 17) 가 있다.
// 수열이 주어졌을 때, 길이가 가장 짧은 소수 부분 수열을 구하는 프로그램을 작성하시오.
//
// - 입력
// 입력의 첫째 줄에는 테스트 케이스의 개수 t (1 ≤ t ≤ 20) 가 주어진다.
// 각 테스트 케이스는 한 줄로 이루어져 있고, 줄의 첫 번째 정수 n은 (0 < n ≤ 10000) 수열의 길이이다. 다음에 주어지는 정수 n개는 수열의 원소이다. 수열의 원소는 10000보다 작거나 같은 음이 아닌 정수이다.
//
// - 출력
// 각 테스트 케이스마다 가장 짧은 소수 부분 수열의 길이가 x라면 "Shortest primed subsequence is length x:"를 출력하고, 그 수열 공백으로 구분해 출력한다. 가장 짧은 소수 부분 수열이 여러 가지면, 먼저 나오는 것을 출력한다.
// 소수 부분 수열이 없는 경우에는 "This sequence is anti-primed."를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int isPrime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
      return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, tmp = 0;
    cin >> n;
    vector<int> v(n), sum;
    sum.push_back(0);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      tmp += v[i];
      sum.push_back(tmp);
    }
    int size = 2, flag = 0;
    while (size <= n) {
      for (int i = 1, j = i + size - 1; j <= n; i++, j++) {
        int s = sum[j] - sum[i - 1];
        if (isPrime(s)) {
          cout << "Shortest primed subsequence is length " << size << ": ";
          for (int k = i - 1; k < j; k++)
            cout << v[k] << ' ';
          cout << '\n';
          flag = 1;
          break;
        }
      }
      if (flag)
        break;
      size++;
    }
    if (!flag)
      cout << "This sequence is anti-primed.\n";
  }
  return 0;
}