#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp1(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

bool cmp2(pair<int,int> a, pair<int,int> b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < 2; i++)
		cout << v[i].first << ' ' << v[i].second << ' ';
	cout << '\n';
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < 2; i++)
		cout << v[i].first << ' ' << v[i].second << ' ';
}