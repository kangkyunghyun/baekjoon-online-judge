#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    int arr[26] = {0};
    string str;
    getline(cin, str);
    for (char elem : str)
      if (elem != ' ') {
        int num = elem;
        if (num >= 65 && num <= 90)
          arr[num - 65]++;
        else if (num >= 97 && num <= 122)
          arr[num - 97]++;
      }
    if (*min_element(arr, arr + 26) == 0)
      cout << "Case " << i + 1 << ": Not a pangram\n";
    else if (*min_element(arr, arr + 26) == 1)
      cout << "Case " << i + 1 << ": Pangram!\n";
    else if (*min_element(arr, arr + 26) == 2)
      cout << "Case " << i + 1 << ": Double pangram!!\n";
    else if (*min_element(arr, arr + 26) == 3)
      cout << "Case " << i + 1 << ": Triple pangram!!!\n";
  }
  return 0;
}