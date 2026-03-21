#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int c,k,p;
  cin>>c>>k >>p;
  cout<<k*c*(c+1)/2+p*c*(c+1)*(2*c+1)/6;
  return 0;
}