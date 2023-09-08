// 15702: 중간고사 채점
//
// - 문제
// 이번 중간고사에는 총 N문제가 나왔고, 응시한 사람의 수는 M명이다. 각 문제의 배점과 각 사람의 결과가 주어졌을 때, 가장 높은 점수를 획득한 사람을 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 문제의 개수 N과 응시자의 수 M이 주어진다. (1 ≤ N ≤ 100, 1 ≤ M ≤ 100)
// 둘째 줄에는 문제의 배점이 1번 문제부터 N번 문제까지 순서대로 주어진다. 각 문제의 배점은 100보다 작거나 같은 자연수이며, 공백으로 구분되어져 있다.
// 셋째 줄부터 M개의 줄에는 응시자의 정보가 한 줄에 하나씩 주어진다. 응시자의 정보는 총 N+1개의 문자열로 이루어져 있다. 첫 번째 문자열은 응시자의 수험 번호이다.
// 수험 번호는 100,000보다 작거나 같은 자연수이다. 두 번째 부터 N+1번째 문자열은 각 시험 문제의 채점 결과이다.
// 채점 결과는 1번 문제부터 N번 문제까지 순서대로 주어지며, 'O' 또는 'X'이다. 'O'가 주어진 경우에는 해당 문제를 맞춘 것이고, 'X'가 주어진 경우에는 해당 문제를 틀린 것이다.
// 문제를 맞춘 경우에는 그 문제의 배점이 점수에 더해지게 되며, 틀린 경우에는 더해지지 않는다. 수험 번호가 중복되는 경우는 없다.
//
// - 출력
// 첫째 줄에 가장 높은 점수를 얻은 학생의 번호와 점수를 공백으로 구분해 출력한다. 만약, 가장 높은 점수를 얻은 학생이 여러 명이라면, 수험 번호가 가장 작은 것을 출력한다.

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> score(n);
  vector<pair<int, int>> scoreList, ans;
  for (int i = 0; i < n; i++)
    cin >> score[i];
  for (int i = 0; i < m; i++) {
    int student, cnt = 0;
    cin >> student;
    for (int j = 0; j < n; j++) {
      char s;
      cin >> s;
      if (s == 'O')
        cnt += score[j];
    }
    scoreList.push_back(make_pair(student, cnt));
  }
  sort(scoreList.begin(), scoreList.end(), compare);
  int maxScore = scoreList.front().second;
  for (auto i : scoreList)
    if (i.second == maxScore)
      ans.push_back(i);
  sort(ans.begin(), ans.end());
  cout << ans.front().first << ' ' << ans.front().second;
  return 0;
}