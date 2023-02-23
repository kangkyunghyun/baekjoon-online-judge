// 11054: 가장 긴 바이토닉 부분 수열
//
// - 문제
// 수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
// 예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.
// 수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)
//
// - 출력
// 첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m = 0, ans;
  cin >> n;
  vector<int> v(n), asc(n, 1), dsc(n, 1);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++)
      if (v[i] > v[j])
        asc[i] = max(asc[i], asc[j] + 1);
    if (asc[i] > m) {
      m = asc[i];
      for (int a = i; a < n; a++)
        for (int b = i; b < a; b++)
          if (v[a] < v[b])
            dsc[a] = max(dsc[a], dsc[b] + 1);
      ans = max(ans, m + *max_element(dsc.begin(), dsc.end()) - 1);
    }
    fill(dsc.begin(), dsc.end(), 1);
  }
  cout << ans << '\n';
  return 0;
}