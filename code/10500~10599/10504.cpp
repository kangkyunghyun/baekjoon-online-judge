// 10504: 덧셈
//
// - 문제
// 학기 시작을 앞두고, 광현이는 숫자놀음에 빠져버렸다. 펜을 굴리다 문득 연속되는 수로 표현되지 못하는 수는 뭐가 있을까 갑자기 궁금해졌다. 하나씩 세고 있던 광현이가 안쓰러운 승균이는 빼어난 코딩실력으로 답을 알려주려 한다.
// 정수 N이 주어지면, 두 개 이상의 연속되는 양의 정수의 합으로 나타내는 프로그램을 작성하시오.
// 예를 들면, 10 = 1 + 2 + 3 + 4 로 표현 가능하고, 24 = 7 + 8 + 9 로 표현 가능하다.
// 만약 여러 개의 표현이 존재한다면, 가장 짧은 표현을 출력한다.
//
// - 입력
// 첫 번째 줄에 테스트케이스 T가 주어진다.
// 다음 T개의 줄에 걸쳐서 한 줄씩 정수 N (1 ≤ N ≤ 109) 가 주어진다.
//
// - 출력
// 각 테스트케이스마다 한 줄씩 아래의 예와 같이 정답을 출력한다.
// N = a + (a+1) + ... + b
// 만약 표현이 존재하지 않다면, IMPOSSIBLE 을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i = 2;
    cin >> n;
    int x = n / i;
    while (1) {
      if (x - (i / 2) < 0) {
        cout << "IMPOSSIBLE\n";
        break;
      }
      if (i % 2) {
        if (!(n % i)) {
          cout << n << " = ";
          for (int j = x - (i / 2); j < x + (i / 2); j++)
            cout << j << " + ";
          cout << x + (i / 2) << '\n';
          break;
        }
      } else {
        if (n % i == i / 2) {
          cout << n << " = ";
          for (int j = x - (i / 2) + 1; j < x + (i / 2); j++)
            cout << j << " + ";
          cout << x + (i / 2) << '\n';
          break;
        }
      }
      i++;
      x = n / i;
    }
  }
  return 0;
}