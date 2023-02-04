// 17499: 수열과 시프트 쿼리
//
// - 문제
// 백준 온라인 저지를 여행하다 보면 하나의 수열이 주어지고 여기에 여러 가지 연산을 하는 문제들을 만나볼 수 있습니다.
// 진수는 백준 온라인 저지에서 문제를 풀다 다음과 같은 문제를 찾았습니다.
// 길이가 N인 정수 수열 [a1, a2, ..., aN] 이 주어진다. 다음과 같은 연산들을 수행한 후 수열을 출력하는 프로그램을 작성하시오.
// 1 i x : ai에 정수 x만큼 더한다.
// 2 s : 수열을 오른쪽으로 s칸 시프트한다.
// 3 s : 수열을 왼쪽으로 s칸 시프트한다.
// 수열을 오른쪽으로 한 칸 시프트하면 수열 [a1, a2, …, aN-1, aN] 은 [aN, a1, a2, …, aN-1] 이 되고
// 수열을 왼쪽으로 한 칸 시프트하면 수열 [a1, a2, …, aN-1, aN] 은 [a2, …, aN-1, aN, a1] 이 된다.
// 진수는 빠르게 코딩하여 제출하였는데 '시간 초과' 판정을 받았습니다.
// 진수가 작성한 코드는 시프트 연산을 수행할 때마다 반복문이 N번 실행되어 너무 느리기 때문입니다.
// 진수는 이 문제를 풀어 '맞았습니다!!' 를 띄워줄 누군가를 기다리고 있습니다.
//
// - 입력
// 첫 번째 줄에 수열의 길이 N (2 ≤ N ≤ 200,000) 과 연산의 개수 Q (1 ≤ Q ≤ 200,000) 가 주어집니다.
// 두 번째 줄에는 정수 a1, a2, ..., aN (-10,000 ≤ ai ≤ 10,000) 이 주어집니다.
// 다음 Q개의 줄에는 각 줄 마다 연산이 주어집니다.
//
// - 출력
// 첫 번째 줄에 Q개의 연산을 차례대로 수행한 후 a1, a2, …, aN 을 공백을 사이에 두고 출력합니다.
//
// - 제한
// 1 ≤ i ≤ N
// -10,000 ≤ x ≤ 10,000
// 1 ≤ s ≤ N-1

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, q, p = 0;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int i, t;
      cin >> i >> t;
      v[(i + p - 1) % n] += t;
    } else if (x == 2) {
      int t;
      cin >> t;
      p = (p + n - t) % n;
    } else {
      int t;
      cin >> t;
      p = (p + t) % n;
    }
  }
  if (p) {
    for (int i = p; i < n; i++)
      cout << v[i] << ' ';
    for (int i = 0; i < p; i++)
      cout << v[i] << ' ';
  } else {
    for (int i = 0; i < n; i++)
      cout << v[i] << ' ';
  }
  return 0;
}