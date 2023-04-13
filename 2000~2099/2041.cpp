// 2041: 숫자채우기
//
// - 문제
// N×M 크기의 격자에 적절히 수를 채우려 한다. 단, 인접한 수들의 차이로 1부터 (2NM-N-M)까지의 수가 한 번씩 나오도록 채우려 한다. N=2, M=2인 경우를 예로 들면 다음과 같은 방법이 있다.
// 위와 같이 채우면 인접한 수들의 차이로 1, 2, 3, 4가 모두 한 번씩 나오게 된다. N과 M이 주어질 때 위의 조건을 만족하며 수를 채우는 프로그램을 작성하시오.
//
// - 입력
// 첫 줄에 정수 N과 M(1 ≤ N, M ≤ 1,000)이 주어진다.
//
// - 출력
// N개의 줄에 걸쳐 답을 출력한다. 답이 여러 가지가 있다면 그중 한 가지만 출력한다. 1 이상 2×109 이하의 정수만 채울 수 있다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a = 1, b = 2 * n * m - n - m + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        cout << a << ' ';
        a++;
      } else {
        cout << b << ' ';
        b--;
      }
    }
    a += m / 2;
    b -= m / 2;
    if (m % 2 == 0) {
      if (i % 2 == 0)
        b++;
      else
        a--;
    }
    cout << '\n';
  }
  return 0;
}

/* 숏코딩
#include<iostream>
int main(){int n,m;std::cin>>n>>m;int a=1,b=2*n*m-n-m+1,i=0,j;for(;i<n;i++){for(j=0;j<m;j++)std::cout<<((i+j)%2?b--:a++)<<' ';a+=m/2;b-=m/2;if(m%2==0)i%2?a--:b++;std::cout<<'\n';}}
*/