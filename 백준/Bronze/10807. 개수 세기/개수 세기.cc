#include <iostream>
using namespace std;

int main() {
  int N, a, v;
  cin >> N;
  int arr[201] = {0};
  for (int i = 0; i < N; i++) {
    cin >> a;
    arr[a + 100]++;
  }
  cin >> v;
  cout << arr[v + 100];
}