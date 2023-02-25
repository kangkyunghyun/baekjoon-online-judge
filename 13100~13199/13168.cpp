// 13168: 내일로 여행
//
// - 문제
// 친한 친구인 승현이와 지학이는 여름방학 때 여행을 가기로 계획했습니다. 해외여행은 금전적으로 부담이 많기 때문에 둘은 한국의 여러 도시를 여행하기로 했습니다. 한국에는 N개의 도시가 있으며, 승현이는 이 중 여행할 M개의 도시를 결정했습니다. 여행 경로에서 같은 도시를 여러 번 방문할 수 있으며, 여행을 시작하는 도시와 끝내는 도시는 같습니다.
// 한국에는 두 도시 사이를 오갈 수 있는 K개의 교통수단이 있습니다. 교통수단의 종류는 기차, 지하철, 버스, 택시, 비행기 등으로 다양합니다. 특히 기차 코스는 매우 세부적으로 나뉘어 있어서 무궁화호(Mugunghwa), ITX-새마을(ITX-Saemaeul), ITX-청춘(ITX-Cheongchun), KTX, S-Train, V-Train 등이 있습니다. 모든 교통수단은 한 번 이용하는 데 필요한 비용이 정해져 있습니다. 승현이와 지학이는 계획한 M개의 도시를 최소비용으로 차례대로 움직일 것입니다.
// 한편, 코레일에서는 ‘내일로’라는 특별한 기차표를 판매하고 있습니다. 방학 동안, 젊은 청년들은 R원을 주고 내일로 티켓을 살 수 있습니다. 한 번 내일로 티켓을 사면, 며칠 동안 무궁화호, ITX-새마을, ITX-청춘은 무료로 이용할 수 있으며, S-Train과 V-Train은 50% 할인된 가격으로 이용할 수 있습니다. KTX나 지하철, 또는 다른 교통수단에 대해서는 할인이 적용되지 않습니다.
// 지학이는 자신이 아무것도 하지 않는 것에 죄책감을 느끼기 때문에, 자신들의 여행에서 내일로 티켓이 필요한지 생각해보기로 했습니다. 지학이를 도와 내일로 티켓을 사는 것과 사지 않는 것 중 어떤 선택이 더 좋은 지 구하는 프로그램을 작성하세요.
//
// - 입력
// 첫 번째 줄에는 한국에 있는 도시의 수 N(1 ≤ N ≤ 100)과 1인당 내일로 티켓의 가격 R(1 ≤ R ≤ 1,000,000)이 주어집니다. 두 번째 줄에는 N개의 도시의 이름이 주어집니다. 도시의 이름은 알파벳 대소문자로 구성된 길이 20 이하의 문자열입니다. 세 번째 줄에는 승현이와 지학이가 여행할 도시의 수 M(1 ≤ M ≤ 200)이 주어집니다. 네 번째 줄에는 승현이와 지학이가 여행할 M개 도시의 이름이 주어집니다. 이 도시들은 앞서 언급된 N개의 도시 중 하나입니다. 다섯 번째 줄에는 교통수단의 수 K(1 ≤ K ≤ 10,000)가 주어집니다. 마지막 K개의 줄에는 교통수단에 대한 정보가 주어집니다. 줄마다 교통수단의 종류 Typei, 양 끝 도시 Si, Ei, 1인당 비용 Costi (1 ≤ Costi ≤ 100,000)가 주어집니다. Typei는 ‘Subway’, ‘Bus’, ‘Taxi’, ‘Airplane’, ‘KTX’, ‘S-Train’, ‘V-Train’, ‘ITX-Saemaeul’, ‘ITX-Cheongchun’, ‘Mugunghwa’ 중 하나이며, 모든 도시는 주어진 K개의 교통수단을 이용하여 갈 수 있음이 보장되어 있습니다.
// 한국에는 이름이 같은 도시가 있을 수 있다. 따라서, N개의 도시의 이름에는 같은 도시의 이름이 두 번 이상 주어질 수도 있다. 이 경우 이러한 도시를 모두 같은 도시라고 생각해야 한다.
//
// - 출력
// 한줄에 내일로 티켓을 사는 것이 좋으면 ‘Yes’를 출력하고 그렇지 않으면 ‘No’를 출력합니다. 내일로 티켓을 사더라도 비용이 정확히 같다면 ‘No’를 출력합니다.

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, R, M, K;
  double dist1[101][101], dist2[101][101];
  map<string, int> m;
  cin >> N >> R;
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    m[s] = i;
  }
  cin >> M;
  vector<int> v;
  for (int i = 1; i <= M; i++) {
    string s;
    cin >> s;
    v.push_back(m[s]);
  }
  cin >> K;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      dist1[i][j] = i == j ? 0 : INF;
      dist2[i][j] = i == j ? 0 : INF;
    }
  while (K--) {
    string t, s, e;
    double c;
    cin >> t >> s >> e >> c;
    int u = m[s], v = m[e];
    dist1[u][v] = min(dist1[u][v], c);
    dist1[v][u] = min(dist1[v][u], c);
    if (t == "Mugunghwa" || t == "ITX-Saemaeul" || t == "ITX-Cheongchun") {
      dist2[u][v] = 0;
      dist2[v][u] = 0;
    } else if (t == "S-Train" || t == "V-Train") {
      dist2[u][v] = min(dist2[u][v], c / 2);
      dist2[v][u] = min(dist2[v][u], c / 2);
    } else {
      dist2[u][v] = min(dist2[u][v], c);
      dist2[v][u] = min(dist2[v][u], c);
    }
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
        dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
      }
  double sum1 = 0, sum2 = 0;
  for (int i = 0; i < M - 1; i++) {
    int s = v[i], e = v[i + 1];
    sum1 += dist1[s][e];
    sum2 += dist2[s][e];
  }
  cout << (sum1 > sum2 + R ? "Yes\n" : "No\n");
  return 0;
}