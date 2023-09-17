#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Vtuber {
  int hour, min, cnt;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, m;
  cin >> n >> m;
  set<string> s;
  vector<map<string, Vtuber>> M(m / 7);
  for (int i = 0; i < n; i++) {
    string name;
    int day, start_hour, start_min, stop_hour, stop_min;
    char tmp;
    cin >> name >> day >> start_hour >> tmp >> start_min >> stop_hour >> tmp >> stop_min;
    s.insert(name);
    int gap_hour = stop_hour - start_hour;
    int gap_min = stop_min - start_min;
    if (gap_min < 0) {
      gap_min = 60 + gap_min;
      gap_hour--;
    }
    int week = (day - 1) / 7;
    if (M[week].find(name) != M[week].end()) {
      Vtuber x = M[week][name];
      x.hour += gap_hour + (x.hour + gap_min) / 60;
      x.min = (x.min + gap_min) % 60;
      x.cnt++;
      M[week][name] = x;
    } else {
      M[week][name] = {gap_hour, gap_min, 1};
    }
  }
  int f = 0;
  for (string curr : s) {
    int flag = 0;
    for (int i = 0; i < m / 7; i++) {
      if (M[i].find(curr) != M[i].end()) {
        if (M[i][curr].hour < 60 || M[i][curr].cnt < 5) {
          flag = 1;
          break;
        }
      } else {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << curr << '\n';
      f = 1;
    }
  }
  if (!f)
    cout << -1;
  return 0;
}