// 5021: 왕위 계승
//
// - 문제
// 유토피아의 왕이 사망했다. 왕은 자손을 남기지 않고 사망했기 때문에, 왕위를 계승할 사람을 지목하지 않았다. 왕실 귀족은 왕위를 주장하기 시작했다. 유토피아의 법에는 왕의 계승자가 없는 경우에, 나라를 세운 사람과 혈통이 가까운 사람이 유토피아를 통치한다는 조항이 있다.
// 나라를 세운 사람과 혈통이 가장 가까운 사람은 그의 자손이 아닌 사람과 피가 덜 섞인 사람이다. 모든 사람은 아버지의 혈통과 어머니의 혈통을 반 씩 받게 된다. 나라를 세운 사람의 자식은 1/2 왕족이며, 그 아들이 왕족이 아닌 사람과 결혼한 경우에는 아들의 자식은 1/4 왕족이 된다.
// 가장 나라를 세운 사람과 혈통이 가까운 사람을 찾는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N과 M이 주어진다. (2 ≤ N, M ≤ 50)
// 둘째 줄에 유토피아를 세운 사람의 이름이 주어진다.
// 다음 N개 줄에는 가족 정보가 주어진다. 정보는 이름 세 개로 이루어져 있고, 공백으로 구분되어져 있다. 첫 번째 이름은 자식의 이름이고, 뒤의 두 이름은 부모의 이름이다.
// 다음 M개 줄에는 왕위를 계승받기를 주장하는 사람의 이름이 한 줄에 하나씩 주어진다.
// 모든 이름은 1~10글자이며, 알파벳 소문자로만 이루어져 있다. 나라를 세운 사람이 왕위를 계승하는 경우나, 누군가의 자식인 경우는 없다.
//
// - 출력
// 첫째 줄에 유토피아를 세운 사람과 가장 혈통이 가까운 사람의 이름을 출력한다. 항상 답이 유일한 경우만 입력으로 주어진다.
// 문제에 주어지는 가족 관계는 성별, 나이를 고려하지 않고 만들었기 때문에, 실제로는 말이 안되는 경우가 나올 수도 있다. 하지만, 모든 자식의 부모는 유일하며, 다시 자식이 부모의 부모가 되는 경우도 없다. 또, 한 사람이 여러 명의 자식이 될 수 도 없다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, cnt = 0;
  string king;
  cin >> n >> m >> king;
  map<string, int> M;
  vector<int> edges[151], inDegree(151, 0);
  vector<double> blood(151, 0);
  M[king] = cnt++;
  blood[M[king]] = 1;
  while (n--) {
    string name[3];
    for (int i = 0; i < 3; i++)
      cin >> name[i];
    for (int i = 0; i < 3; i++)
      if (M.find(name[i]) == M.end())
        M[name[i]] = cnt++;
    inDegree[M[name[0]]] += 2;
    edges[M[name[1]]].push_back(M[name[0]]);
    edges[M[name[2]]].push_back(M[name[0]]);
  }
  queue<int> q;
  for (int i = 0; i < cnt; i++)
    if (inDegree[i] == 0)
      q.push(i);
  for (int i = 0; i < cnt; i++) {
    int node = q.front();
    q.pop();
    for (int next : edges[node]) {
      blood[next] += blood[node] / 2;
      if (--inDegree[next] == 0)
        q.push(next);
    }
  }
  string s, ans;
  double tmp = 0;
  while (m--) {
    cin >> s;
    if (M.find(s) != M.end() && tmp < blood[M[s]]) {
      tmp = blood[M[s]];
      ans = s;
    }
  }
  cout << ans;
  return 0;
}