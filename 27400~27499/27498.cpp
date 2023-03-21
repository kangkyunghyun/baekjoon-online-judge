// 27498: 연애 혁명
//
// - 문제
// 신촌고등학교 학생회장 기령이는 최근 학생들의 복잡한 사랑관계로 인해 고민이
// 많다. 학생들이 공부에 집중하지 못해 전반적인 성적이 하락하고 있는 것이다.
// 이에 기령이는 학생들의 복잡한 마음을 덜어주기 위해 일부의 사랑 관계를 강제로
// 포기하게 만드는 특단의 조치를 취하기로 했다. 단, 파장을 최소화 하기 위해
// 다음의 조건을 만족하도록 조치할 것이다. 사랑 관계 중, 이미 성사된 사랑 관계는
// 포기하도록 하지 않는다.사랑 관계가 K각 관계를 이루지 않도록 한다. K(K
// \geq 3)각 관계라는 것은 임의의 서로 다른 K명의 학생 A_1, A_2, \cdots, A_i,
// \cdots, A_K에 대하여, i \neq 1인 모든 i에 대해서 A_{i-1}과
// A_{i}사이에 사랑 관계가 존재하며, A_K와 A_1사이에 사랑 관계가 존재하는
// 것을 의미한다. 포기하도록 만들 수 있는 경우가 여러가지일 경우 포기하도록 만든
// 애정도의 합을 최소화한다. 다만 학생의 수가 매우 많아 이러한 조건을 만족하는
// 경우를 찾기는 어렵다. 조건을 만족하도록 사랑관계를 포기하게 했을 때,
// 포기하도록 만든 애정도의 합의 최솟값을 구해보자.
//
// - 입력
// 첫째 줄에 학생의 수 N(3 ≤ N ≤ 10\ 000), 사랑 관계의 수 M(N ≤ M
// ≤ 100\ 000)가 주어진다. 이후 M개의 줄에 걸쳐 사랑관계를 표현하는 세
// 개의 정수 a_i, b_i, c_i와 성사 여부 d_i가 공백으로 구분되어 주어진다.
// (1 ≤ a_i < b_i ≤ N; 1 ≤ c_i ≤ 10\ 000)  이는 학생 a_i와
// b_i가 애정도가 c_i인 사랑관계에 있으며 d_i가 1일 경우 이미 성사된
// 사랑 관계임을, 0일 경우 그렇지 않음을 의미한다. 주어지는 데이터는 임의의 두
// 학생이 한 개 이상의 사랑 관계에 걸쳐 연결되며, 동일한 두 학생 간의 사랑
// 관계가 여러 번 주어지지 않는다. 또한 성사된 사랑 관계만으로 이루어진 K각
// 관계는 존재하지 않는다.
//
// - 출력
// 포기하도록 만든 애정도의 합의 최솟값을 출력한다.

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