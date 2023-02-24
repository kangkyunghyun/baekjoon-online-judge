// 2821: 크게 만들기
//
// - 문제
// N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)
// 둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.
//
// - 출력
// 입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    while (!v.empty() && v.back() < s[i] - '0' && k) {
      v.pop_back();
      k--;
    }
    v.push_back(s[i] - '0');
  }
  while (k--)
    v.pop_back();
  for (int i : v)
    cout << i;
  cout << '\n';
  return 0;
}