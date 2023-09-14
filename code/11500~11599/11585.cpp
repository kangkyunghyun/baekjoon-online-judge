#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

vector<int> kmp(string text, string pattern) {
  int N = text.size() - 1, M = pattern.size();
  int fail[MAX] = {0};
  for (int i = 1, j = 0; i < M; i++) {
    while (j > 0 && pattern[i] != pattern[j])
      j = fail[j - 1];
    if (pattern[i] == pattern[j])
      fail[i] = ++j;
  }
  vector<int> result;
  for (int i = 0, j = 0; i < N; i++) {
    while (j > 0 && text[i] != pattern[j])
      j = fail[j - 1];
    if (text[i] == pattern[j]) {
      if (j == M - 1) {
        result.push_back(i - M + 1);
        j = fail[j];
      } else
        j++;
    }
  }
  return result;
}

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  string T, P;
  char c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    P += c;
  }
  for (int i = 0; i < n; i++) {
    cin >> c;
    T += c;
  }
  int p = kmp(T + T, P).size();
  int g = gcd(n, p);
  cout << p / g << '/' << n / g;
  return 0;
}