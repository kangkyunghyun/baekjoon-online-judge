// 2740: 행렬 곱셈
//
// - 문제
// N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다.
// 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.
//
// - 출력
// 첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k, input;
  vector<vector<int>> A, B, C;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int j = 0; j < m; j++) {
      cin >> input;
      temp.push_back(input);
    }
    A.push_back(temp);
  }
  cin >> m >> k;
  for (int i = 0; i < m; i++) {
    vector<int> temp;
    for (int j = 0; j < k; j++) {
      cin >> input;
      temp.push_back(input);
    }
    B.push_back(temp);
  }
  for (int h = 0; h < n; h++) {
    vector<int> temp;
    for (int i = 0; i < k; i++) {
      int sum = 0;
      for (int j = 0; j < m; j++)
        sum += A[h][j] * B[j][i];
      temp.push_back(sum);
    }
    C.push_back(temp);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++)
      cout << C[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}