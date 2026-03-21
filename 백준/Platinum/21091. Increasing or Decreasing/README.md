# [Platinum III] Increasing or Decreasing - 21091 

[문제 링크](https://www.acmicpc.net/problem/21091) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

정렬, 애드 혹, 해 구성하기

### 제출 일자

2026년 3월 19일 11:25:29

### 문제 설명

<p>You are given two permutations $A$ and $B$ of size $n$. You want to transform $A$ to $B$ in no more than $n$ operations of the following kind:</p>

<ul>
	<li>Choose a subsegment $[l;r]$ of $A$ and sort it in either increasing or decreasing order.</li>
</ul>

<p>Note that you don't have to minimize the number of operations, any sequence of operations of length not more than $n$ is ok.</p>

### 입력 

 <p>The first line contains one integer $n$ ($1 \le n \le 500$) --- the sizes of both permutations.</p>

<p>The second line contains the permutation $A_{1}, A_{2}, \ldots, A_{n}$.</p>

<p>The third line contains the permutation $B_{1}, B_{2}, \ldots, B_{n}$.</p>

### 출력 

 <p>On the first line print one integer $m$ ($0 \le m \le n$) --- the number of operations.</p>

<p>On the next $m$ lines print the descriptions of operation. One description has a form $l_{i}$ $r_{i}$ $t_{i}$  ($1 \le l_{i} \le r_{i} \le n$, $t_{i}$ is '<code>I</code>' or '<code>D</code>') and means sort the subsegment $[l_{i};r_{i}]$ in (I)ncreasing or (D)ecreasing order.</p>

<p>If there are different solutions any one will be accepted. It is guaranteed that there is at least one solution.</p>

