#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string A, T;
  cin >> A >> T;
  int left = 0, right = T.size() - 1;
  deque<char> front, back;
  while (left <= right) {
    while (left <= right) {
      front.push_back(T[left]);
      left++;
      int flag = 0;
      if (front.size() >= A.size()) {
        flag = 1;
        for (int i = 0; i < A.size(); i++)
          if (front[front.size() - A.size() + i] != A[i]) {
            flag = 0;
            break;
          }
      }
      if (flag) {
        for (int i = 0; i < A.size(); i++)
          front.pop_back();
        break;
      }
    }
    while (left <= right) {
      back.push_front(T[right]);
      right--;
      int flag = 0;
      if (back.size() >= A.size()) {
        flag = 1;
        for (int i = 0; i < A.size(); i++)
          if (back[i] != A[i]) {
            flag = 0;
            break;
          }
      }
      if (flag) {
        for (int i = 0; i < A.size(); i++)
          back.pop_front();
        break;
      }
    }
  }
  T = "";
  for (int i = 0; i < front.size(); i++)
    T += front[i];
  for (int i = 0; i < back.size(); i++)
    T += back[i];
  while (T.find(A) != string::npos)
    T.erase(T.find(A), A.size());
  cout << T << '\n';
  return 0;
}