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