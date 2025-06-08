#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, K;
deque<pair<int, pair<int, int>>> edge;
vector<int> p, banned;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y)
        p[y] = x;
    else
        p[x] = y;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    p.resize(N + 1);
    banned.resize(M + 1, 0);
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        edge.push_back({i, {x, y}});
    }
    int flag = 0;
    while (K--) {
        int minWeight = 999, ans = 0;
        if (!flag) {
            iota(p.begin(), p.end(), 0);
            for (auto [weight, path] : edge) {
                if (banned[weight] != 1 && find(path.first) != find(path.second)) {
                    ans += weight;
                    minWeight = min(minWeight, weight);
                    merge(path.first, path.second);
                }
            }
        }
        for (int i = 2; i <= N; i++)
            if (find(i) != 1)
                flag = 1;
        cout << (flag ? 0 : ans) << ' ';
        banned[minWeight] = 1;
    }
    return 0;
}