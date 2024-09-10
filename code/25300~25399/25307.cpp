#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    queue<pair<int,int>> q;
    cin >> n >> m >> k;
    vector<vector<int>> board(n,vector<int>(m)), dist(n,vector<int>(m,0)), visited(n,vector<int>(m,0));
    int sx, sy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 4) {
                sx = i, sy = j;
            } else if (board[i][j] == 3) {
                q.push({i,j});
            }
        }
    int mannequin = q.size();
    while(!q.empty()) {
        pair<int,int> curr = q.front();
        int xx = curr.first;
        int yy = curr.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (!dist[nx][ny] && board[nx][ny] != 3) {
                dist[nx][ny] = dist[xx][yy] + 1;
                q.push({nx,ny});
            }
        }
    }
    q.push({sx,sy});
    while(!q.empty()) {
        pair<int,int> curr = q.front();
        int xx = curr.first;
        int yy = curr.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (!visited[nx][ny] && (mannequin ? dist[nx][ny] > k : true) && board[nx][ny] != 1) {
                visited[nx][ny] = visited[xx][yy] + 1;
                q.push({nx,ny});
                if (board[nx][ny] == 2) {
                    cout << visited[nx][ny];
                    return 0;
                }
            }
        }
    }
    cout<<-1;
}