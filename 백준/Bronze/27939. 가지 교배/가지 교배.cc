#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a=0;
  cin>>n;
    vector<char> v(n);
    for (int i=0;i<n;i++)
cin>>v[i];
    int m, k;
    cin>>m>>k;
    for (int i=0;i<m;i++){
        int tmp=0;
for (int j =0;j<k;j++){
    int x;
    cin>>x;
    if(v[x-1]=='P')
        tmp++;
}
        if (tmp==0)
            a++;
            
}
    if(a!=0)
        cout<<'W';
    else
        cout<<'P';
  return 0;
}