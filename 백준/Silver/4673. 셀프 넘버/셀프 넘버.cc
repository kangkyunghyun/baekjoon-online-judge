#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[10001] = {0};
  for (int i = 1; i < 10001; i++) {
    string num = to_string(i);
    int newNum = i;
    for (char j : num)
      newNum += j - '0';
    if (newNum <= 10000)
      arr[newNum]++;
  }
  for (int i = 1; i < 10001; i++)
    if (!arr[i])
      cout << i << '\n';
  return 0;
}