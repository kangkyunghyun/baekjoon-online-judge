#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, t = 0;
int arr[50][50];

void row(int a, int b) {
    for (int i = 0; i < m; i++)
        swap(arr[a][i], arr[b][i]);
}

void col(int a, int b) {
    for (int i = 0; i < n; i++)
        swap(arr[i][a], arr[i][b]);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i][0] > arr[j][0])
                row(i, j);
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (arr[0][i] > arr[0][j])
                col(i, j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < t) {
                cout << 0;
                return 0;
            }
            t = arr[i][j];
        }
    cout << 1;
}