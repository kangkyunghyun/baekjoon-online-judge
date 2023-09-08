// 4836: 춤
//
// - 문제
// 창영이는 요즘 춤을 배우고 있다. 창영이는 다음과 같은 규칙을 따라서 춤을 추어야 한다.
// 1. dip은 jiggle을 춘 다음이나 다다음, 또는 twirl을 추기 전에 출 수 있다. 예를 들면 다음과 같다.
//   ...jiggle dip...
//   ...jiggle stomp dip...
//   ...dip twirl...
// 2. 모든 춤은 clap stomp clap으로 끝나야 한다.
// 3. 만약 twirl을 췄다면, hop도 춰야한다.
// 4. jiggle로 춤을 시작할 수 없다.
// 5. 반드시 dip을 춰야 한다.
// 창영이가 춘 춤이 주어졌을 때, 위의 규칙을 지켰는지 아닌지를 알아내는 프로그램을 작성하시오.
//
// - 입력
// 입력은 여러개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 창영이가 춘 춤이 주어진다. 각 춤은 1000스텝을 넘지 않는다. 각 스텝 알파벳 소문자로 이루어져 있고, 100글자를 넘지 않는다.
//
// - 출력
// 창영이의 춤이 규칙을 모두 지켰다면, "form ok: "를 출력하고 입력으로 주어진 춤을 출력한다.
// 창영이의 춤이 규칙을 1개만 어겼다면, "form error K: "를 출력하고 입력으로 주어진 춤을 출력한다. 여기서 K는 창영이가 어긴 규칙의 번호이다.
// 창영이의 춤이 규칙을 여러개 어겼다면, "form errors K(1), K(2), ..., K(N-1) and K(N): "을 출력하고 입력으로 주어진 춤을 출력한다. K(i)는 창영이가 어긴 규칙의 번호이고, 오름차순이다.
// 창영이가 1번 규칙을 어겼다면, 입력으로 주어진 춤을 출력할 때, 규칙에 어긋난 dip을 대문자로 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    vector<string> ss;
    string sss;
    stringstream stream(s);
    while (stream >> sss)
      ss.push_back(sss);
    vector<int> errors(6, 0);
    int size = ss.size();
    int twirl = 0, hop = 0, dip = 0;
    for (int i = 0; i < size; i++) {
      if (ss[i] == "dip") {
        dip = 1;
        if (!((i - 1 >= 0 && ss[i - 1] == "jiggle") || (i - 2 >= 0 && ss[i - 2] == "jiggle") || (i + 1 < size && ss[i + 1] == "twirl"))) {
          errors[1] = 1;
          ss[i] = "DIP";
        }
      } else if (ss[i] == "twirl") {
        twirl = 1;
      } else if (ss[i] == "hop") {
        hop = 1;
      }
    }
    if (size < 3 || !(ss[size - 1] == "clap" && ss[size - 2] == "stomp" && ss[size - 3] == "clap"))
      errors[2] = 1;
    if (twirl && !hop)
      errors[3] = 1;
    if (ss[0] == "jiggle")
      errors[4] = 1;
    if (!dip)
      errors[5] = 1;
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
      if (errors[i] == 1)
        cnt++;
    cout << "form ";
    if (cnt == 0) {
      cout << "ok: ";
    } else if (cnt == 1) {
      cout << "error ";
      for (int i = 1; i <= 5; i++)
        if (errors[i] == 1)
          cout << i << ": ";
    } else {
      cout << "errors ";
      int tmp = 0;
      for (int i = 1; i <= 5; i++) {
        if (errors[i] == 1) {
          tmp++;
          cout << i;
          if (tmp == 0)
            continue;
          else if (tmp < cnt - 1)
            cout << ", ";
          else if (tmp == cnt - 1)
            cout << " and ";
          else
            cout << ": ";
        }
      }
    }
    for (string i : ss)
      cout << i << ' ';
    cout << '\n';
  }
  return 0;
}