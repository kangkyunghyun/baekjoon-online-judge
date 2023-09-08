// 4195: 친구 네트워크
//
// - 문제
// 민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.
// 어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
// 친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.
//
// - 입력
// 첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.
//
// - 출력
// 친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

vector<int> p, s;

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  if (x > y)
    swap(x, y);
  s[x] += s[y];
  p[y] = x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    p.resize(2 * n);
    iota(p.begin(), p.end(), 0);
    s.resize(2 * n);
    fill(s.begin(), s.end(), 1);
    map<string, int> M;
    while (n--) {
      string a, b;
      cin >> a >> b;
      if (M.find(a) == M.end())
        M[a] = M.size();
      if (M.find(b) == M.end())
        M[b] = M.size();
      merge(M[a], M[b]);
      cout << s[find(M[a])] << '\n';
    }
  }
  return 0;
}