// 3803: Networking
//
// - 문제
// You are assigned to design network connections between certain points in a
// wide area. You are given a set of points in the area, and a set of possible
// routes for the cables that may connect pairs of points. For each possible
// route between two points, you are given the length of the cable that is
// needed to connect the points over that route. Note that there may exist many
// possible routes between two given points. It is assumed that the given
// possible routes connect (directly or indirectly) each two points in the area.
// Your task is to design the network for the area, so that there is a
// connection (direct or indirect) between every two points (i.e., all the
// points are interconnected, but not necessarily by a direct cable), and that
// the total length of the used cable is minimal.
//
// - 입력
// The input file consists of a number of data sets. Each data set defines one
// required network. The first line of the set contains two integers: the first
// defines the number P of the given points, and the second the number R of
// given routes between the points. The following R lines define the given
// routes between the points, each giving three integer numbers: the first two
// numbers identify the points, and the third gives the length of the route. The
// numbers are separated with white spaces. A data set giving only one number
// P=0 denotes the end of the input. The data sets are separated with an empty
// line. The maximal number of points is 50. The maximal length of a given route
// is 100. The number of possible routes is unlimited. The nodes are identified
// with integers between 1 and P (inclusive). The routes between two points i
// and j may be given as i j or as j i.
//
// - 출력
// For each data set, print one number on a separate line that gives the total
// length of the cable used for the entire designed network.

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
  int cost = 0;
  while (!pq.empty()) {
    int weight = -pq.top().first;
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
  return cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    cin >> V;
    if (V == 0)
      break;
    cin >> E;
    for (int i = 1; i <= V; i++)
      graph[i].clear();
    while (E--) {
      int a, b, c;
      cin >> a >> b >> c;
      graph[a].push_back({-c, b});
      graph[b].push_back({-c, a});
    }
    cout << prim() << '\n';
  }
  return 0;
}