#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Ingredient {
    int p, f, s, v, c;
};

int n, mp, mf, ms, mv, ans = 1e9;
vector<Ingredient> v;
vector<int> ing, visited, ansIng;

void dfs(int curr, Ingredient sum) {
    if (sum.p >= mp && sum.f >= mf && sum.s >= ms && sum.v >= mv && ans > sum.c) {
        ans = sum.c;
        ansIng = ing;
        return;
    }
    for (int i = curr + 1; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            ing.push_back(i);
            sum.p += v[i].p;
            sum.f += v[i].f;
            sum.s += v[i].s;
            sum.v += v[i].v;
            sum.c += v[i].c;
            dfs(i, sum);
            sum.p -= v[i].p;
            sum.f -= v[i].f;
            sum.s -= v[i].s;
            sum.v -= v[i].v;
            sum.c -= v[i].c;
            visited[i] = 0;
            ing.pop_back();
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> mp >> mf >> ms >> mv;
    v.resize(n);
    visited.resize(n, 0);
    for (auto &[p, f, s, v, c] : v)
        cin >> p >> f >> s >> v >> c;
    Ingredient tmp = {0, 0, 0, 0, 0};
    dfs(-1, tmp);
    if (ans == 1e9) {
        cout << -1;
    } else {
        cout << ans << '\n';
        for (int i : ansIng)
            cout << i + 1 << ' ';
    }
}