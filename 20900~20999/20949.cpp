// 20949: 효정과 새 모니터
//
// - 문제
// 효정은 새해를 맞이하여 새 모니터를 구매하고자 한다. 효정은 돈이 많기 때문에 77인치 모니터를 구매할 것이다. 모니터를 구경하던 효정은 놀라 자빠질 수밖에 없었다. 모니터가 너무 많아 고를 수가 없었기 때문이다. 이왕이면 고해상도가 좋은 법, 효정은 PPI가 가장 높은 모니터를 구매할 것이다. 우선 효정은 PPI가 높은 순으로 모니터들을 정렬하기로 결심하였다.
// PPI는 Pixels Per Inch의 약자로 인치당 몇 개의 픽셀이 존재하는지를 수치로 표현한 것이다. PPI는 다음과 같이 계산할 수 있다.
// 여기서 W는 가로 픽셀 수, H는 세로 픽셀 수, D는 대각선의 길이(인치)이다. 예를 들어, Full HD 해상도는 가로 픽셀 수가 1920, 세로 픽셀 수가 1080이다. 따라서 24인치 Full HD 모니터의 PPI는 다음과 같다.
// N개의 모니터가 주어졌을 때, PPI가 높은 순으로 모니터들을 정렬하는 프로그램을 작성하시오. 모든 모니터의 크기는 77인치로 동일하다.
//
// - 입력
// 첫 번째 줄에 모니터의 개수 N이 주어진다.
// 이후 N개의 줄 중 i(1 ≤ i ≤ N)번째 줄에는 i번 모니터의 가로 픽셀 수 Wi와 세로 픽셀 수 Hi가 주어진다.
// 모든 입력은 정수이며 공백으로 구분되어 주어진다.
//
// - 출력
// N개의 줄에 걸쳐 모니터의 번호를 PPI가 높은 순으로 한 줄에 하나씩 출력한다.
// PPI가 동일한 경우 번호가 더 작은 모니터를 먼저 출력한다.
//
// - 제한
// 1 ≤ N ≤ 1,000
// 1 ≤ Wi, Hi ≤ 30,000

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
  return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, w, h;
  cin >> n;
  vector<pair<int, double>> v;
  for (int i = 0; i < n; i++) {
    cin >> w >> h;
    double ppi = pow(w * w + h * h, 0.5) / 77;
    v.push_back(make_pair(i + 1, ppi));
  }
  stable_sort(v.begin(), v.end(), compare);
  for (auto i : v)
    cout << i.first << '\n';
  return 0;
}