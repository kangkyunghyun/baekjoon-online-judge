// 20530: Shipping
//
// - 문제
// Your animals have begun producing products, and you’re honestly a little strapped for cash. Since you have far more animal byproducts than you know what to do with, you’ve decided to begin shipping them for extra money. Given the information in your shipping ledger, determine how much money you can expect to make.
//
// - 입력
// The first line will contain a single integer n that indicates the number of data sets that follow. Each data set will start with a single integer x denoting how many items follow. The next x lines consist of a string, and integer, and a floating point number to two decimal places, representing the name of what was sold, the quantity, and the unit price of each item.
//
// - 출력
// For each test case, output the amount of money you expect to make with all of the goods you sold, rounded to two decimal places.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    double sum = 0;
    while (x--) {
      string s;
      int a;
      double b;
      cin >> s >> a >> b;
      sum += b * a;
    }
    cout.precision(2);
    cout << '$' << fixed << round(sum * 100) / 100 << '\n';
  }
  return 0;
}