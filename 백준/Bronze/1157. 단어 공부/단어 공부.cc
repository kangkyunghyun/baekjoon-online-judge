#include <iostream>
using namespace std;

int main() {
  int arr[26] = {0};
  int max = 0, result, cnt = 0;
  string str, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      str[i] -= 32;
    }
  }
  for (int j = 0; j < alphabet.length(); j++) {
    for (int k = 0; k < str.length(); k++) {
      if (alphabet[j] == str[k]) {
        arr[j] += 1;
      }
    }
  }
  for (int l = 0; l < 26; l++) {
    if (arr[l] > max) {
      max = arr[l];
      result = alphabet[l];
    }
  }
  for (int m = 0; m < 26; m++) {
    if (arr[m] == max) {
      cnt++;
    }
  }
  if (cnt > 1) {
    cout << '?' << '\n';
  } else {
    cout << (char)result << '\n';
  }
  return 0;
}