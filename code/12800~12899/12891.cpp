#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int sSize, pSize, a[4], ans = 0;
    string s;
    cin >> sSize >> pSize >> s;
    for (int &i : a)
        cin >> i;
    int tmp[4] = {0};
    for (int i = 0; i < pSize; i++)
        if (s[i] == 'A')
            tmp[0]++;
        else if (s[i] == 'C')
            tmp[1]++;
        else if (s[i] == 'G')
            tmp[2]++;
        else if (s[i] == 'T')
            tmp[3]++;
    for (int i = pSize; i < sSize; i++) {
        int flag = 1;
        for (int j = 0; j < 4; j++)
            if (tmp[j] < a[j]) {
                flag = 0;
                break;
            }
        if (flag)
            ans++;
        if (s[i] == 'A')
            tmp[0]++;
        else if (s[i] == 'C')
            tmp[1]++;
        else if (s[i] == 'G')
            tmp[2]++;
        else if (s[i] == 'T')
            tmp[3]++;
        if (s[i - pSize] == 'A')
            tmp[0]--;
        else if (s[i - pSize] == 'C')
            tmp[1]--;
        else if (s[i - pSize] == 'G')
            tmp[2]--;
        else if (s[i - pSize] == 'T')
            tmp[3]--;
    }
    int flag = 1;
    for (int j = 0; j < 4; j++)
        if (tmp[j] < a[j]) {
            flag = 0;
            break;
        }
    if (flag)
        ans++;
    cout << ans;
}