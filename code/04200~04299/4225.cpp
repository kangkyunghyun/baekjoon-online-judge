#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Point {
    double x, y;
};

int n;
vector<Point> p, s;

double ccw(Point a, Point b, Point c) {
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

int convexHull() {
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
    return s.size();
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int cnt = 1;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        p.resize(n);
        s.clear();
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        convexHull();
        double ans = 1e9;
        for (int i = 0; i < s.size(); i++) {
            Point A = s[i], B = i == s.size() - 1 ? s[0] : s[i + 1];
            double a, b, c;
            if (A.x == B.x)
                a = 1, b = 0, c = 0;
            else if (A.y == B.y)
                a = 0, b = 1, c = 0;
            else
                a = (B.y - A.y) / (B.x - A.x), b = -1, c = A.y - a * A.x;
            double tmp = 0;
            for (int j = 0; j < s.size(); j++) {
                double dist = abs(a * s[j].x + b * s[j].y + c) / sqrt(a * a + b * b);
                tmp = max(tmp, dist);
            }
            ans = min(ans, tmp);
        }
        cout.precision(2);
        cout << fixed << "Case " << cnt++ << ": " << ceil(100.0 * ans) / 100.0 << '\n';
    }
}