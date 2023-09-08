// 6778: Which Alien?
//
// - 문제
// Canada Cosmos Control has received a report of another incident. They believe that an alien has illegally entered our space. A person who witnessed the appearance of the alien has come forward to describe the alien’s appearance. It is your role within the CCC to determine which alien has arrived. There are only 3 alien species that we are aware of, described below:
// TroyMartian, who has at least 3 antenna and at most 4 eyes;
// VladSaturnian, who has at most 6 antenna and at least 2 eyes;
// GraemeMercurian, who has at most 2 antenna and at most 3 eyes.
//
// - 입력
// The first line contain the number of antenna that the witness claimed to have seen on the alien. The second line contain the number of eyes seen on the alien.
//
// - 출력
// The output will be the list of aliens who match the possible description given by the witness. If no aliens match the description, there is no output.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a >= 3 && b <= 4)
    cout << "TroyMartian\n";
  if (a <= 6 && b >= 2)
    cout << "VladSaturnian\n";
  if (a <= 2 && b <= 3)
    cout << "GraemeMercurian\n";
  return 0;
}