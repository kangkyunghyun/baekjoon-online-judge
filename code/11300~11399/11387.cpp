#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int arr[4][5];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    int currA = arr[0][0] * (100 + arr[0][1]) * (100 * (100 - min(arr[0][2], (int)100)) + min(arr[0][2], (int)100) * arr[0][3]) * (100 + arr[0][4]);
    int currB = arr[1][0] * (100 + arr[1][1]) * (100 * (100 - min(arr[1][2], (int)100)) + min(arr[1][2], (int)100) * arr[1][3]) * (100 + arr[1][4]);
    for (int i = 0; i < 5; i++) {
        arr[0][i] = arr[0][i] - arr[2][i] + arr[3][i];
        arr[1][i] = arr[1][i] - arr[3][i] + arr[2][i];
    }
    int newA = arr[0][0] * (100 + arr[0][1]) * (100 * (100 - min(arr[0][2], (int)100)) + min(arr[0][2], (int)100) * arr[0][3]) * (100 + arr[0][4]);
    int newB = arr[1][0] * (100 + arr[1][1]) * (100 * (100 - min(arr[1][2], (int)100)) + min(arr[1][2], (int)100) * arr[1][3]) * (100 + arr[1][4]);
    if (newA > currA)
        cout << '+';
    else if (newA < currA)
        cout << '-';
    else
        cout << '0';
    cout << '\n';
    if (newB > currB)
        cout << '+';
    else if (newB < currB)
        cout << '-';
    else
        cout << '0';
}