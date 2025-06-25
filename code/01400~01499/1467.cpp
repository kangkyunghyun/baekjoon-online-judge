#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string num, del, ans = "";
    int delCount[10] = {0}, numCount[10] = {0}, idx = 0;
    cin >> num >> del;
    for (char i : num)
        numCount[i - '0']++;
    for (char i : del) {
        delCount[i - '0']++;
        numCount[i - '0']--;
    }
    for (int i = 0; i < num.length() - del.length(); i++) {
        for (int j = 9; j >= 0; j--) {
            if (!numCount[j])
                continue;
            vector<int> tmp(10, 0);
            for (int k = idx; num[k] - '0' != j; k++)
                tmp[num[k] - '0']++;
            int flag = 1;
            for (int i = 0; i < 10; i++)
                if (tmp[i] > delCount[i]) {
                    flag = 0;
                    break;
                }
            if (flag) {
                while (num[idx] - '0' != j) {
                    delCount[num[idx] - '0']--;
                    idx++;
                }
                idx++;
                ans += j + '0';
                numCount[j]--;
                break;
            }
        }
    }
    cout << ans;
}