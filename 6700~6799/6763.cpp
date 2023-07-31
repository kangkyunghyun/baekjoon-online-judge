// 6763: Speed fines are not fine!
//
// - 문제
// Many communities now have “radar” signs that tell drivers what their speed is, in the hope that they will slow down.
// You will output a message for a “radar” sign. The message will display information to a driver based on his/her speed according to the following table:
// km/h over the limit	Fine
// 1 to 20	100
// 21 to 30	270
// 31 or above	500
//
// - 입력
// The input will be two integers. The first line of input will be speed limit. The second line of input will be the recorded speed of the car.
//
// - 출력
// If the driver is not speeding, the output should be:
// Congratulations, you are within the speed limit!
// If the driver is speeding, the output should be:
// You are speeding and your fine is F.
// where F is the amount of the fine as described in the table above.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int c = b - a;
  if (c > 0)
    cout << "You are speeding and your fine is " << (c > 20 ? (c > 30 ? 500 : 270) : 100) << '.';
  else
    cout << "Congratulations, you are within the speed limit!";
  return 0;
}