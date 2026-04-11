#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a;
        int A[5] = {0}, B[5] = {0};
        for (int i = 0, x; i < a; i++) {
            cin >> x;
            A[x]++;
        }
        cin >> b;
        for (int i = 0, x; i < b; i++) {
            cin >> x;
            B[x]++;
        }
        char ans = 'A';
        if (A[4] < B[4]) {
            ans = 'B';
        } else if (A[4] == B[4]) {
            if (A[3] < B[3]) {
                ans = 'B';
            } else if (A[3] == B[3]) {
                if (A[2] < B[2]) {
                    ans = 'B';
                } else if (A[2] == B[2]) {
                    if (A[1] < B[1]) {
                        ans = 'B';
                    } else if (A[1] == B[1]) {
                        ans = 'D';
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}