// 24805: Climbing Worm
//
// - 문제
// A worm is at the bottom of a pole. It wants to reach the top, but it is too lazy to climb to the top without stopping. It can crawl up the pole a certain number of inches at a time, falling down a lesser number of inches right after while it rests. How many times does the worm need to crawl up in order to reach the top of the pole?
//
// - 입력
// The input consists of a single line that contains three integers a, b (0 ≤ b < a ≤ 100), and h, (0 < h ≤ 100,000) indicating the amount a of inches the worm can climb at a time, the amount b of inches the worm falls during its resting period, and the height h of the pole, respectively.  Note: For the purposes of this problem, the worm is modeled as a point and thus has no length.
//
// - 출력
// Output the number of times the worm must crawl up in order to reach the top of the pole.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int a, b, h, sum = 0, ans = 0;
  cin >> a >> b >> h;
  while (1) {
    sum += a;
    ans++;
    if (sum >= h)
      break;
    sum -= b;
  }
  cout << ans;
  return 0;
}