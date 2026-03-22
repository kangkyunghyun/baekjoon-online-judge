#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0, num;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int sum = accumulate(v.begin(), v.end(), 0);
  float avg = floor((float)sum / n + 0.5);
  int arr[8001] = {0};
  for (int i : v)
    arr[i + 4000]++;
  for (int i : arr)
    if (i > cnt)
      cnt = i;
  vector<int> arr1;
  for (int i = 0; i < 8001; i++)
    if (arr[i] == cnt)
      arr1.push_back(i - 4000);
  sort(arr1.begin(), arr1.end());
  if (arr1.size() > 1)
    num = arr1[1];
  else
    num = arr1[0];
  cout << avg << '\n';
  cout << v[(n - 1) / 2] << '\n';
  cout << num << '\n';
  cout << (v[v.size() - 1] - v[0]) << '\n';
  return 0;
}