#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    string s;
    getline(cin, s);
    vector<string> v;
    stringstream ss(s);
    string tmp;
    while (ss >> tmp)
      v.push_back(tmp);
    char temp = v[v.size() - 1][v[v.size() - 1].size() - 1];
    v[v.size() - 1] = v[v.size() - 1].substr(0, v[v.size() - 1].size() - 1);
    for (int i = 0; i < v.size(); i++) {
      if (i + 2 < v.size()) {
        if (v[i + 1] == "of" && v[i + 2] == "Korea") {
          if (v[i][v[i].size() - 1] != '!' && v[i][v[i].size() - 1] != '?' && v[i][v[i].size() - 1] != ',' && v[i][v[i].size() - 1] != '.') {
            if (v[i][0] >= 'a' && v[i][0] <= 'z')
              v[i][0] -= 'a' - 'A';
            v[i] = "K-" + v[i];
            v.erase(v.begin() + i + 1);
            v.erase(v.begin() + i + 1);
            i--;
          }
        } else if (v[i + 1] == "of" && v[i + 2] == "Korea?") {
          if (v[i][v[i].size() - 1] != '!' && v[i][v[i].size() - 1] != '?' && v[i][v[i].size() - 1] != ',' && v[i][v[i].size() - 1] != '.') {
            if (v[i][0] >= 'a' && v[i][0] <= 'z')
              v[i][0] -= 'a' - 'A';
            v[i] = "K-" + v[i] + "?";
            v.erase(v.begin() + i + 1);
            v.erase(v.begin() + i + 1);
            i--;
          }
        } else if (v[i + 1] == "of" && v[i + 2] == "Korea!") {
          if (v[i][v[i].size() - 1] != '!' && v[i][v[i].size() - 1] != '?' && v[i][v[i].size() - 1] != ',' && v[i][v[i].size() - 1] != '.') {
            if (v[i][0] >= 'a' && v[i][0] <= 'z')
              v[i][0] -= 'a' - 'A';
            v[i] = "K-" + v[i] + "!";
            v.erase(v.begin() + i + 1);
            v.erase(v.begin() + i + 1);
            i--;
          }
        } else if (v[i + 1] == "of" && v[i + 2] == "Korea,") {
          if (v[i][v[i].size() - 1] != '!' && v[i][v[i].size() - 1] != '?' && v[i][v[i].size() - 1] != ',' && v[i][v[i].size() - 1] != '.') {
            if (v[i][0] >= 'a' && v[i][0] <= 'z')
              v[i][0] -= 'a' - 'A';
            v[i] = "K-" + v[i] + ",";
            v.erase(v.begin() + i + 1);
            v.erase(v.begin() + i + 1);
            i--;
          }
        }
      }
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      if (i + 1 < v.size()) {
        if (v[i] == "Korea") {
          if (v[i + 1][0] >= 'a' && v[i + 1][0] <= 'z')
            v[i + 1][0] -= 'a' - 'A';
          v[i] = "K-" + v[i + 1];
          v.erase(v.begin() + i + 1);
        }
      }
    }
    for (int i = 0; i < v.size() - 1; i++) {
      cout << v[i] << ' ';
    }
    cout << v[v.size() - 1] << temp << '\n';
  }
}