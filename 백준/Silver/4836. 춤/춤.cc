#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    vector<string> ss;
    string sss;
    stringstream stream(s);
    while (stream >> sss)
      ss.push_back(sss);
    vector<int> errors(6, 0);
    int size = ss.size();
    int twirl = 0, hop = 0, dip = 0;
    for (int i = 0; i < size; i++) {
      if (ss[i] == "dip") {
        dip = 1;
        if (!((i - 1 >= 0 && ss[i - 1] == "jiggle") || (i - 2 >= 0 && ss[i - 2] == "jiggle") || (i + 1 < size && ss[i + 1] == "twirl"))) {
          errors[1] = 1;
          ss[i] = "DIP";
        }
      } else if (ss[i] == "twirl") {
        twirl = 1;
      } else if (ss[i] == "hop") {
        hop = 1;
      }
    }
    if (size < 3 || !(ss[size - 1] == "clap" && ss[size - 2] == "stomp" && ss[size - 3] == "clap"))
      errors[2] = 1;
    if (twirl && !hop)
      errors[3] = 1;
    if (ss[0] == "jiggle")
      errors[4] = 1;
    if (!dip)
      errors[5] = 1;
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
      if (errors[i] == 1)
        cnt++;
    cout << "form ";
    if (cnt == 0) {
      cout << "ok: ";
    } else if (cnt == 1) {
      cout << "error ";
      for (int i = 1; i <= 5; i++)
        if (errors[i] == 1)
          cout << i << ": ";
    } else {
      cout << "errors ";
      int tmp = 0;
      for (int i = 1; i <= 5; i++) {
        if (errors[i] == 1) {
          tmp++;
          cout << i;
          if (tmp == 0)
            continue;
          else if (tmp < cnt - 1)
            cout << ", ";
          else if (tmp == cnt - 1)
            cout << " and ";
          else
            cout << ": ";
        }
      }
    }
    for (string i : ss)
      cout << i << ' ';
    cout << '\n';
  }
  return 0;
}