#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "WelcomeToSMUPC";
  int n;
  cin >> n;
  cout << s[(n - 1) % 14];
}