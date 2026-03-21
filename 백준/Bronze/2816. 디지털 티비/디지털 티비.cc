#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
  vector<int> v;
  for (int i = 1; i <= n; i++)
    if (n % i == 0)
      v.push_back(i);
  int sum = 0;
  for (int i = 0; i < v.size() - 1; i++)
    sum += v[i];
  if (sum > n)
    return true;
  else
    return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] != "KBS1")
      cout << 1;
    else {
      idx = i;
      break;
    }
  }
  while (v[0] != "KBS1") {
    cout << 4;
    string tmp = v[idx - 1];
    v[idx - 1] = v[idx];
    v[idx] = tmp;
    idx--;
  }
  int temp;
  for (int i = 1; i < n; i++)
    if (v[i] == "KBS2") {
      temp = i;
      break;
    }
  int gap = idx - temp;
  if (gap > 0) {
    while (gap > 0) {
      cout << 2;
      idx--;
      gap--;
    }
  } else {
    while (gap < 0) {
      cout << 1;
      idx++;
      gap++;
    }
  }
  while (v[1] != "KBS2") {
    cout << 4;
    string tmp = v[idx - 1];
    v[idx - 1] = v[idx];
    v[idx] = tmp;
    idx--;
  }
  return 0;
}