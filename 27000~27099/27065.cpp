// 27065: 2022년이 아름다웠던 이유
//
// - 문제
// Good Bye, BOJ 2022! 대회는 2022년의 끝을 기념하는 알고리즘 문제해결 대회이다.  leejseo라는 핸들을 사용하는 종서는 자신의 22번째 생일인 2022년 12월 31일에 Good Bye, BOJ 2022!를 개최하기로 결심했다.
// 정휘는 Good Bye, BOJ 2022!가 개최된다는 소식에 기뻐 제목을 뚫어져라 보다가, 2022가 정말 아름다운 수라는 사실을 깨달았다.
// 자기 자신을 제외한 약수들의 합이 자기 자신보다 작은 수를 부족수, 자기 자신보다 큰 수를 과잉수, 자기 자신과 같은 수를 완전수라고 하자.
// 그러면 2022는 과잉수이면서 2022의 자기 자신을 제외한 모든 약수는 모두 부족수이거나 완전수이다. 과잉과 부족의 조화라니, 이 얼마나 아름다운 수인가! 다음에 이런 년도가 오려면 2044년이 되어야 한다.
// 양의 정수 n이 주어진다. n이 과잉수이면서 n을 제외한 n의 모든 약수가 부족수이거나 완전수인지 판별하는 프로그램을 작성하여라.
//
// - 입력
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
// 이후 T개의 줄에 걸쳐 테스트 케이스가 한 줄에 하나씩 주어진다. 각 테스트 케이스는 한 줄로 구성되며, 각각 한 개의 양의 정수 n이 주어진다.
//
// - 출력
// 각 테스트 케이스에 대해, n이 과잉수이면서 n을 제외한 n의 모든 약수가 부족수이거나 완전수라면 Good Bye, 그렇지 않다면 BOJ 2022를 한 줄에 하나씩 차례로 출력하여라.

#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
  vector<int> v;
  for (int i = 1; i <= n; i++)
    if (n % i == 0)
      v.push_back(i);
  int sum = 0;
  for (int i = 0; i < v.size() - 1; i++)
    sum += v[i];
  if (sum > n)
    return true;
  else
    return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
      if (n % i == 0)
        v.push_back(i);
    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++)
      sum += v[i];
    if (sum <= n) {
      cout << "BOJ 2022\n";
    } else {
      int cnt = 0;
      for (int i = 0; i < v.size() - 1; i++)
        if (!check(v[i]))
          cnt++;
      if (cnt == v.size() - 1)
        cout << "Good Bye\n";
      else
        cout << "BOJ 2022\n";
    }
  }
  return 0;
}