#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans=0;
int visited[1001];
int rome[4]={1,5,10,50};

void dfs(int m, int depth, int sum) {
	if (depth == n) {
		if (!visited[sum]) {
			visited[sum]=1;
			ans++;
		}
		return;
	}
	for (int i = m; i < 4; i++)
		dfs(i, depth+1, sum+rome[i]);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	dfs(0,0,0);
	cout << ans;
}