#include <bits/stdc++.h>
using namespace std;

int n;
bool flag = 0;
vector<int> v(5001), visited(5001, 0);

bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

void dfs(int cnt, int sum) {
  if (cnt == n) {
    cout << "YES\n";
    for (int i = 0; i < n; i++)
      cout << v[i] << ' ';
    flag = 1;
    return;
  }
  for (int i = 1; !flag && i <= n; i++) {
    if (!visited[i] && !isPrime(sum + i)) {
      visited[i] = 1;
      v[cnt] = i;
      dfs(cnt + 1, sum + i);
      visited[i] = 0;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  dfs(0, 0);
  if (!flag)
    cout << "NO";
}