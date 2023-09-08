// 27648: 증가 배열 만들기
//
// - 문제
// N \times M 크기의 2차원 배열이 있다. 당신은 배열의 각 칸에 1 이상 K 이하의 정수를 채워 넣어 배열을 증가 상태로 만들고자 한다.
// 배열이 증가 상태라는 것은 \left(1, 1\right)에서 출발해서 \left(N, M\right)을 향해 오른쪽이나 아래쪽으로 이동할 때 가능한 모든 경로에 대해, 각 경로에서 방문한 칸의 수를 처음부터 일렬로 나열한 수열이 오름차순임을 의미한다.
// 오른쪽이나 아래쪽으로 이동한다는 것은, \left(i, j\right)에서 \left(i, j + 1\right)와 \left(i + 1, j\right)로 움직인다는 것이다. 단, 배열 밖으로는 이동할 수 없다.
// 수열 A_{1}, A_{2}, \dots, A_{k} 가 오름차순이라는 것은 A_{1} \lt A_{2} \lt \cdots \lt A_{k} 임을 의미한다.
//
// - 입력
// 첫째 줄에 N, M, K가 주어진다.  \left(1 \le N , M \le 1\,000,1 \le K \le 100\,000 \right) 
//
// - 출력
// 조건에 맞는 배열이 존재하면 첫 번째 줄에 YES를 출력하고 두 번째 줄부터 N개의 각 줄에 1 이상 K 이하의 수 M개를 공백으로 구분하여 출력하라. 조건에 맞는 배열이 여러 개일 경우 그중 하나만 출력한다.
// 그런 배열이 존재하지 않으면 NO를 출력하라.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  if (k < n + m - 1) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << i + j + 1 << ' ';
    cout << '\n';
  }
  return 0;
}