#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> hamburger(3);
  vector<int> drink(2);
  for (int i = 0; i < 3; i++)
    cin >> hamburger[i];
  for (int i = 0; i < 2; i++)
    cin >> drink[i];
  int max = hamburger[0] + drink[0];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      if (hamburger[i] + drink[j] < max)
        max = hamburger[i] + drink[j];
  cout << max - 50;
  return 0;
}