#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

vector<int> kmp(string text, string pattern) {
    int N = text.size(), M = pattern.size();
    int fail[MAX] = {0};
    for (int i = 1, j = 0; i < M; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = fail[j - 1];
        if (pattern[i] == pattern[j])
            fail[i] = ++j;
    }
    vector<int> result;
    for (int i = 0, j = 0; i < N; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = fail[j - 1];
        if (text[i] == pattern[j]) {
            if (j == M - 1) {
                result.push_back(i - M + 1);
                j = fail[j];
            } else
                j++;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string T, P;
    getline(cin, T);
    getline(cin, P);
    for (int i : kmp(T, P))
        cout << i << ' ';
    return 0;
}
// O(N+M)