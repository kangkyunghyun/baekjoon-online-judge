#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0), parent(referral.size(), -1);
    map<string, int> person;
    for (int i = 0; i < enroll.size(); i++) {
        person[enroll[i]] = i;
    }
    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] == "-")
            continue;
        parent[i] = person[referral[i]];
    }
    for (int i = 0; i < seller.size(); i++) {
        int curr = person[seller[i]];
        int p = parent[curr];
        int v_p = 10 * amount[i];
        int v_curr = 100 * amount[i] - v_p;
        while(1) {
            answer[curr] += v_curr;
            if (p == -1)
                break;
            curr = p;
            p = parent[curr];
            int tmp = v_p;
            v_p = 0.1 * v_p;
            v_curr = tmp - v_p;
        }
    }
    return answer;
}