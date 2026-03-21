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