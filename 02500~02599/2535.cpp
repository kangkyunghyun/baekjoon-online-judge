// 2535: 아시아 정보올림피아드
//
// - 문제
// 최근 아시아 지역의 학생들만 참여하는 정보 올림피아드 대회가 만들어졌다. 이 대회는 온라인으로 치러지기 때문에 각 나라에서 이 대회에 참여하는 학생 수의 제한은 없다.
// 참여한 학생들의 성적순서대로 세 명에게만 금, 은, 동메달을 수여한다. 단, 동점자는 없다고 가정한다. 그리고 나라별 메달 수는 최대 두 개다.
// 대회 결과가 입력으로 주어질 때, 메달 수상자를 결정하여 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫 번째 줄에는 대회참가 학생 수를 나타내는 N이 주어진다. 단, 3 ≤ N ≤ 100이다. 두 번째 줄부터 N개의 줄에는 각 줄마다 한 학생의 소속 국가 번호, 학생 번호, 그리고 성적이 하나의 빈칸을 사이에 두고 주어진다.
// 단, 국가 번호는 1부터 순서대로 하나의 정수로 주어지며, 각 학생번호는 각 나라별로 1부터 순서대로 하나의 정수로 주어진다,점수는 0 이상 1000 이하의 정수이고, 동점자는 없다고 가정한다. 입력으로 제공되는 국가는 적어도 두 나라 이상이다.
//
// - 출력
// 메달을 받는 학생들을 금, 은, 동메달 순서대로 한 줄에 한 명씩 출력한다. 즉, 첫 번째 줄에는 금메달 수상자를, 두 번째 줄에는 은메달 수상자를, 세 번째 줄에는 동메달 수상자를 출력한다.
// 하나의 줄에는 소속국가 번호와 학생 번호를 하나의 빈칸을 사이에 두고 출력한다.

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> v;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(make_pair(make_pair(a, b), c));
    m.insert(make_pair(a, 0));
  }
  sort(v.begin(), v.end(), compare);
  vector<pair<int, int>> ans;
  for (int i = 0; ans.size() < 3; i++)
    if (m[v[i].first.first] < 2) {
      ans.push_back(v[i].first);
      m[v[i].first.first]++;
    }
  for (auto i : ans)
    cout << i.first << ' ' << i.second << '\n';
  return 0;
}