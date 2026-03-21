#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,l,x;cin>>n>>l;priority_queue<pair<int,int>>q;for(int i=1;i<=n;i++){cin>>x;q.push({-x,i});while(q.top().second<=i-l)q.pop();cout<<-q.top().first<<' ';}}