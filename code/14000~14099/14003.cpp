// 14003: 가장 긴 증가하는 부분 수열 5
//
// - 문제
// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
// 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
//
// - 입력
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)
//
// - 출력
// 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
// 둘째 줄에는 정답이 될 수 있는 가장 긴 증가하는 부분 수열을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n >> x;
  vector<int> v{x}, LIS{x}, idx{1};
  for (int i = 1; i < n; i++) {
    cin >> x;
    v.push_back(x);
    if (LIS.back() < x) {
      LIS.push_back(x);
      idx.push_back(LIS.size());
    } else {
      auto it = lower_bound(LIS.begin(), LIS.end(), x);
      *it = x;
      idx.push_back(it - LIS.begin() + 1);
    }
  }
  int size = LIS.size();
  cout << size << '\n';
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--)
    if (idx[i] == size) {
      ans.push_back(v[i]);
      size--;
    }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}