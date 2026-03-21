#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int V, E, sum = 0, cnt = 0;
vector<pii> graph[10001];

int prim() {
	priority_queue<pii> pq;
	vector<int> visited(V + 1, 0);
	visited[1] = 1;
	for (pii edge : graph[1])
		pq.push(edge);
	int cost = 0;
	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (!visited[node]) {
			visited[node] = 1;
			cost += weight;
			for (pii next : graph[node])
				if (!visited[next.second])
					pq.push(next);
		}
	}
	return cost - cnt * 10000;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	while (E--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		sum += c;
		if (d == 1) {
			c += 10000;
			cnt++;
		}
		graph[a].push_back({c, b});
		graph[b].push_back({c, a});
	}
	cout << sum - prim();
	return 0;
}