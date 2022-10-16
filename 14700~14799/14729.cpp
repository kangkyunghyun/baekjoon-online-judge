// 14729: 칠무해
//
// - 문제
// 조(Joe)는 중앙대학교 교수이고, 논리회로 설계 과목을 담당하고 있다. 그는 수업을 하면서 7명의 학생을 제외한 나머지 학생들에게 좋은 학점을 주겠다고 약속을 하였다.
// Joe 교수님을 돕기 위해서 학생들의 최종 성적이 주어질 때, 그의 연구실인 You See Lab으로 데려갈 성적이 좋지 못한 7명의 학생, 칠무해의 성적을 뽑아보자.
//
// - 입력
// 첫째 줄에 학생의 수 N(8 ≤ N ≤ 10,000,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 학생들의 성적이 무작위로 주어진다. 성적은 최소 0점부터 최대 100점까지 0.001 점 단위로 부여된다.
//
// - 출력
// 하위 7명의 성적을 점수가 낮은 순으로 각 줄마다 출력한다. 하위 7명의 성적의 커트 라인에 동점자가 있을 경우에도 7명만 출력을 하면 된다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<float> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  cout.precision(3);
  cout << fixed;
  for (int i = 0; i < 7; i++)
    cout << v[i] << '\n';
  return 0;
}