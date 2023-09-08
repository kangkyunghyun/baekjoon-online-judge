#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> knapsack(k + 1, 0);
  while (n--) {
    int w, v;
    cin >> w >> v;
    for (int i = k; i >= w; i--)
      knapsack[i] = max(knapsack[i], knapsack[i - w] + v);
  }
  cout << knapsack[k];
  return 0;
}
// O(NK)