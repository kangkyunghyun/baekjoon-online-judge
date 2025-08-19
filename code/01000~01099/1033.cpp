#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, L = 1, G;
vector<pair<int, pair<int, int>>> edge[10];
int arr[10], visited[10];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void dfs(int curr) {
    visited[curr] = 1;
    for (auto [next, ratio] : edge[curr]) {
        if (!visited[next]) {
            auto [p, q] = ratio;
            arr[next] = arr[curr] / p * q;
            dfs(next);
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        edge[a].push_back({b, {p, q}});
        edge[b].push_back({a, {q, p}});
        L *= lcm(p, q);
    }
    arr[0] = L;
    dfs(0);
    G = arr[0];
    for (int i = 1; i < n; i++)
        G = gcd(G, arr[i]);
    for (int i = 0; i < n; i++)
        cout << arr[i] / G << ' ';
}