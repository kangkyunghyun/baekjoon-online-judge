// 6810: ISBN
//
// - 문제
// The International Standard Book Number (ISBN) is a 13-digit code for identifying books. These numbers have a special property for detecting whether the number was written correctly.
// The 1-3-sum of a 13-digit number is calculated by multiplying the digits alternately by 1’s and 3’s (see example) and then adding the results. For example, to compute the 1-3-sum of the number 9780921418948 we add
// 9 ∗ 1 + 7 ∗ 3 + 8 ∗ 1 + 0 ∗ 3 + 9 ∗ 1 + 2 ∗ 3 + 1 ∗ 1 + 4 ∗ 3 + 1 ∗ 1 + 8 ∗ 3 + 9 ∗ 1 + 4 ∗ 3 + 8 ∗ 1
// to get 120.
// The special property of an ISBN number is that its 1-3-sum is always a multiple of 10.
// Write a program to compute the 1-3-sum of a 13-digit number. To reduce the amount of typing, you may assume that the first ten digits will always be 9780921418, like the example above. Your program should input the last three digits and then print its 1-3-sum. Use a format similar to the samples below.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  cout << "The 1-3-sum is " << 91 + a + b * 3 + c;
  return 0;
}