#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < alphabet.length(); i++) {
    cout << (int)s.find(alphabet[i]) << '\n';
  }
}