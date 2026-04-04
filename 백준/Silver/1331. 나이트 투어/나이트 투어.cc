#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int arr[6][6] = {0};
    string ans = "Valid";
    int preX, preY, firstX, firstY;
    for (int i = 1; i <= 36; i++) {
        string s;
        cin >> s;
        int x = s[0] - 'A', y = s[1] - '1';
        if (i == 1) {
            firstX = x, firstY = y;
        }
        if ((i == 1 || (abs(preX - x) == 2 && abs(preY - y) == 1) || (abs(preX - x) == 1 && abs(preY - y) == 2)) && !arr[x][y]) {
            arr[x][y] = i;
        } else {
            ans = "Invalid";
            break;
        }
        preX = x;
        preY = y;
    }
    if (!((abs(preX - firstX) == 2 && abs(preY - firstY) == 1) || (abs(preX - firstX) == 1 && abs(preY - firstY) == 2)))
        ans = "Invalid";
    cout << ans;
}