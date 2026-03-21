#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (true) {
        int x;
        cin >> x;
        if (x == 0) break;
        cout << x << " is";
        if (x % n != 0) {
            cout << " NOT";
        }
        cout << " a multiple of " << n << ".\n";
    }
    return 0;
}