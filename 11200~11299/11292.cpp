// 11292: 키 큰 사람
//
// - 문제
// 민우는 학창시절 승부욕이 강해서 달리기를 할 때에도 누가 가장 빠른지를 중요하게 생각하고, 시험을 볼 때에도 누가 가장 성적이 높은지를 중요하게 생각한다.
// 이번에 반에서 키를 측정하였는데, 민우는 마찬가지로 누구의 키가 가장 큰지 궁금해한다. 민우를 도와 가장 키가 큰 사람을 찾아보자.
//
// - 입력
// 입력은 여러개의 테스트케이스로 구성되어있다. 각 테스트케이스는 첫 번째 줄에 학생의 수 N (0 < N ≤ 50)이 주어지고, 이어서 N개의 줄에 각 학생의 이름과 키가 공백으로 구별되어 주어진다.
// 학생의 이름은 알파벳 대/소문자로만 이루어져 있고, 길이는 10을 넘지 않는다. 학생의 키는 소숫점 이하 2자리까지 주어진다. N이 0으로 주어지는 경우 프로그램을 종료한다.
//
// - 출력
// 각 테스트케이스에 대해, 가장 키가 큰 학생의 이름을 한 줄에 출력한다. 같은 키의 사람이 여러명 일 경우 모두 출력해야 하며, 순서는 입력으로 들어온 순서를 유지해야 한다.

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, float> a, pair<string, float> b) {
  return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (1) {
    cin >> n;
    if (n == 0)
      break;
    vector<pair<string, float>> v;
    string name;
    float height;
    for (int i = 0; i < n; i++) {
      cin >> name >> height;
      v.push_back(make_pair(name, height));
    }
    stable_sort(v.begin(), v.end(), compare);
    float max = v[0].second;
    for (auto i : v)
      if (i.second == max)
        cout << i.first << ' ';
    cout << '\n';
  }
  return 0;
}