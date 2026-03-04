#include <bits/stdc++.h>
using namespace std;

int value(int i, int j) {
    int n = max(abs(i), abs(j));
    int val = pow(2 * n + 1, 2);
    if (i == n)
        return val - n + j;
    val -= 2 * n;
    if (j == -n)
        return val - n + i;
    val -= 2 * n;
    if (i == -n)
        return val - n - j;
    val -= 2 * n;
    return val - n - i;
}

int gap(int val) {
    return val ? gap(val / 10) + 1 : 0;
}

signed main() {
    int r1, c1, r2, c2, g = 0;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    for (int i = r1; i <= r2; i++)
        for (int j = c1; j <= c2; j++)
            g = max(g, gap(value(i, j)));
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++)
            printf("%*d ", g, value(i, j));
        printf("\n");
    }
}