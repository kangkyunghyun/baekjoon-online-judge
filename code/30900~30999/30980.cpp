#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> v(3*n);
    for (int i = 0; i < 3*n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < 3*n; i+=3) { //각 줄
        for (int j = 0; j < 8*m; j+=8){ // 각 식
            int a = v[i][j+1] - '0';
            int b = v[i][j+3] - '0';
            int c,flag=0;
            if (v[i][j+6] >= '0' && v[i][j+6] <= '9') {
                c = (v[i][j+5] - '0')*10 + (v[i][j+6] - '0');
                flag=1;
            } else {
                c = v[i][j+5] - '0';
            }
            if (a+b==c){
                if (flag) {
                    for(int k=1;k<7;k++){
                        v[i-1][j+k]='*';
                        v[i+1][j+k]='*';
                    }
                    v[i][j]='*';
                    v[i][j+7]='*';
                } else {
                    for(int k=1;k<6;k++){
                        v[i-1][j+k]='*';
                        v[i+1][j+k]='*';
                    }
                    v[i][j]='*';
                    v[i][j+6]='*';
                }
            } else {
                v[i-1][j+3]='/';
                v[i][j+2]='/';
                v[i+1][j+1]='/';
            }
        }
    }
    for (string i : v)
        cout << i << '\n';
}