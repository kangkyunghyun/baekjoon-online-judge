#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int arr[20], sum = 0, index;
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] == 20)
            index = i;
    }
    double bob = (double)sum / 20, alice = 0;
    if (index == 0)
        alice = (double)(arr[0] + arr[1] + arr[19]) / 3;
    else if (index == 19)
        alice = (double)(arr[0] + arr[18] + arr[19]) / 3;
    else
        alice = (double)(arr[index - 1] + arr[index] + arr[index + 1]) / 3;
    if (alice < bob)
        cout << "Bob";
    else if (alice > bob)
        cout << "Alice";
    else
        cout << "Tie";
}