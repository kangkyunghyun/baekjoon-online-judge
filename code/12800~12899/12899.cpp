#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 2000000

int n, q, x;
vector<int> t;

void update(int p, int v) {
    for (t[p += MAX] += v; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

// [l, r)
int query(int l, int r) {
    int res = 0;
    for (l += MAX, r += MAX; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    t.resize(2 * MAX);
    while (n--) {
        cin >> q >> x;
        if (q == 1) {
            update(x - 1, 1);
        } else {
            int l = 0, r = MAX;
            while (l <= r) {
                if (l == r - 1) {
                    cout << l + 1 << '\n';
                    update(l, -1);
                    break;
                }
                int mid = (l + r) / 2;
                int left = query(l, mid);
                int right = query(mid + 1, r);
                if (left < x) {
                    l = mid;
                    x -= left;
                } else {
                    r = mid;
                }
            }
        }
    }
}