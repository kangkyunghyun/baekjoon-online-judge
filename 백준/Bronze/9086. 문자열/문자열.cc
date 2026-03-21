#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  string a;
  for (int i = 0; i < T; i++) {
    cin >> a;
    cout << a[0] << a[a.size() - 1] << '\n';
  }
}