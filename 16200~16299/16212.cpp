// 16212: 정열적인 정렬
//
// - 문제
// 형준이는 수열을 하나 가지고 있다. 형준이는 수열을 정열적으로 정렬해보려 한다. 과연, 정렬할 수 있을까?
//
// - 입력
// 첫째 줄에는 수열의 길이 N (1 ≤ N ≤ 500,000)이 주어진다.
// 둘째 줄에는 수열의 각 원소 ai가 공백을 사이에 두고 차례대로 주어진다. ai의 절댓값은 200만 이하이다.
//
// - 출력
// 수열 a를 오름차순으로 정렬해서, 공백을 사이에 두고 하나씩 차곡차곡 출력하자.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
  cout << '\n';
  delete[] arr;
  return 0;
}