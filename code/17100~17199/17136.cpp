#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 101

int arr[10][10], ans = MAX, paper[] = {0, 5, 5, 5, 5, 5};

int check(int x, int y, int size) {
    if (x + size > 10 || y + size > 10)
        return 0;
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            if (!arr[i][j])
                return 0;
    return 1;
}

void dfs(int x, int y, int cnt) {
    if (x == 10) {
        ans = min(ans, cnt);
        return;
    }
    if (cnt >= ans)
        return;
    if (arr[x][y])
        for (int i = 5; i > 0; i--) {
            if (paper[i] && check(x, y, i)) {
                for (int j = x; j < x + i; j++)
                    for (int k = y; k < y + i; k++)
                        arr[j][k] = 0;
                paper[i]--;
                if (y == 9)
                    dfs(x + 1, 0, cnt + 1);
                else
                    dfs(x, y + 1, cnt + 1);
                paper[i]++;
                for (int j = x; j < x + i; j++)
                    for (int k = y; k < y + i; k++)
                        arr[j][k] = 1;
            }
        }
    else if (y == 9)
        dfs(x + 1, 0, cnt);
    else
        dfs(x, y + 1, cnt);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> arr[i][j];
    dfs(0, 0, 0);
    cout << (ans == MAX ? -1 : ans);
}