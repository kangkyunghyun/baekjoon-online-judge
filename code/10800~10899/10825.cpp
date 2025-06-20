#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<vector<int>, string> a, pair<vector<int>, string> b) {
    if (a.first[0] == b.first[0]) {
        if (a.first[1] == b.first[1]) {
            if (a.first[2] == b.first[2])
                return a.second < b.second;
            return a.first[2] > b.first[2];
        }
        return a.first[1] < b.first[1];
    }
    return a.first[0] > b.first[0];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<vector<int>, string>> v;
    for (int i = 0; i < n; i++) {
        string name;
        vector<int> score(3);
        cin >> name >> score[0] >> score[1] >> score[2];
        v.push_back({score, name});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i : v)
        cout << i.second << '\n';
}