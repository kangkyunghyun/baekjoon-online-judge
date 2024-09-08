#include <bits/stdc++.h>
using namespace std;
#define int long long

void hanoi(int n, int source, int dest, int aux) {
    if (n == 1) {
        cout << source << ' ' << dest << '\n';
    } else {
        hanoi(n - 1, source, aux, dest);
        cout << source << ' ' << dest << '\n';
        hanoi(n - 1, aux, dest, source);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << '\n';
    hanoi(n, 1, 3, 2);
}