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