// 29007: SAVE the World (Small)
//
// - 문제
// 본 문제와 Large 문제는 점수 계산식과 제한이 다르다. "제한" 문단을 참조하라.
// 어느 날, 당신을 포함하여 총 $n+1$명의 용사가 이세계로 소환되었다. 당신은 용사들을 통솔할 수 있는 "지시" 능력을 부여받았다. 그러나 용사들이 이세계 곳곳에 흩어져 있기에, 마왕을 토벌하기 전 모든 용사가 한 곳에 집합할 필요가 있다. 따라서, 당신은 용사들이 당신이 있는 곳으로 집합할 수 있도록 그들 모두에게 "지시"를 내려야 한다.
// 이세계는 크기가 무한한 2차원 좌표평면으로 모델링할 수 있다. 당신은 현재 $(0,0)$에 있으며, 다른 모든 용사 또한 각각 서로 다른 정수 좌표 $(x,y)$에 있다.
// $(0,0)$에 있지 않은 모든 용사는 각 시점마다 자신의 좌표 $(x,y)$에 대해 $\max(|x'-x|,|y'-y|)=1$인 $(x',y')$로 이동해야 한다. 즉, 현재 어떤 용사가 $(x,y)$에 있다면, 이 용사는 $(x-1,y)$, $(x-1,y-1)$, $(x,y-1)$, $(x+1,y-1)$, $(x+1,y)$, $(x+1,y+1)$, $(x,y+1)$, $(x-1,y+1)$ 중 한 곳으로 이동해야만 한다.
// 용사들에게 지시를 내리는 방법은 다음과 같다. 각 순간, $(0,0)$에 있지 않은 모든 용사는 인접한 $8$개의 칸 중 하나로 이동해야 한다. 이때, 용사가 키보드의 $S$ 키에 있다고 가정하면 인접한 $8$개의 칸을 직관적으로 생각할 수 있을 것이다. 현재 용사가 $(x,y)$에 있다면, 인접한 칸 $8$개 각각에 대응하는 키보드의 알파벳은 다음과 같다.
// $A$ 	 $(x-1,y)$ 
// $Q$ 	 $(x-1,y+1)$ 
// $W$ 	 $(x,y+1)$ 
// $E$ 	 $(x+1,y+1)$ 
// $D$ 	 $(x+1,y)$ 
// $C$ 	 $(x+1,y-1)$ 
// $X$ 	 $(x,y-1)$ 
// $Z$ 	 $(x-1,y-1)$ 
// 각 순간마다 하나의 알파벳을 정해 문자열로 합치면, 용사에 대한 "지시"가 된다. 예를 들어, $(1,1)$에 있는 용사에게 지시 $QXX$를 내리면 용사는 순서대로 $(0,2)$, $(0,1)$, $(0,0)$의 경로를 지나서 최종적으로 $(0,0)$에 도착할 것이다. 또한 $(-1,-1)$에 있는 용사에게 지시 $E$를 내리면 용사는 한 번에 $(0,0)$에 도착할 것이다. 용사 전체에 대한 지시는 각 용사와 그 용사에게 내리는 지시 간의 일대일 대응으로 정의된다.
// 그러나, 용사에 대한 사실은 아직 비밀에 부쳐져 있으며 용사를 소집시키는 작전 또한 아직 기밀이기에, 용사에게 지시를 내리는 것에는 다음과 같은 제약이 있다.
// 한 용사는 같은 좌표를 $2$번 이상 지날 수 없다. 다시 말해, 어느 순간에 용사가 좌표 $u$에서 좌표 $v$로 이동했다면, 그 용사는 좌표 $u$를 다시 방문할 수 없다.
// 어느 순간에 $2$명 이상의 용사가 $(0,0)$을 제외한 어떤 좌표에 동시에 위치할 수 없다. 다시 말해, 어느 순간에 두 용사 A와 B가 좌표 $v$에 인접한 서로 다른 좌표에 있었다면, 두 용사가 동시에 좌표 $v$로 이동하는 것은 불가능하다. 단, 두 용사가 각각 좌표 $u$와 $v$를 차지하여, 어느 순간에 자리를 바꾸어 각각 $v$와 $u$로 이동하는 것은 가능하다.
// 모든 용사는 동시에 현재 순간의 지시에 해당하는 다음 좌표로 이동해야 한다. 다시 말해, 현재가 순간 $i$라면, $(0,0)$에 있는 용사들을 제외한 모든 용사는 자신의 지시에서 $i$번째 알파벳에 해당하는 좌표로 이동해야 한다.
// 어떤 용사가  $(0,0)$에 도착한 이후부터는 더 이상 그 용사에게 지시를 내리면 안 된다.
// 어느 순간에 $2$명 이상의 용사가 동시에 $(0,0)$으로 이동할 수 없다. 다시 말해, 어떤 순간에 $(0,0)$에 도착하는 용사는 반드시 $1$명이거나 $0$명이어야 한다.
// 예시를 들어 보자. 당신을 제외한 용사들이 현재 $(1,-1)$, $(1,0)$, $(1,1)$에 있다고 가정하자. 이때 다음은 정당한 지시의 예시이다.
// $(1,-1)$ 	 $Q$ 
// $(1,0)$ 	 $QX$ 
// $(1,1)$ 	 $CAA$ 
// 예시 1. 정당한 지시의 예시
// 그러나, 다음은 제약을 만족하지 않는 지시들과, 그 지시들이 제약을 만족하지 않는 이유이다.
// $(1,-1)$ 	 $WA$ 
// $(1,0)$ 	 $A$ 
// $(1,1)$ 	 $XA$
// 예시 2. 두 용사가 순간 $1$에 동시에 $(1,0)$을 차지하고 있다.
// $(1,-1)$ 	 $Q$ 
// $(1,0)$ 	 $WZ$ 
// $(1,1)$ 	 $Z$ 
// 예시 3. 두 용사가 순간 $1$에 동시에 $(0,0)$으로 이동하고 있다.
// $(1,-1)$ 	 $XDQQ$ 
// $(1,0)$ 	 $A$ 
// $(1,1)$ 	 $AX$
// 예시 4. 한 용사가 $(1,-1)$을 $2$번 지나가고 있다.
// 다만, 다음 지시는 정당한 지시이다.
// $(1,-1)$ 	 $WA$ 
// $(1,0)$ 	 $XAW$ 
// $(1,1)$ 	 $Z$ 
// 예시 5. 두 용사가 순간 $1$에 서로 자리를 바꾸었지만, 여전히 이 지시는 정당한 지시이다.
// 과연 당신은 충분히 빠른 시간 안에 모든 용사를 $(0,0)$으로 집합시킬 수 있을까?
//
// - 입력
// 첫 번째 줄에 당신을 제외한 용사의 수 $n$이 주어진다.
// 두 번째 줄부터 $n+1$번째 줄까지 용사의 좌표에 해당하는 값 $x_i$, $y_i$가 각각 공백으로 분리되어 주어진다.
//
// - 출력
// $i$번째 줄에 $i$번째 용사에게 내릴 지시를 문자열로 출력한다.
//
// - 제한
// 주어지는 입력의 제한은 다음과 같다.
// $1 \le n \le 500$ 
// $-15 \le x_i,y_i \le 15$ 
// 각 용사의 위치 $(x_i,y_i)$는 모두 서로 다르다. $(x_i,y_i) \neq (0,0)$ 
// Small 문제의 각 테스트 케이스에 대해, 당신의 지시에 대한 점수는 다음과 같다.
// $$10^6 \times V$$ 
// 이때, 코드가 출력한 지시가 정당한 지시이며 모든 용사가 $(0,0)$으로 집합하는 데 성공하였다면 $V=1$이며, 그렇지 않다면 $V=0$이다.
// Small 문제에는 $50$개의 테스트 케이스가 있으며, 총점수는 각 테스트 케이스에 대한 점수의 합이다.
// Small 문제의 테스트 케이스는 다음의 추가적인 조건을 따른다.
// $40$개의 테스트 케이스는 무작위로 생성되었다. 무작위로 생성하는 방식은 다음과 같다. 이 방법은 ${960 \choose n}$가지 가능한 용사의 위치의 조합을 균등한 확률로 뽑는다.
// 우선 $960$개의 가능한 점을 모두 하나의 배열에 나열한다.
// 다음, $960$개의 점이 포함된 배열의 순서를 무작위로 섞는다.
// 마지막으로 그 중 첫 $n$개를 테스트에 포함되는 점으로 선정한다.
// 나머지 테스트 케이스에 대해서는 입력 자체의 제한 이외에 별도의 제한이 없다.
// 무작위 테스트 케이스를 생성하기 위해 사용된 Generator의 소스 코드와 테스트의 편의를 위한 테스트 케이스 시각화 도구가 하단에 첨부되어 있으며, 테스트를 위해 자유롭게 활용하여도 좋다.
// gen_small.cpp
// visualizer.html
// 출력의 크기가 128MB를 초과하는 경우 채점 결과로 '출력 초과'를 받음에 주의하라.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    string cmd = "";
    while (1) {
      if (!x && !y)
        break;
      if (x > 0 && y > 0) { // 1사분면
        if (y >= x) {
          cmd += 'A';
          x--;
        } else {
          cmd += 'W';
          y++;
        }
      } else if (x < 0 && y > 0) { // 2사분면
        if (y <= -x + 1) {
          cmd += 'X';
          y--;
        } else {
          cmd += 'A';
          x--;
        }
      } else if (x < 0 && y < 0) { // 3사분면
        if (y <= x) {
          cmd += 'D';
          x++;
        } else {
          cmd += 'X';
          y--;
        }
      } else if (x > 0 && y < 0) { // 4사분면
        if (y >= -x) {
          cmd += 'W';
          y++;
        } else {
          cmd += 'D';
          x++;
        }
      } else if (x == 0 && y > 0) { // y축 위
        if (y == 1) {
          cmd += 'X';
          y--;
        } else {
          cmd += 'A';
          x--;
        }
      } else if (x == 0 && y < 0) { // y축 아래
        cmd += 'D';
        x++;
      } else if (y == 0 && x > 0) { // x축 오른쪽
        cmd += 'W';
        y++;
      } else if (y == 0 && x < 0) { // x축 왼쪽
        cmd += 'X';
        y--;
      }
    }
    cout << cmd << '\n';
  }
  return 0;
}
/*
X X A A A A A A A A A A A A A A A A A A A A A A A A A A A A A
X X X A A A A A A A A A A A A A A A A A A A A A A A A A A A W
X X X X A A A A A A A A A A A A A A A A A A A A A A A A A W W
X X X X X A A A A A A A A A A A A A A A A A A A A A A A W W W
X X X X X X A A A A A A A A A A A A A A A A A A A A A W W W W
X X X X X X X A A A A A A A A A A A A A A A A A A A W W W W W
X X X X X X X X A A A A A A A A A A A A A A A A A W W W W W W
X X X X X X X X X A A A A A A A A A A A A A A A W W W W W W W
X X X X X X X X X X A A A A A A A A A A A A A W W W W W W W W
X X X X X X X X X X X A A A A A A A A A A A W W W W W W W W W
X X X X X X X X X X X X A A A A A A A A A W W W W W W W W W W
X X X X X X X X X X X X X A A A A A A A W W W W W W W W W W W
X X X X X X X X X X X X X X A A A A A W W W W W W W W W W W W
X X X X X X X X X X X X X X X A A A W W W W W W W W W W W W W
X X X X X X X X X X X X X X X X A W W W W W W W W W W W W W W
X X X X X X X X X X X X X X X 0 W W W W W W W W W W W W W W W
X X X X X X X X X X X X X X D D W W W W W W W W W W W W W W W
X X X X X X X X X X X X X D D D D W W W W W W W W W W W W W W
X X X X X X X X X X X X D D D D D D W W W W W W W W W W W W W
X X X X X X X X X X X D D D D D D D D W W W W W W W W W W W W
X X X X X X X X X X D D D D D D D D D D W W W W W W W W W W W
X X X X X X X X X D D D D D D D D D D D D W W W W W W W W W W
X X X X X X X X D D D D D D D D D D D D D D W W W W W W W W W
X X X X X X X D D D D D D D D D D D D D D D D W W W W W W W W
X X X X X X D D D D D D D D D D D D D D D D D D W W W W W W W
X X X X X D D D D D D D D D D D D D D D D D D D D W W W W W W
X X X X D D D D D D D D D D D D D D D D D D D D D D W W W W W
X X X D D D D D D D D D D D D D D D D D D D D D D D D W W W W
X X D D D D D D D D D D D D D D D D D D D D D D D D D D W W W
X D D D D D D D D D D D D D D D D D D D D D D D D D D D D W W
D D D D D D D D D D D D D D D D D D D D D D D D D D D D D D W
*/