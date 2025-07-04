#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        string s, ans = "";
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '@':
                cnt++;
                ans += 'a';
                break;
            case '[':
                cnt++;
                ans += 'c';
                break;
            case '!':
                cnt++;
                ans += 'i';
                break;
            case ';':
                cnt++;
                ans += 'j';
                break;
            case '^':
                cnt++;
                ans += 'n';
                break;
            case '0':
                cnt++;
                ans += 'o';
                break;
            case '7':
                cnt++;
                ans += 't';
                break;
            case '\\':
                if (s[i + 1] == '\'') {
                    cnt++;
                    ans += 'v';
                    i++;
                } else if (s[i + 1] == '\\' && s[i + 2] == '\'') {
                    cnt++;
                    ans += 'w';
                    i += 2;
                }
                break;
            default:
                ans += s[i];
                break;
            }
        }
        cout << (cnt >= (ans.size() + 1) / 2 ? "I don't understand" : ans) << '\n';
    }
}