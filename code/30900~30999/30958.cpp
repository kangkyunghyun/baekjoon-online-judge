#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    vector<int> v(26,0);
    while(cin >> s) {
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= 'a' && s[i] <= 'z')
            v[s[i]-'a']++;
        }
    }
    cout << *max_element(v.begin(),v.end());
}