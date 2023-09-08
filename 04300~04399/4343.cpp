// 4343: Arctic Network
//
// - 문제
// The Department of National Defence (DND) wishes to connect several northern outposts by a wireless network. Two different communication technologies are to be used in establishing the network: every outpost will have a radio transceiver and some outposts will in addition have a satellite channel.
// Any two outposts with a satellite channel can communicate via the satellite, regardless of their location. Otherwise, two outposts can communicate by radio only if the distance between them does not exceed D, which depends of the power of the transceivers. Higher power yields higher D but costs more. Due to purchasing and maintenance considerations, the transceivers at the outposts must be identical; that is, the value of D is the same for every pair of outposts.
// Your job is to determine the minimum D required for the transceivers. There must be at least one communication path (direct or indirect) between every pair of outposts.
//
// - 입력
// The first line of input contains N, the number of test cases. The first line of each test case contains 1 <= S <= 100, the number of satellite channels, and S < P <= 500, the number of outposts. P lines follow, giving the (x,y) coordinates of each outpost in km (coordinates are integers between 0 and 10,000).
//
// - 출력
// For each case, output should consist of a single line giving the minimum D required to connect the network. Output should be specified to 2 decimal points.

#include <bits/stdc++.h>
using namespace std;

vector<int> p;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int S, P, cnt = 0;
    double ans = 0;
    cin >> S >> P;
    p.resize(P + 1);
    iota(p.begin(), p.end(), 0);
    vector<pair<double, pair<int, int>>> edge;
    vector<pair<int, int>> xy(P + 1);
    for (int i = 1; i <= P; i++)
      cin >> xy[i].first >> xy[i].second;
    for (int i = 1; i < P; i++)
      for (int j = i + 1; j <= P; j++) {
        auto [x1, y1] = xy[i];
        auto [x2, y2] = xy[j];
        double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        edge.push_back({d, {i, j}});
      }
    sort(edge.begin(), edge.end());
    for (auto [weight, path] : edge)
      if (find(path.first) != find(path.second)) {
        ans = weight;
        merge(path.first, path.second);
        if (++cnt == P - S)
          break;
      }
    cout.precision(2);
    cout << fixed << ans << '\n';
  }
  return 0;
}