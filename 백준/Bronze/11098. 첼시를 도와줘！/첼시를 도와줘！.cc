#include <iostream>
using namespace std;

int main() {
  int n, p, min = 0, m = 0;
  int arr[100];
  string str, top;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    min = 0;
    for (int j = 0; j < p; j++) {
      cin >> m >> str;
      if (min < m) {
        top = str;
        min = m;
      }
    }
    cout << top << '\n';
  }
  return 0;
}