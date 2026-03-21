#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{0, 0};
    map<string, int> m;
    for (int i = 0; i < words.size(); i++) {
        if (m.find(words[i]) != m.end() || (i > 0 && words[i].front() != words[i-1].back())) {
            answer = {i % n + 1, i / n + 1};
            break;
        }
        m[words[i]] = 1;
    }
    return answer;
}