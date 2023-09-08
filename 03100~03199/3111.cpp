// 3111: 검열
//
// - 문제
// 김상근은 창영마을에서의 권력을 유지하기 위해 신문을 검열하려고 한다.
// 상근이는 텍스트 T에서 A라는 단어를 다음과 같은 알고리즘을 이용해서 모두 없애려고 한다.
// T에 A가 없으면 알고리즘을 종료한다.
// T에서 처음 등장하는 A를 찾은 뒤, 삭제한다.
// T에 A가 없으면 알고리즘을 종료한다.
// T에서 마지막으로 등장하는 A를 찾은 뒤, 삭제한다.
// 1번으로 돌아간다.
// 상근이는 마을을 지배해야하기 때문에, 검열을 할 시간이 없다. 상근이의 검열을 대신해주는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 단어 A가, 둘째 줄에 텍스트 T가 주어진다. A와 T는 알파벳 소문자로만 이루어져 있고, A는 최대 25자, T는 최대 300,000자이다.
//
// - 출력
// 검열을 한 이후의 텍스트를 출력한다.

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