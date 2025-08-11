// O(NlogN)
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Point {
    int x, y;
};

int n;
vector<Point> p, s;

int ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmpY(Point a, Point b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

bool cmpCCW(Point a, Point b) {
    int cc = ccw(p[0], a, b);
    return cc ? cc > 0 : cmpY(a, b);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    sort(p.begin(), p.end(), cmpY);
    sort(p.begin() + 1, p.end(), cmpCCW);
    s.push_back(p[0]);
    s.push_back(p[1]);
    for (int i = 2; i < n; i++) {
        while (s.size() >= 2) {
            Point second = s.back();
            s.pop_back();
            Point first = s.back();
            if (ccw(first, second, p[i]) > 0) {
                s.push_back(second);
                break;
            }
        }
        s.push_back(p[i]);
    }
    cout << s.size();
    return 0;
}