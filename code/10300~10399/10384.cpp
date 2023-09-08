// 10384: 팬그램
//
// - 문제
// 팬그램은 모든 알파벳을 적어도 한 번씩을 사용한 영어 문장을 말한다.
// 다음은 유명한 팬그램 중 하나이다.
// The quick brown fox jumps over a lazy dog
// 더블 팬그램은 모든 알파벳을 적어도 두 번씩은 사용한 문장을 말하고,
// 트리플 팬그램은 모든 알파벳을 적어도 세 번씩은 사용한 문장을 말한다.
// 더 이어나갈 수도 있겠지만 시간상 여기까지만 하도록 하겠다.
//
// - 입력
// 입력은 여러 줄의 테스트케이스들로 이루어진다.
// 첫째 줄에 테스트케이스의 수 n이 주어진다.
// 각 테스트케이스는 영어 소문자와 대문자, 특수기호들로 이루어진다.
//
// - 출력
// 각 케이스마다 한 줄에 하나씩 다음 중 하나를 출력한다.

// 팬그램이 아닐 경우 - Not a pangram
// 팬그램일 경우 - Pangram!
// 더블 팬그램일 경우 - Double pangram!!
// 트리플 팬그램일 경우 - Triple pangram!!!
// 트리플 팬그램일 경우에는 자연스럽게 팬그램과 더블 팬그램이 되지만, Triple pangram!!!만을 출력한다. 더블 팬그램도 마찬가지이다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    int arr[26] = {0};
    string str;
    getline(cin, str);
    for (char elem : str)
      if (elem != ' ') {
        int num = elem;
        if (num >= 65 && num <= 90)
          arr[num - 65]++;
        else if (num >= 97 && num <= 122)
          arr[num - 97]++;
      }
    if (*min_element(arr, arr + 26) == 0)
      cout << "Case " << i + 1 << ": Not a pangram\n";
    else if (*min_element(arr, arr + 26) == 1)
      cout << "Case " << i + 1 << ": Pangram!\n";
    else if (*min_element(arr, arr + 26) == 2)
      cout << "Case " << i + 1 << ": Double pangram!!\n";
    else if (*min_element(arr, arr + 26) == 3)
      cout << "Case " << i + 1 << ": Triple pangram!!!\n";
  }
  return 0;
}