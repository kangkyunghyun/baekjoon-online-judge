#include <iostream>
using namespace std;

int main() {
  int n, score, max = 0;
  float sum = 0;
  cin >> n;
  int arr[1000] = {0};
  for (int i = 0; i < n; i++) {
    cin >> score;
    arr[i] = score;
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  for (int i = 0; i < n; i++) {
    sum += (float)arr[i] / max * 100;
  }
  cout << (float)sum / n << '\n';
  return 0;
}