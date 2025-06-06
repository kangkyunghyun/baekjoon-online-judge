#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int cnt = 1;
    while (1) {
        int n, ans = -1e12;
        cin >> n;
        if (!n)
            break;
        int arr[101][101] = {0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        // ㅣ
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 3; j++)
                ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);
        for (int i = 0; i < n - 3; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]);
        // ㄹ
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 2; j++)
                ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
        for (int i = 0; i < n - 2; i++)
            for (int j = 0; j < n - 1; j++)
                ans = max(ans, arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j]);
        // ㄴ
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 2; j++)
                ans = max(ans, max(arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2], arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]));
        for (int i = 0; i < n - 2; i++)
            for (int j = 0; j < n - 1; j++)
                ans = max(ans, max(arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j], arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1]));
        // ㅗ
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 2; j++)
                ans = max(ans, max(arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2], arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]));
        for (int i = 0; i < n - 2; i++)
            for (int j = 0; j < n - 1; j++)
                ans = max(ans, max(arr[i][j] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j], arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 1][j]));
        // ㅁ
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1; j++)
                ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
        cout << cnt++ << ". " << ans << '\n';
    }
}