#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  while (t--) {
    string s[8];
    int visited[8][8] = {0};
    for (int i = 0; i < 8; i++)
      cin >> s[i];
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++) {
        if (s[i][j] != '.') {
          cout << s[i][j];
          visited[i][j] = 1;
          for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
              continue;
            if (s[nx][ny] == '.' || visited[nx][ny])
              continue;
            else {
              cout << s[nx][ny];
              visited[nx][ny] = 1;
              i = nx;
              j = ny;
            }
          }
        }
      }
    cout << '
';
  }
  return 0;
}