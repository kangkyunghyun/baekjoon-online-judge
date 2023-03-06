// 12020: LU 분해
//
// - 문제
//  (N times N) Matrix A가 주어진다. LU 분해란 (A = LU)꼴의 Matrix 곱로 분해하는 것이다. (단, (L)은 Lower Triangular Matrix, (U)는 Upper Triangular Matrix)
// Lower Triangular Matrix란 (L_{ij} = 0 text{ (if }i < jtext{)}) 
// Upper Triangular Matrix란 (U_{ij} = 0 text{ (if }i > jtext{)}) 
// 여기서 특이한 Matrix의 LU decomposition을 생각한다. Band Matrix란 대각성분이 띠 같은 모양을 이루고 있는 Matrix를 말한다. 여기서 우리는 Band의 폭이 1인 것만 생각한다. 즉
// (begin{bmatrix} b_1 & c_1 &  0 & dots & 0   a_2  & b_2 & c_2 & dots & vdots  0 & ddots & ddots & ddots & 0  vdots & ddots  & a_{n-1} & b_{n-1} & c_{n-1}   0 & dots & 0 & a_n & b_n end{bmatrix}) 의 꼴만 생각 한다.
// 더 이상의 자세한 설명은 생략한다. 행렬 (L)의 대각성분은 1이 되도록 하는 행렬 (L)과 (U)를 구하시오.
//
// - 입력
// 첫째 줄에는 정사각 행렬의 크기 N (1 ≤ N ≤ 1,000)이 주어지고 그 후 N줄에 차례대로 행렬의 성분이 주어진다.
//
// - 출력
// 먼저 N개의 줄에 (L)행렬을 출력한 후 그 다음 N개의 줄에 (U)행렬을 출력한다. 행렬 성분의 값은 소수 4째자리에서 반올림하여 3째자리 까지 출력한다. 만약 LU 분해가 불가능하거나 (U)의 대각 성분이 0이면 첫째 줄에 –1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  vector<vector<double>> L(1001, vector<double>(1001, 0)), U(1001, vector<double>(1001, 0));
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> U[i][j];
      L[i][j] = i == j ? 1 : 0;
    }
  for (int i = 0; i < n - 1; i++) {
    double d = U[i][i];
    for (int j = i + 1; j < n; j++) {
      double x = U[j][i] / d;
      for (int k = 0; k < n; k++)
        U[j][k] -= x * U[i][k];
      L[j][i] = x;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (isnan(L[i][j]) || isnan(U[i][j])) {
        cout << "-1\n";
        return 0;
      }
  cout.precision(3);
  cout << fixed;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << L[i][j] << ' ';
    cout << '\n';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << U[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}