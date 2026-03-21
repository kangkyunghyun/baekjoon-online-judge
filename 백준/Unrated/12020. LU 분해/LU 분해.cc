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
      for (int k = 0; k < n; k++) {
        U[j][k] -= x * U[i][k];
      }
      L[j][i] = x;
    }
  }
  for (int i = 0, j = 0; i < n; i++, j++)
    if (L[i][j] != 1) {
      cout << "-1\n";
      return 0;
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