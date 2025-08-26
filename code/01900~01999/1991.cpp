#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
char arr[26][2];

void preOrder(int curr) {
    if (curr + 'A' == '.')
        return;
    cout << (char)(curr + 'A');
    preOrder(arr[curr][0] - 'A');
    preOrder(arr[curr][1] - 'A');
}

void inOrder(int curr) {
    if (curr + 'A' == '.')
        return;
    inOrder(arr[curr][0] - 'A');
    cout << (char)(curr + 'A');
    inOrder(arr[curr][1] - 'A');
}

void postOrder(int curr) {
    if (curr + 'A' == '.')
        return;
    postOrder(arr[curr][0] - 'A');
    postOrder(arr[curr][1] - 'A');
    cout << (char)(curr + 'A');
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c >> arr[c - 'A'][0] >> arr[c - 'A'][1];
    }
    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
}