#include <bits/stdc++.h>
using namespace std;
#define int long long

int A, B, C, visited[201][201][201];

struct water {
    int a, b, c;
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> A >> B >> C;
    queue<water> q;
    q.push({0, 0, C});
    set<int> ans;
    while (!q.empty()) {
        water curr = q.front();
        q.pop();
        auto [a, b, c] = curr;
        if (visited[a][b][c])
            continue;
        visited[a][b][c] = 1;
        if (a == 0)
            ans.insert(c);
        if (a + b > B)
            q.push({a + b - B, B, c});
        else
            q.push({0, a + b, c});
        if (a + c > C)
            q.push({a + c - C, b, C});
        else
            q.push({0, b, a + c});
        if (a + b > A)
            q.push({A, a + b - A, c});
        else
            q.push({a + b, 0, c});
        if (b + c > C)
            q.push({a, b + c - C, C});
        else
            q.push({a, 0, b + c});
        if (a + c > A)
            q.push({A, b, a + c - A});
        else
            q.push({a + c, b, 0});
        if (b + c > B)
            q.push({a, B, b + c - B});
        else
            q.push({a, b + c, 0});
    }
    for (auto i = ans.begin(); i != ans.end(); i++)
        cout << *i << ' ';
}