// CCW
#include <bits/stdc++.h>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int tmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (tmp > 0)
        return 1;
    else if (tmp < 0)
        return -1;
    else
        return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    pair<int, int> a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i].first >> a[i].second;
    cout << ccw(a[0].first, a[0].second, a[1].first, a[1].second, a[2].first, a[2].second);
    return 0;
}