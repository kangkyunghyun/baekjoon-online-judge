#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> cnt, ans;
    set<string> rep;
    multimap<string, string> info;
    for (string s : report) {
        rep.insert(s);
    }
    for (string s : rep) {
        int idx = s.find(' ');
        string a = s.substr(0, idx);
        string b = s.substr(idx + 1, s.size() - idx - 1);
        info.insert({a, b});
        cnt[b]++;
    }
    for (auto [a, b] : info) {
         ans[a] += (cnt[b] >= k);
    }
    for (string s : id_list) {
        answer.push_back(ans[s]);
    }
    return answer;
}