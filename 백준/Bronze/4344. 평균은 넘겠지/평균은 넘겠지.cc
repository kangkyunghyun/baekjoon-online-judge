#include <iostream>
using namespace std;

int main() {
  cout.precision(3);
  cout << fixed;
  int c, n, score, sum, cnt;
  float avg;
  int arr[1000] = {0};
  cin >> c;
  for (int i = 0; i < c; i++) {
    cin >> n;
    sum = 0;
    cnt = 0;
    for (int j = 0; j < n; j++) {
      cin >> score;
      arr[j] = score;
      sum += score;
    }
    avg = (float)(sum / n);
    for (int j = 0; j < n; j++) {
      if (arr[j] > avg)
        cnt++;
    }
    cout << (float)cnt / n * 100 << '%' << '\n';
  }
  return 0;
}