#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string s, ans = "";
        cin >> s;
        int arr[26] = {0};
        for (char c : s)
            arr[c-'A']++;
        while (arr['Z'-'A']) {
            ans += '0';
            arr['Z'-'A']--;
            arr['E'-'A']--;
            arr['R'-'A']--;
            arr['O'-'A']--;
        }
        while (arr['W'-'A']) {
            ans += '2';
            arr['T'-'A']--;
            arr['W'-'A']--;
            arr['O'-'A']--;
        }
        while (arr['X'-'A']) {
            ans += '6';
            arr['S'-'A']--;
            arr['I'-'A']--;
            arr['X'-'A']--;
        }
        while (arr['S'-'A']) {
            ans += '7';
            arr['S'-'A']--;
            arr['E'-'A']--;
            arr['V'-'A']--;
            arr['E'-'A']--;
            arr['N'-'A']--;
        }
        while (arr['V'-'A']) {
            ans += '5';
            arr['F'-'A']--;
            arr['I'-'A']--;
            arr['V'-'A']--;
            arr['E'-'A']--;
        }
        while (arr['U'-'A']) {
            ans += '4';
            arr['F'-'A']--;
            arr['O'-'A']--;
            arr['U'-'A']--;
            arr['R'-'A']--;
        }
        while (arr['G'-'A']) {
            ans += '8';
            arr['E'-'A']--;
            arr['I'-'A']--;
            arr['G'-'A']--;
            arr['H'-'A']--;
            arr['T'-'A']--;
        }
        while (arr['T'-'A']) {
            ans += '3';
            arr['T'-'A']--;
            arr['H'-'A']--;
            arr['R'-'A']--;
            arr['E'-'A']--;
            arr['E'-'A']--;
        }
        while (arr['O'-'A']) {
            ans += '1';
            arr['O'-'A']--;
            arr['N'-'A']--;
            arr['E'-'A']--;
        }
        while (arr['N'-'A']) {
            ans += '9';
            arr['N'-'A']--;
            arr['I'-'A']--;
            arr['N'-'A']--;
            arr['E'-'A']--;
        }
        sort(ans.begin(), ans.end());
        cout << "Case #" << i << ": " << ans << '\n';
    }
}