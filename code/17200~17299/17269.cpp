#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> solve(vector<int> v) {
    if (v.size() == 2)
        return v;
    vector<int> tmp;
    for (int i = 0; i < v.size()-1; i++)
        tmp.push_back((v[i]+v[i+1])%10);
    return solve(tmp);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, m;
    string A, B;
    cin >> n >> m >> A >> B;
    vector<int> v;
    int arr[] = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};
    for(int i = 0; i < max(n,m); i++) {
        if (i < n) {
            v.push_back(arr[A[i]-'A']);
        }
        if (i < m) {
            v.push_back(arr[B[i]-'A']);
        }
    }
    vector<int> ans = solve(v);
    if (ans[0] != 0)
        cout << ans[0];
    cout << ans[1] << '%';
}