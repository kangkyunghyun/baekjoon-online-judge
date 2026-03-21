#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr, ans;
  for (int i = 0; i < n; i++)
    arr.push_back(i + 1);
  for (int i = k - 1; arr.size() != 0; i += k - 1) {
    while (i >= arr.size())
      i -= arr.size();
    ans.push_back(arr[i]);
    arr.erase(arr.begin() + i);
  }
  cout << "<";
  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << ">\n";
  return 0;
}