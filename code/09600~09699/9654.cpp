// 9654: 나부 함대 데이터
//
// - 문제
// 나부 행성의 함대 정보를 출력하는 프로그램을 작성하시오.
//
// - 출력
// 나부 행성의 함대의 정보를 아래와 예제 출력과 같은 표로 출력한다.
// 처음 두 열의 너비는 문자 15개, 세 번째 열은 11개, 마지막 열의 너비는 10개이다.

#include <iostream>
using namespace std;

int main() {
  cout << "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE\nN2 Bomber      Heavy Fighter  Limited    21        \nJ-Type 327     Light Combat   Unlimited  1         \nNX Cruiser     Medium Fighter Limited    18        \nN1 Starfighter Medium Fighter Unlimited  25        \nRoyal Cruiser  Light Combat   Limited    4         \n"
       << '\n';
}