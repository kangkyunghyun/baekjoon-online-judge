// 16563: 어려운 소인수분해
//
// - 문제
// 지원이는 대회에 출제할 문제에 대해서 고민하다가 소인수분해 문제를 출제해야겠다고 마음을 먹었다. 그러나 그 이야기를 들은 동생의 반응은 지원이의 기분을 상하게 했다.
// "소인수분해? 그거 너무 쉬운 거 아니야?"
// 지원이는 소인수분해의 어려움을 알려주고자 엄청난 자신감을 가진 동생에게 2와 500만 사이의 자연수 N개를 주고 소인수분해를 시켰다. 그러자 지원이의 동생은 기겁하며 쓰러졌다. 힘들어하는 지원이의 동생을 대신해서 여러분이 이것도 쉽다는 것을 보여주자!
//
// - 입력
// 첫째 줄에는 자연수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다.
// 둘째 줄에는 자연수 ki (2 ≤ ki ≤ 5,000,000, 1 ≤ i ≤ N)가 N개 주어진다.
//
// - 출력
// N줄에 걸쳐서 자연수 ki의 소인수들을 오름차순으로 출력하라.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> isPrime(5000001, 1), prime;
  for (int i = 2; i * i <= 5000000; i++)
    if (isPrime[i]) {
      prime.push_back(i);
      for (int j = i * i; j <= 5000000; j += i)
        isPrime[j] = 0;
    }
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    while (x > 1)
      if (isPrime[x]) {
        cout << x;
        x = 1;
      } else {
        for (int i : prime)
          if (x % i == 0) {
            cout << i << ' ';
            x /= i;
            break;
          }
      }
    cout << '\n';
  }
  return 0;
}