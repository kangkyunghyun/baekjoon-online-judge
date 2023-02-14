// 14622: 소수 게임
//
// - 문제
// 인하대학교에 다니는 대웅이는 정수론을 정말 좋아한다. 정수론을 광적으로 좋아하는 대웅이는 어느 순간부터 소수를 외우기 시작했고 어떤 수를 말하면 그 수가 소수인지 아닌지 판별할 수 있는 능력을 가지게 되었다. 인하대학교에 소수의 신이 있다는 소문이 퍼지자 인상대학교의 소수 마스터 규성이는 대웅이에게 도전장을 내밀었다.
// 둘은 누가 더 소수를 사랑하는지 내기를 하기로 하였다.
// 하지만 누가 더 소수를 사랑하는지에 대한 기준이 없으므로 소수 게임을 이용하기로 하였다.
// 소수게임의 규칙은 다음과 같다.
// 1. 두 사람이 번갈아가며 소수를 말한다.
// 2. 소수가 아닌 수를 부르게 될 경우 상대방은 지금까지 상대방이 말한 소수중에서 3번째로 큰 수만큼 점수를 얻게 된다.(만약 상대방이 지금까지 말한 소수가 3개 미만이라면 상대방은 1000점을 얻게 된다.)
// 3. 만약 지금까지 한번이라도 등장한 소수를 말할 경우 해당 소수를 말한 팀이 -1000을 얻게 되며 해당 소수는 그 사람이 말한 소수로 기록되지 않는다.
// 4. 규성이는 도전자이므로 게임은 항상 대웅이부터 시작한다.
// 5. 두 사람이 말할 수 있는 소수는 항상 5000000 미만이다.
// 다음과 같은 규칙으로 소수 게임을 진행할 때 승자를 출력하시오.
//
// - 입력
// 입력의 첫째 줄에 두 사람이 대결을 하는 라운드 수 N이 주어진다. (5≤N≤100,000)
// 이 후 N개의 줄에 대웅이와 규성이가 말하는 정수가 공백으로 구분되어 주어진다. 두 사람이 말하는 정수는 5,000,000보다 작은 자연수 또는 0이다.
//
// - 출력
// 대웅이가 이길 경우 “소수의 신 갓대웅” 규성이가 이길 경우 “소수 마스터 갓규성”을 출력한다. 만약 비길 경우 “우열을 가릴 수 없음” 을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> sieve(5000001, 1);
  for (int i = 2; i <= 5000000; i++)
    if (sieve[i])
      for (int j = i * 2; j <= 5000000; j += i)
        sieve[j] = 0;
  sieve[0] = 0, sieve[1] = 0;
  int n;
  long long a_sum = 0, b_sum = 0;
  cin >> n;
  vector<int> visited(5000001, 0);
  priority_queue<int, vector<int>, greater<int>> a, b;
  while (n--) {
    int num;
    cin >> num;
    if (sieve[num]) {
      if (visited[num] == 0) {
        visited[num] = 1;
        a.push(num);
        if (a.size() > 3)
          a.pop();
      } else {
        a_sum -= 1000;
      }
    } else {
      if (b.size() < 3)
        b_sum += 1000;
      else
        b_sum += b.top();
    }
    cin >> num;
    if (sieve[num]) {
      if (visited[num] == 0) {
        visited[num] = 1;
        b.push(num);
        if (b.size() > 3)
          b.pop();
      } else {
        b_sum -= 1000;
      }
    } else {
      if (a.size() < 3)
        a_sum += 1000;
      else
        a_sum += a.top();
    }
  }
  if (a_sum > b_sum)
    cout << "소수의 신 갓대웅\n";
  else if (a_sum < b_sum)
    cout << "소수 마스터 갓규성\n";
  else
    cout << "우열을 가릴 수 없음\n";
  return 0;
}