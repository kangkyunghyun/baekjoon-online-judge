// 27907: The primes contain arbitrarily long arithmetic progressions
//
// - 문제
// 그린-타오 정리(Green–Tao theorem)[1]는 소수 집합이 임의 길이의 등차수열을 포함한다는 정리로, 2004년에 Ben Green과 Terence Tao가 증명했다. 실제로는 이보다 조금 더 강력한 다음 명제를 증명한다:
// 소수 집합의 부분집합인 A가limsuplimits_{Nrightarrowinfty} frac{≤ft| A cap [1, N] right|}{pi(N)} > 0을 만족한다면, 모든 양의 정수 k에 대해 A가 길이 k인 등차수열을 무한히 많이 포함한다. 특히 A를 소수 집합 전체로 놓으면 소수 집합이 임의 길이의 등차수열을 포함한다.
// 그린-타오 정리는 세메레디의 정리(Szemerédi's theorem)[2]의 확장이라고 할 수 있다. 세메레디의 정리는 다음과 같다:
// 자연수 집합의 부분집합인 A가limsuplimits_{Nrightarrowinfty} frac{≤ft| A cap [1, N] right|}{N} > 0을 만족한다면, 모든 양의 정수 k에 대해 A가 길이 k인 등차수열을 무한히 많이 포함한다.
// 그린-타오 정리를 세메레디의 정리로부터 바로 유도할 수는 없다. 소수의 집합은 자연수에 대해 밀도가 0이기 때문이다. 하지만 세메레디의 정리를 확장하여 자연수 집합을 유사 난수와 관련된 특정 조건을 만족하는 집합으로 확장할 수 있고, 이 조건을 만족하면서 소수 집합을 조밀 집합(dense subset)으로 갖는 집합을 구성하여 그린-타오 정리를 증명하게 된다.
// 하지만 그린-타오 정리는 실제로 임의 길이의 소수 등차수열을 어떻게 구성하는지는 알려주지 않는다. 이 문제에서는 임의 길이의 소수 등차수열을 직접 구성해야 한다.
// [1] Green, Ben, and Terence Tao. "The primes contain arbitrarily long arithmetic progressions." Annals of mathematics (2008): 481-547.
// [2] Szemerédi, Endre. "On sets of integers containing no k elements in arithmetic progression." Acta Arith 27.299-345 (1975): 21.
//
// - 입력
// 첫째 줄에 자연수 n이 주어진다.
//
// - 출력
// 첫째 줄에 길이가 n이고 3,825,123,056,546,413,051 이하의 소수로만 이루어진 등차수열을 출력한다.
// 만약 그러한 등차수열이 없으면 대신 -1을 출력한다.
//
// - 제한
// 2 ≤ n ≤ 30 
//
// - 서브태스크
// 번호	배점	제한
// 1	7	n ≤ 3
// 2	900	n ≤ 10
// 3	27000	추가 제약 조건 없음

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cout << 2 << ' ';
  return 0;
}