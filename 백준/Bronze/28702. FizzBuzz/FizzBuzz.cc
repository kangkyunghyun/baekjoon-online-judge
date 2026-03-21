#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  if (c[0] >= 48 && c[0] <= 57) {
    int x = stoi(c) + 1;
    if (x % 3 == 0) {
      if (x % 5 == 0) {
        cout << "FizzBuzz";
      } else {
        cout << "Fizz";
      }
    } else if (x % 5 == 0) {
      cout << "Buzz";
    } else {
      cout << x;
    }
  } else if (b[0] >= 48 && b[0] <= 57) {
    int x = stoi(b) + 2;
    if (x % 3 == 0) {
      if (x % 5 == 0) {
        cout << "FizzBuzz";
      } else {
        cout << "Fizz";
      }
    } else if (x % 5 == 0) {
      cout << "Buzz";
    } else {
      cout << x;
    }
  } else if (a[0] >= 48 && a[0] <= 57) {
    int x = stoi(a) + 3;
    if (x % 3 == 0) {
      if (x % 5 == 0) {
        cout << "FizzBuzz";
      } else {
        cout << "Fizz";
      }
    } else if (x % 5 == 0) {
      cout << "Buzz";
    } else {
      cout << x;
    }
  }
  return 0;
}