#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    deque<char> x, y;
    for (char c : a)
        x.push_back(c);
    for (char c : b)
        y.push_back(c);
    while (!x.empty() && !y.empty() && x.front() == y.front()) {
        x.pop_front();
        y.pop_front();
    }
    while (!x.empty() && !y.empty() && x.back() == y.back()) {
        x.pop_back();
        y.pop_back();
    }
    cout << y.size();
}