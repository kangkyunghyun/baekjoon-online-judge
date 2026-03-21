#include <bits/stdc++.h>
using namespace std;

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

string B[50];

int wbCnt(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      if (B[x + i][y + j] != WB[i][j])
        cnt++;
  return cnt;
}

int bwCnt(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      if (B[x + i][y + j] != BW[i][j])
        cnt++;
  return cnt;
}

int main() {
  int x, y, m = 12345;
  cin >> x >> y;
  for (int i = 0; i < x; i++)
    cin >> B[i];
  for (int i = 0; i + 8 <= x; i++) {
    for (int j = 0; j + 8 <= y; j++) {
      int temp = min(wbCnt(i, j), bwCnt(i, j));
      if (temp < m)
        m = temp;
    }
  }
  cout << m;
  return 0;
}