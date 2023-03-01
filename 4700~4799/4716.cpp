// 4716: 풍선
//
// - 문제
// 전대프연 대회에서 문제를 푼 팀은 풍선을 받게 된다. 풍선은 사람이 직접 달아주기 때문에 자원 봉사자가 필요하다.
// 풍선은 방 A와 방 B에 보관되어 있다. 대회에 참가한 팀의 수는 총 N개이고, 앉아있는 자리는 서로 다르다. 어떤 팀은 방 A에 가깝고, 어떤 팀은 B에 더 가깝다.
// 각 팀에게 달아줘야 하는 풍선의 수와 방 A와 B로부터의 거리가 주어진다. 이때, 모든 풍선을 달아주는데 필요한 이동 거리의 최솟값을 출력한다. 대회에서 풍선을 달아주는 사람은 매우 많고, 풍선은 한 가지 색상을 여러 개 달아준다고 가정한다. 풍선을 달기 위해 이동해야하는 거리는 팀이 A와 B로부터 떨어진 거리와 같다. 풍선을 달아주는 사람은 한 번에 풍선 하나만 들고 이동할 수 있다.
//
// - 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 팀의 수 N(1 ≤ N ≤ 1,000)과 방 A와 B에 보관되어있는 풍선의 수 A, B가 주어진다. (0 ≤ A, B ≤ 10,000)
// 다음 N개 줄에는 팀에게 달아줘야하는 풍선의 수 K와 방 A로부터 떨어진 거리 DA, B로부터 떨어진 거리 DB (0 ≤ DA, DB ≤ 1,000)가 주어진다. 풍선이 부족한 경우는 없다. 즉, Σi Ki ≤ A+B.
// 입력의 마지막 줄에는 0이 세 개 주어진다.
//
// - 출력
// 각 테스트 케이스에 대해서, 모든 팀에게 풍선을 달아주기 위해 필요한 이동 거리의 최솟값을 한 줄에 하나씩 출력한다. 이때, 풍선을 달아주고 방 A나 B로 돌아오는 거리는 포함하지 않는다. 즉, 방 A와 B에서 팀으로 이동하는 거리만 포함한다.

#include <bits/stdc++.h>
using namespace std;

struct team {
  int K, a, b;
};

bool cmp(team a, team b) {
  return abs(a.a - a.b) > abs(b.a - b.b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int N, A, B;
    long long ans = 0;
    cin >> N >> A >> B;
    if (!N && !A && !B)
      break;
    vector<team> v(N);
    for (int i = 0; i < N; i++)
      cin >> v[i].K >> v[i].a >> v[i].b;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) {
      int K = v[i].K, a = v[i].a, b = v[i].b;
      int m = a > b ? 0 : 1;
      if (m) {
        if (A >= K) {
          ans += K * a;
          A -= K;
        } else {
          ans += A * a;
          K -= A;
          A = 0;
          ans += K * b;
          B -= K;
        }
      } else {
        if (B >= K) {
          ans += K * b;
          B -= K;
        } else {
          ans += B * b;
          K -= B;
          B = 0;
          ans += K * a;
          A -= K;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}