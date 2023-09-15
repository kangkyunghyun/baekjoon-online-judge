#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int ac = 0, wa = 0;
  map<string, int> m;
  set<string> s;
  while (n--) {
    int num, result, memory, time, lang, len;
    string id;
    cin >> num >> id >> result >> memory >> time >> lang >> len;
    if (id == "megalusion")
      continue;
    if (s.find(id) == s.end()) {
      if (result == 4) {
        ac++;
        s.insert(id);
        if (m.find(id) != m.end())
          wa += m[id];
      } else {
        if (m.find(id) != m.end())
          m[id]++;
        else
          m[id] = 1;
      }
    }
  }
  cout.precision(9);
  if (ac == 0)
    cout << 0;
  else
    cout << fixed << (double)ac / (ac + wa) * 100;
  return 0;
}