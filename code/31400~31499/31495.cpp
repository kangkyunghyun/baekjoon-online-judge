#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin,s);
    if (s[0]=='"' && s[s.size()-1]=='"'){
        if(s.substr(1,s.size()-2)=="")
            cout<<"CE";
        else
        cout<<s.substr(1,s.size()-2);
    }else{
        cout<<"CE";
	}
}