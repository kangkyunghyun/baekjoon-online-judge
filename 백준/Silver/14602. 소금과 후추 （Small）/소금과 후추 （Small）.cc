#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int m, n, k, w;
    cin >> m >> n >> k >> w;
    int arr[30][30];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int i = 0; i < m - w + 1; i++) {
        for (int j = 0; j < n - w + 1; j++) {
            vector<int> tmp;
            for (int x = 0; x < w; x++)
                for (int y = 0; y < w; y++)
                    tmp.push_back(arr[i + x][j + y]);
            sort(tmp.begin(), tmp.end());
            cout << tmp[tmp.size() / 2] << ' ';
        }
        cout << '\n';
    }
}