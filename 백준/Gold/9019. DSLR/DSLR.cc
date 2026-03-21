#include <bits/stdc++.h>
using namespace std;

int A, B;
vector<pair<int, string>> visited(10000, {0, ""});

int rotate(int n, int x) {
  int a = n / 1000;
  int b = (n % 1000) / 100;
  int c = (n % 100) / 10;
  int d = n % 10;
  return x ? b * 1000 + c * 100 + d * 10 + a : d * 1000 + a * 100 + b * 10 + c;
}

void bfs() {
  queue<int> q;
  q.push(A);
  visited[A] = {1, ""};
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    if (n == B) {
      cout << visited[B].second << '\n';
      break;
    }
    int D = (n * 2) % 10000;
    if (!visited[D].first) {
      visited[D] = {visited[n].first + 1, visited[n].second + 'D'};
      q.push(D);
    }
    int S = n ? n - 1 : 9999;
    if (!visited[S].first) {
      visited[S] = {visited[n].first + 1, visited[n].second + 'S'};
      q.push(S);
    }
    int L = rotate(n, 1);
    if (!visited[L].first) {
      visited[L] = {visited[n].first + 1, visited[n].second + 'L'};
      q.push(L);
    }
    int R = rotate(n, 0);
    if (!visited[R].first) {
      visited[R] = {visited[n].first + 1, visited[n].second + 'R'};
      q.push(R);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    fill(visited.begin(), visited.end(), pair<int, string>{0, ""});
    cin >> A >> B;
    bfs();
  }
  return 0;
}