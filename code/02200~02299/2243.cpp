#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1000000

int n;
vector<int> t;

void init() {
    for (int i = MAX - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

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
    t.resize(2 * MAX);
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b;
        if (a == 1) {
            int l = 0, r = MAX;
            while (l <= r) {
                if (l == r - 1) {
                    cout << l + 1 << '\n';
                    update(l, -1);
                    break;
                }
                int mid = (l + r) / 2;
                int left = query(l, mid);
                int right = query(mid, r);
                if (left < b) {
                    l = mid;
                    b -= left;
                } else {
                    r = mid;
                }
            }
        } else {
            cin >> c;
            update(b - 1, c);
        }
    }
}