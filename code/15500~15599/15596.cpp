// 15596: 정수 N개의 합
//
// - 문제
// 정수 n개가 주어졌을 때, n개의 합을 구하는 함수를 작성하시오.
// 작성해야 하는 함수는 다음과 같다.
// long long sum(std::vector<int> &a);
//   a: 합을 구해야 하는 정수 n개가 저장되어 있는 배열 (0 ≤ a[i] ≤ 1,000,000, 1 ≤ n ≤ 3,000,000)
//   리턴값: a에 포함되어 있는 정수 n개의 합

#include <vector>
long long sum(std::vector<int> &a) {
  long long ans = 0;
  for (long long i : a) {
    ans += i;
  }
  return ans;
}