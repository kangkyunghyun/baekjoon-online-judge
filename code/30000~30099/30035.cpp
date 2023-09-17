#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, t, sum = 0;
  cin >> n >> t;
  map<string, pair<int, int>> m;
  while (t--) {
    string name, num;
    cin >> name >> num;
    if (num[num.size() - 1] == '%') {
      int idx = num.find('%');
      int tmp = (double)n * stoi(num.substr(0, idx)) / 100;
      n -= tmp;
      m[name] = {sum + 1, sum + tmp};
      int temp = ceil((double)tmp / 4);
      if (temp > tmp) {
        m[name + '1'] = {sum + 1, sum + tmp};
        sum += tmp;
      } else {
        m[name + '1'] = {sum + 1, sum + temp};
        tmp -= temp;
        sum += temp;
      }
      if (temp > tmp) {
        m[name + '2'] = {sum + 1, sum + tmp};
        sum += tmp;
      } else {
        m[name + '2'] = {sum + 1, sum + temp};
        tmp -= temp;
        sum += temp;
      }
      if (temp > tmp) {
        m[name + '3'] = {sum + 1, sum + tmp};
        sum += tmp;
      } else {
        m[name + '3'] = {sum + 1, sum + temp};
        tmp -= temp;
        sum += temp;
      }
      if (temp > tmp) {
        m[name + '4'] = {sum + 1, sum + tmp};
        sum += tmp;
      } else {
        m[name + '4'] = {sum + 1, sum + temp};
        tmp -= temp;
        sum += temp;
      }
    } else {
      int tmp = min(n, stoi(num));
      n -= tmp;
      m[name] = {sum + 1, sum + tmp};
      int temp = ceil((double)tmp / 4);
      if (temp > tmp) {
        m[name + '1'] = {sum + 1, sum + tmp};
        sum += tmp;
      } else {
        m[name + '1'] = {sum + 1, sum + temp};
        tmp -= temp;
        sum += temp;
      }
      if (temp > tmp) {
        m[name + '2'] = {sum + 1, sum + tmp};
        sum += tmp;
      } else {
        m[name + '2'] = {sum + 1, sum + temp};
        tmp -= temp;
        sum += temp;
      }
      if (temp > tmp) {
        m[name + '3'] = {sum + 1, sum + tmp};
        sum += tmp;
      } else {
        m[name + '3'] = {sum + 1, sum + temp};
        tmp -= temp;
        sum += temp;
      }
      if (temp > tmp) {
        m[name + '4'] = {sum + 1, sum + tmp};
        sum += tmp;
      } else {
        m[name + '4'] = {sum + 1, sum + temp};
        tmp -= temp;
        sum += temp;
      }
    }
  }
  string q;
  cin >> q;
  if (n != 0) {
    cout << "Invalid System";
  } else {
    pair<int, int> ans = m[q];
    if (ans.first > ans.second)
      cout << "Liar";
    else
      cout << ans.first << ' ' << ans.second;
  }
}