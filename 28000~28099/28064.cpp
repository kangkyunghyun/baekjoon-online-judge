// 28064: 이민희진
//
// - 문제
// 이민희와 민희진을 연결하면 이민희진
// 김서인과 서인국을 연결하면 김서인국
// 박건과 건빵을 연결하면 박건빵
// 민희는 한 사람의 이름 뒷부분이 다른 사람의 이름 앞부분과 같을 때, 이 둘을 연결하는 것을 재밌어한다.
// N명의 사람이 주어질 때, 연결할 수 있는 서로 다른 사람 쌍의 개수를 구해보자.
// 각각 S, T라는 이름을 가진 두 사람을 연결할 수 있으려면 다음과 같은 조건을 충족해야 한다.
// S, T의 길이보다 작거나 같은 양의 정수 k가 존재하여, S의 앞 k글자와 T의 뒤 k글자가 일치하거나, S의 뒤 k글자와 T의 앞 k글자가 일치해야 한다.
//
// - 입력
// 첫 줄에는 사람 수 N이 주어진다. (1 ≤ N ≤ 100)
// 두 번째 줄부터 N개 줄에 걸쳐 각 사람의 이름이 주어진다.
// 이름은 영어 소문자로만 구성되어 있으며, 길이는 최소 1자, 최대 20자이다.
// 단, 동명이인이 있을 수 있다.
//
// - 출력
// 첫 줄에 연결할 수 있는 서로 다른 사람 쌍의 개수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v(n);
  set<vector<int>> ans;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++) {
    string a = v[i];
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      string b = v[j];
      for (int k = 1; k <= min(a.size(), b.size()); k++)
        if (b.substr(0, k) == a.substr(a.size() - k, k)) {
          vector<int> tmp{i, j};
          sort(tmp.begin(), tmp.end());
          ans.insert(tmp);
          break;
        }
    }
  }
  cout << ans.size();
  return 0;
}