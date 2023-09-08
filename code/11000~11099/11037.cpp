// 11037: 중복 없는 수
//
// - 문제
// 중복 없는 수는 각 숫자(1, 2, 3, ..., 9)가 최대 한 번씩 등장하고, 숫자 0은 포함하지 않는 수이다. 따라서 중복 없는 수는 최대 9자리로 이루어질 수 있다. 중복 없는 수의 예시로는 9, 32, 489, 98761, 983245 등이 있다.
// 정수 N이 주어질 때, N보다 크면서 가장 작은 중복 없는 수를 출력하는 프로그램을 작성하라.
//
// - 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 정수 N(0 ≤ N ≤ 999,999,999)이 주어진다.
//
// - 출력
// 각 테스트 케이스마다 답을 출력한다. 만약 답에 해당하는 수가 없는 경우는 0을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  while (cin >> n) {
    int flag = 0;
    for (int i = n + 1; i <= 999999999; i++) {
      string num = to_string(i);
      if (num.find('0') == string::npos) {
        vector<int> check(10, 0);
        for (int j = 0; j < num.size(); j++) {
          int a = num[j] - '0';
          if (check[a] >= 1)
            break;
          else
            check[a]++;

          if (j == num.size() - 1) {
            cout << num << '\n';
            flag = 1;
            break;
          }
        }
      }
      if (flag)
        break;
    }
    if (!flag)
      cout << 0 << '\n';
  }
  return 0;
}