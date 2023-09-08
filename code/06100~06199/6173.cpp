// 6173: Pearl Pairing
//
// - 문제
// At Bessie's recent birthday party, she received N (2 <= N <= 100,000; N%2 == 0) pearls, each painted one of C different colors (1 <= C <= N).
// Upon observing that the number of pearls N is always even, her creative juices flowed and she decided to pair the pearls so that each pair of pearls has two different colors.
// Knowing that such a set of pairings is always possible for the supplied testcases, help Bessie perform such a pairing. If there are multiple ways of creating a pairing, any solution suffices.
//
// - 입력
// Line 1: Two space-separated integers: N and C
// Lines 2..C + 1: Line i+1 tells the count of pearls with color i: C_i
//
// - 출력
// Lines 1..N/2: Line i contains two integers a_i and b_i indicating that Bessie can pair two pearls with respective colors a_i and b_i.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  priority_queue<pii> pq;
  for (int i = 0; i < c; i++) {
    int x;
    cin >> x;
    pq.push({x, i + 1});
  }
  for (int i = 0; i < n / 2; i++) {
    pii a = pq.top();
    pq.pop();
    pii b = pq.top();
    pq.pop();
    cout << a.second << ' ' << b.second << '\n';
    a.first--;
    b.first--;
    if (a.first)
      pq.push(a);
    if (b.first)
      pq.push(b);
  }
  return 0;
}