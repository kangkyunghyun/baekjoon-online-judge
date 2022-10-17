// 1755: 숫자놀이
//
// - 문제
// 79를 영어로 읽되 숫자 단위로 하나씩 읽는다면 "seven nine"이 된다. 80은 마찬가지로 "eight zero"라고 읽는다.
// 79는 80보다 작지만, 영어로 숫자 하나씩 읽는다면 "eight zero"가 "seven nine"보다 사전순으로 먼저 온다.
// 문제는 정수 M, N(1 ≤ M ≤ N ≤ 99)이 주어지면 M 이상 N 이하의 정수를 숫자 하나씩 읽었을 때를 기준으로 사전순으로 정렬하여 출력하는 것이다.
//
// - 입력
// 첫째 줄에 M과 N이 주어진다.
//
// - 출력
// M 이상 N 이하의 정수를 문제 조건에 맞게 정렬하여 한 줄에 10개씩 출력한다.

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  cin >> m >> n;
  map<char, string> dict{{'0', "zero"}, {'1', "one"}, {'2', "two"}, {'3', "three"}, {'4', "four"}, {'5', "five"}, {'6', "six"}, {'7', "seven"}, {'8', "eight"}, {'9', "nine"}};
  vector<pair<int, string>> v;
  for (int i = m; i <= n; i++) {
    string num = to_string(i);
    string item = "";
    for (char c : num)
      item += dict[c] + ' ';
    v.push_back(make_pair(i, item));
  }
  sort(v.begin(), v.end(), compare);
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first;
    cnt++;
    if (cnt % 10 == 0)
      cout << '\n';
    else
      cout << ' ';
  }
  return 0;
}