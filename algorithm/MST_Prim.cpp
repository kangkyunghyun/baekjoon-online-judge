#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int V, E;
vector<pii> graph[10001];

int prim() {
    priority_queue<pii> pq;
    vector<int> visited(V + 1, 0);
    visited[1] = 1;
    for (pii edge : graph[1])
        pq.push(edge);
    int cost = 0, cnt = 1;
    while (cnt < V) {
        auto [weight, node] = pq.top();
        pq.pop();
        if (!visited[node]) {
            visited[node] = 1;
            cost -= weight;
            cnt++;
            for (pii next : graph[node])
                if (!visited[next.second])
                    pq.push(next);
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({-c, b});
        graph[b].push_back({-c, a});
    }
    cout << prim();
    return 0;
}
// O(ElogV)