#include <iostream>
using namespace std;

int main() {
  int a, max, max_index;
  int arr[9] = {0};
  for (int i = 0; i < 9; i++) {
    cin >> a;
    arr[i] = a;
  }
  max = arr[0];
  max_index = 0;
  for (int i = 0; i < 9; i++) {
    if (arr[i] > max) {
      max = arr[i];
      max_index = i;
    }
  }
  cout << max << '\n';
  cout << max_index + 1 << '\n';
  return 0;
}