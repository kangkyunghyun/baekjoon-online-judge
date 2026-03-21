#include <stdio.h>
#pragma warning(disable : 4669)

int Stu[29];
int All_Stu[31];
int Absent[2];
int count = 0;

int main() {
  for (int n = 0; n < 30; n++) {
    All_Stu[n] = n + 1;
  }
  // 비교를 위해 1 ~ 30 까지의 요소를 저장한 배열

  for (int i = 0; i < 28; i++) {
    scanf("%d", &Stu[i]);
  }
  // 실제 입력값에 대한 배열

  for (int j = 0; j < 28; j++) {
    for (int k = 0; k < 30; k++) {
      if (All_Stu[k] == Stu[j]) {
        All_Stu[k] = 0;
        break;
      }
    }
  }
  // All_Stu배열의 1 ~ 30 중 입력값(Stu)에 존재했던 값들은 0으로 만들어줌으로서, 입력값에 없었던 요소들(미제출자들)만 남겨놓는 과정

  for (int m = 0; m < 30; m++) {
    if (All_Stu[m] != 0) {
      Absent[count] = All_Stu[m];
      count++;
    }
  }
  // 입력값에 없었던 요소들(미제출자들)을 Absent라는 배열에 따로 추출하여 저장하는 과정

  printf("%d\n%d\n", Absent[0], Absent[1]);
  // 미제출자들에 대한 출력
  return 0;
}