# [Silver IV] 2023 아주머학교 프로그래딩 정시머힌 - 28125 

[문제 링크](https://www.acmicpc.net/problem/28125) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2025년 7월 5일 01:37:05

### 문제 설명

<p>2023 APC를 총괄하고 있는 A.N.S.I 부회장 현빈이는 문제들을 검수하던 중 이상한 점을 발견하였다. 그것은 몇몇 단어들이 비슷하게 생겼지만, 다른 철자로 되어있었던 것이었다. 어리둥절한 현빈이는 누가 이러한 짓을 저질렀는지 고민하던 와중, 어제 선우와 했던 대화가 문득 떠올랐다.</p>

<p style="text-align: center;">[그림 1] 실제 대화 내용이다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 450px; height: 353px;"></p>

<p>가뜩이나 A.N.S.I 부회장으로서 바쁜 현빈이는 철자가 바뀐 단어들을 다시 원래대로 고치기가 매우 귀찮았다. 다행히도 현빈이는 평소 선우가 어떠한 철자를 바꾸는지 알고 있다. 선우는 알파벳 소문자에 대해서만 철자를 바꾸며, 목록은 다음과 같다.</p>

<table align="center" border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 500px;">
	<caption>[표 1] 선우가 바꾸는 철자 목록</caption>
	<thead>
		<tr>
			<th scope="col">원본</th>
			<th scope="col">수정본</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>a</td>
			<td>@</td>
		</tr>
		<tr>
			<td>c</td>
			<td>[</td>
		</tr>
		<tr>
			<td>i</td>
			<td>!</td>
		</tr>
		<tr>
			<td>j</td>
			<td>;</td>
		</tr>
		<tr>
			<td>n</td>
			<td>^</td>
		</tr>
		<tr>
			<td>o</td>
			<td>0</td>
		</tr>
		<tr>
			<td>t</td>
			<td>7</td>
		</tr>
		<tr>
			<td>v</td>
			<td>\'</td>
		</tr>
		<tr>
			<td>w</td>
			<td>\\\'</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;"> </p>

<p>철자가 바뀐 단어들을 보며 어지러웠던 현빈이는 단어에 있는 알파벳의 절반 이상이 바뀌어 있으면 해석을 포기하기로 하였다. 표를 참고하여 현빈이가 주어지는 단어들을 해석할 수 있는지 알아보자.</p>

### 입력 

 <p>첫 번째 줄에는 정수 $N$이 주어진다. $(1 \leq N \leq 100)$ 두 번째 줄에는 $N$줄에 걸쳐 선우가 바꾸어 놓은 단어들이 주어진다. 선우가 바꾼 단어는 본래 알파벳 소문자로만 구성되어 있었으며, 단어의 길이는 $100$ 이하이다.</p>

### 출력 

 <p>현빈이가 주어진 단어를 해석할 수 있다면 선우가 바꾸기 전의 원래 단어를, 해석을 포기했다면 <span style="color:#e74c3c;"><code>I don't understand</code></span>를 $N$줄에 걸쳐 출력한다.</p>

