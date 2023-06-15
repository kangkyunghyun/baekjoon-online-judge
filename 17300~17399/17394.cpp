// 17394: 핑거 스냅
//
// - 문제
// [어벤져스] 시리즈를 보지 않은 사람이라도 ‘인피니티 건틀렛’이 무엇인지는 다들 알 것이다. 그래도 모르는 사람들을 위해 설명을 하자면, 인피니티 스톤이 모두 모인 인피니티 건틀렛을 끼고 손가락을 튕기면, 사용자가 원하는 것을 할 수 있다. 그러나 반동이 매우 심하기 때문에 그리 많이는 사용할 수 없다.
// 정신 나간 수학자 Sonaht는 우연히 이 인피니티 건틀렛을 손에 넣게 된다. 그러나 이 인피니티 건틀렛에는 약간의 하자가 있어서, 핑거 스냅으로 할 수 있는 일이 몇가지 없다. 다음은, 핑거 스냅으로 할 수 있는 일을 나열한 것이다.
// 전 우주의 생명체 수를 현재의 절반으로 한다.
// 전 우주의 생명체 수를 현재의 1/3로 한다.
// (위의 두 경우에서, 나누어 떨어지지 않으면 몫만 남기고, 나머지는 버린다.)
// 전 우주의 생명체 수를 현재보다 하나 늘린다.
// 전 우주의 생명체 수를 현재보다 하나 줄인다.
// (이미 전 우주의 생명체 수가 0이라면 할 수 없다.)
// Sonaht는 전 우주의 생명체 수를 목표치 A 이상 B 이하로 줄이려 한다. 그러나 역시나 정신 나간 수학자답게, A 이상 B 이하인 수 중 소수로 만들려 한다. (어쩌면 A와 B 사이에 소수가 없을지도 모르지만 말이다.) 소수란, 서로 다른 약수가 1과 자기 자신밖에 없는 수를 의미한다. 그러나 인피니티 건틀렛은 반동이 심하기에, Sonaht는 최대한 적은 수의 핑거 스냅으로 이 목표를 달성하고자 한다. Sonaht가 최소 몇 번의 핑거 스냅을 해야 할지 구해보자.
//
// - 입력
// 첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. (1 ≤ T ≤ 10)
// 두 번째 줄부터 T개의 줄에 걸쳐, 현재 전 우주의 생명체 수인 자연수 N과, Sonaht의 목표 범위인 자연수 A, B가 공백으로 구분되어 주어진다. (2 ≤ N ≤ 1,000,000, 2 ≤ A ≤ B ≤ 100,000)
//
// - 출력
// 매 줄마다, 각 테스트 케이스에서 Sonaht가 전 우주의 생명체 수를 목표범위 내의 소수로 만드는 데 필요한 최소한의 핑거 스냅의 횟수를 출력한다.
// 만약 목표범위 내의 소수로 만들 수 없다면, -1을 출력한다.
// 매 테스트 케이스는 독립적으로 고려되어야 한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> sieve(1000001, 1);
  for (int i = 2; i <= 1000000; i++)
    if (sieve[i])
      for (int j = i * 2; j <= 1000000; j += i)
        sieve[j] = 0;
  int t, n, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    int visited[1000001] = {0}, ans = -1;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      if (curr >= a && curr <= b && sieve[curr]) {
        ans = visited[curr] - 1;
        break;
      }
      if (!visited[curr / 2]) {
        q.push(curr / 2);
        visited[curr / 2] = visited[curr] + 1;
      }
      if (!visited[curr / 3]) {
        q.push(curr / 3);
        visited[curr / 3] = visited[curr] + 1;
      }
      if (!visited[curr + 1]) {
        q.push(curr + 1);
        visited[curr + 1] = visited[curr] + 1;
      }
      if (!visited[curr - 1] && curr - 1 >= 0) {
        q.push(curr - 1);
        visited[curr - 1] = visited[curr] + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}