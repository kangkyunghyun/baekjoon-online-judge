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
    vector<int> errors;
    int size = ss.size();
    if (ss[0] == "jiggle")
      errors.push_back(4);
    if (size >= 3 && !(ss[size - 3] == "clap" && ss[size - 2] == "stomp" && ss[size - 1] == "clap"))
      errors.push_back(2);
    else if (size < 3)
      errors.push_back(2);
    int twirl = 0, hop = 0, dip = 0;
    for (int i = 0; i < ss.size(); i++) {
      if (ss[i] == "twirl")
        twirl = 1;
      if (ss[i] == "hop")
        hop = 1;
      if (ss[i] == "dip") {
        dip = 1;
        int flag = 1;
        if (i - 1 >= 0 && ss[i - 1] == "jiggle")
          flag = 0;
        else if (i - 2 >= 0 && ss[i - 2] == "jiggle")
          flag = 0;
        else if (i + 1 < size && ss[i + 1] == "twirl")
          flag = 0;
        if (flag) {
          errors.push_back(1);
          ss[i] = "DIP";
        }
      }
    }
    if (!dip)
      errors.push_back(5);
    if (twirl && !hop)
      errors.push_back(3);
    errors.erase(unique(errors.begin(), errors.end()), errors.end());
    sort(errors.begin(), errors.end());
    int errSize = errors.size();
    if (errSize == 0) {
      cout << "form ok: " << s << '\n';
    } else if (errSize == 1) {
      cout << "form error " << errors[0] << ": ";
      for (string i : ss)
        cout << i << ' ';
      cout << '\n';
    } else if (errSize > 1) {
      cout << "form errors ";
      for (int i = 0; i < errSize; i++) {
        cout << errors[i];
        if (i == errSize - 2)
          cout << " and ";
        else if (i == errSize - 1)
          cout << ": ";
        else
          cout << ", ";
      }
      for (string i : ss)
        cout << i << ' ';
      cout << '\n';
    }
  }
  return 0;
}