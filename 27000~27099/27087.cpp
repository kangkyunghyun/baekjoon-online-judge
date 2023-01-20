// 27087: 직육면체
//
// - 문제
//  A × B × C 모양의 직육면체를 1 × p × p 모양의 직육면체로 채울 수 있는지 판별하시오. 단, p는 소수이다.
// 직육면체의 방향은 중요하지 않다. 즉, 직육면체를 돌려서 p × 1 × p, p × p × 1로 채우는 것도 가능하다.
//
// - 입력
// 첫 줄에 테스트 케이스의 수 T가 주어진다.
// 이후 한 줄에 하나씩 테스트 케이스에 대한 정보가 주어진다. 각 테스트 케이스는 A, B, C, p가 띄어쓰기를 사이에 두고 주어진다.
//
// - 출력
// 각각의 테스트 케이스에 대해 직육면체를 채울 수 있으면 1, 없으면 0을 출력한다. 한 줄에 하나씩 출력한다.
//
// - 제한
//  1 ≤ T ≤ 1000
//  1 ≤ A ≤ 100 
//  1 ≤ B ≤ 100 
//  1 ≤ C ≤ 100 
//  2 ≤ p ≤ 97 
//  p는 소수

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int p, cnt = 0;
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2] >> p;
    for (int i : v)
      if (!(i % p))
        cnt++;
    if (cnt >= 2)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}