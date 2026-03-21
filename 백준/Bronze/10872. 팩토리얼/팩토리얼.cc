#include <iostream>
using namespace std;

int factorial(int n, int ans = 1) {
  if (n > 1)
    return factorial(n - 1, ans * n);
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << factorial(n) << '\n';
  return 0;
}