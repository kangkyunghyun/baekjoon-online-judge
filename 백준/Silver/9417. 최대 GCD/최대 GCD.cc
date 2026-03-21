#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  string s;
  for (int i = 0; i < n; i++) {
    vector<int> arr;
    getline(cin, s);
    s += ' ';
    int index = 0, ws = s.find(' '), max = 0;
    while (ws != string::npos) {
      string num = s.substr(index, ws - index);
      arr.push_back(stoi(num));
      index = ws + 1;
      ws = s.find(' ', index);
    }
    for (int i = 0; i < arr.size(); i++)
      for (int j = i + 1; j < arr.size(); j++) {
        int g = gcd(arr[i], arr[j]);
        if (max < g)
          max = g;
      }
    cout << max << '\n';
  }
  return 0;
}