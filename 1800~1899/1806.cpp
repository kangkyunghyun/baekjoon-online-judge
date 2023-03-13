// 1806: 부분합
//
// - 문제
// 10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.+1 ~ Ai 중의 최솟값이라고 할 때, D에 저장된 수를 출력하는 프로그램을 작성하시오. 이때, i ≤ 0 인 Ai는 무시하고 D를 구해야 한다.
//
// - 입력
// 첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.
//
// - 출력
// 첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, s;
  cin >> n >> s;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int left = 0, right = 0, sum = v[0], ans = n + 1;
  while (left <= right && right < n)
    if (sum < s) {
      sum += v[++right];
    } else if (sum > s) {
      ans = min(ans, right - left + 1);
      sum -= v[left++];
    } else {
      ans = min(ans, right - left + 1);
      sum += v[++right];
    }
  cout << (ans == n + 1 ? 0 : ans);
  return 0;
}