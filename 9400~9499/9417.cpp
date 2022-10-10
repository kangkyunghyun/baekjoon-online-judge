// 9417: 최대 GCD
//
// - 문제
// 정수 M개가 주어졌을 때, 모든 두 수의 쌍 중에서 가장 큰 최대공약수 찾는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 테스트 케이스의 개수 N (1 < N < 100)이 주어진다.
// 각 테스트 케이스는 한 줄로 이루어져 있으며, 양의 정수 M (1 < M < 100)개가 주어진다. 모든 수는 -231보다 크거나 같고, 231 -1보다 작거나 같다.
//
// - 출력
// 각 테스트 케이스마다, 입력으로 주어진 수의 모든 두 수의 쌍의 최대공약수 중 가장 큰 값을 출력한다.

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