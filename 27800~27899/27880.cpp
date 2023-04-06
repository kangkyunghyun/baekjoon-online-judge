// 27880: Gahui and Soongsil University station
//
// - 문제
// Soongsil University Station is famous as the deepest station on Seoul Subway Line 7. This station is so deep that the platform is on the B6. Gahui was surprised that she did not reach the platform after more than five minutes from the exit. Gahui wants to know how deep Soongsil University station is. Find the depth of the Soongsil University station.
// Depth is the vertical distance from the exit to the platform.
//
// - 입력
//
// line	{floor1}	{floor2}
// 1	F1	B1
// 2	B1	B2
// 3	B2	B5
// 4	B5	B6
// [Table 1] Description of the given input
// For every two adjacent floors ordered by depth, the information is given on a line as follows:
// Stair x
// If you go down x stairs from the {floor1} floor, you will reach the {floor2} floor.
// Es x
// If you go down the escalator with x steps from the {floor1} floor, you will reach the {floor2} floor.
//
// - 출력
// Print the answer in cm. If the answer is 5096cm, print 5096.
//
// - 제한
// The height of 1 escalator step is 21cm, and the height of 1 stair is 17cm.
// The answer ≤ 6425
// All exits are at the same elevation.
// All platforms are at the same elevation.
// There is no change in elevation at the same platform.
// x is integer.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int x, ans = 0;
  while (cin >> s >> x)
    if (s == "Es")
      ans += 21 * x;
    else
      ans += 17 * x;
  cout << ans;
  return 0;
}