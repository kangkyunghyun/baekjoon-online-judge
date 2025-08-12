#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 400001
#define MOD 1'000'000'007

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

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    t.resize(2 * MAX);
    vector<pair<int, int>> stars;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        stars.push_back({x + 200000, y});
    }
    sort(stars.begin(), stars.end(), cmp);
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; i++) {
        auto [x, y] = stars[i];
        if (i != 0 && y != stars[i - 1].second) {
            for (auto [xx, yy] : tmp)
                update(xx, 1);
            tmp.clear();
        }
        ans = (ans + (query(0, x) * query(x + 1, MAX + 1)) % MOD) % MOD;
        tmp.push_back(stars[i]);
    }
    cout << ans;
}