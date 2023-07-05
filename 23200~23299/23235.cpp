// 23235: The Fastest Sorting Algorithm In The World
//
// - 문제
// It is common to compare sorting algorithms based on their asymptotic speeds. Some slower algorithms like selection sort take O(N2) time to sort N items, while comparison-based sorts like merge sort can go no faster than O(N log(N)) time, under reasonable assumptions. Bucket sort, which is not a comparison-based sort, can sort in O(N) time. This is because bucket sort assumes that the range of possible values is small relative to N. In general, the speed of a sorting algorithm depends on the assumptions it can make about the data it is sorting.
// One sorting algorithm that is often overlooked, despite its speed, is The Fastest Sorting Algorithm In The World. It sorts in O(1), or constant, time. Of course, the algorithm assumes that the input is an array that is already in fast-access memory and that the input is already sorted. For this problem, implement The Fastest Sorting Algorithm In The World.
//
// - 입력
// The input file contains multiple test cases, each of which describes an array to sort. Each array description starts with an integer 0 < N ≤ 100. N is followed by the N integers to sort, which will be given in non-decreasing order. All integers to sort are in the range of 0 to 100000. The last test case is followed by a line containing a single zero.
//
// - 출력
// For each test case, print the case number (beginning with 1) followed by the text Sorting... done!

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int cnt = 0;
  while (getline(cin, s) && s != "0") {
    cnt++;
    cout << "Case " << cnt << ": Sorting... done!\n";
  }
  return 0;
}