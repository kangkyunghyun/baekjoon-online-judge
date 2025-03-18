#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sorted[100000];

void merge(ll *data, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (data[i] <= data[j]) {
            sorted[k] = data[i];
            i++;
        } else {
            sorted[k] = data[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (int t = j; t <= end; t++) {
            sorted[k] = data[t];
            k++;
        }
    } else {
        for (int t = i; t <= mid; t++) {
            sorted[k] = data[t];
            k++;
        }
    }
    for (int t = start; t <= end; t++) {
        data[t] = sorted[t];
    }
}

void merge_sort(ll *data, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll arr[100000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}