// 27389: Metronome
//
// - 문제
// A Metronome is a mechanical device used by musicians for keeping time. It is a very clever device, based on a spring, an inverted pendulum, and an escapement gear. Milo is learning to play the glockenspiel, and has purchased a metronome to help him keep time. Milo has noticed that for every complete turn (one revolution) of the key, the metronome will give four ticks. Milo wants the metronome to stop at the end of each song that he tries to play.
// For a given song, how many revolutions must he wind the key?
//
// - 입력
// The single line of input contains a single integer n (1 ≤ n ≤ 10^5), which is the length of the song in ticks.
//
// - 출력
// Output a single real number, which is the number of revolutions Milo must turn the metronome's key so that it stops precisely at the end of the song. This number must be accurate to two decimal places.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double n;
  cin >> n;
  cout.precision(2);
  cout << fixed << n / 4;
  return 0;
}