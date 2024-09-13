#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, s;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> s;
    for (int i = 0; i < n && s > 0; i++) {
        int maxIndex = i;
        for (int j = i; j <= min(n-1, i+s); j++)
            if (v[maxIndex] < v[j])
                maxIndex = j;
        for (int j = maxIndex; j > i; j--, s--)
            swap(v[j], v[j-1]);
    }
    for (int i : v)
        cout << i << ' ';
}