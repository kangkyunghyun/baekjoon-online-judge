# [Silver III] 미소녀 컴퓨터 파루빗토 쨩 - 28086 

[문제 링크](https://www.acmicpc.net/problem/28086) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

수학, 구현, 문자열, 사칙연산

### 제출 일자

2026년 3월 24일 23:50:37

### 문제 설명

<p>미소녀 컴퓨터 파루빗토 쨩은 SCSC에서 만든 8비트 컴퓨터의 이름(일 수도 있었던 무언가)이다. 파루빗토 쨩은 파루빗토로 작동하며 파루빗토 덧셈, 파루빗토 뺄셈, 파루빗토 곱셈, 파루빗토 나눗셈을 할 수 있다. 그런데 파루빗토 컴퓨터를 만든 SCSC 동아리원들은 수많은 전선을 연결하다 눈이 침침해진 나머지 잘못 연결한 전선이 있을까 걱정되기 시작했다! 파루빗토 쨩이 잘 작동하는지 검증하기 위한 코드를 작성해보자!</p>

### 입력 

 <p>첫째 줄에 <code><span style="background-color:#dddddd;">A+B</span>, <span style="background-color:#dddddd;">A-B</span>, <span style="background-color:#dddddd;">A*B</span>, <span style="background-color:#dddddd;">A/B</span></code> 중 하나의 형태의 수식이 주어진다. 입력에 공백이 포함되지 않으며, <code><span style="background-color:#dddddd;">+-</span></code>나 <code><span style="background-color:#dddddd;">--</span></code>의 형태의 연산자는 주어지지 않고, $A$와 $B$는 모두 8진수 정수이다. $(-1\,000\,000\,000_{8} \le A,B \le 1\,000\,000\,000_{8})$</p>

<p>제한 범위는 8진수 기준이다. 즉, 10진수 기준으로는 $-8^9 \le A,B \le 8^9$ 이다.</p>

### 출력 

 <p>주어진 수식의 계산 결과를 8진수 정수로 출력한다. 이때 나눗셈은 $\lfloor A/B \rfloor$로 계산한다. 수식을 계산할 수 없는 경우 <code><span style="background-color:#dddddd;">invalid</span></code>를 출력한다.</p>

